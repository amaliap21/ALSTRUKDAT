/* Nama     : Amalia Putri */
/* NIM      : 13522042 */
/* Kampus   : Ganesha */
/* File     : listdin.c */
/* Tanggal  : 14 September 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
{
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

    BUFFER(*l) = (int *)malloc(capacity * sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l)
{
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
{
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    /* *** Daya tampung container *** */

    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */

    return IDX_MIN;
}

IdxType getLastIdx(ListDin l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */

    return (NEFF(l) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/

    return ((i >= getFirstIdx(l)) && (i <= CAPACITY(l)));
}
boolean isIdxEff(ListDin l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..NEFF(l) */

    return ((i >= getFirstIdx(l)) && (i <= getLastIdx(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
{
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* *** Test list penuh *** */

    return (NEFF(l) == 0);
}

boolean isFull(ListDin l)
{
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

    return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
{
    /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
    /* F.S. List l terdefinisi */
    /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
          0 satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk l kosong */

    /* KAMUS */
    IdxType i;
    int N;

    /* ALGORITMA */
    do
    {
        scanf("%d", &N);
    } while (N < 0 || N > CAPACITY(*l));

    NEFF(*l) = N;

    if (N != 0)
    {
        for (i = IDX_MIN; i < N; i++)
        {
            scanf("%d", &ELMT(*l, i));
        }
    }
}

void printList(ListDin l)
{
    /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
       antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
       di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */

    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        for (i = getFirstIdx(l); i <= getLastIdx(l); i++)
        {
            printf("%d", ELMT(l, i));
            if (i != getLastIdx(l))
            {
                printf(",");
            }
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    /* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

    /* KAMUS */
    ListDin l3;
    IdxType i;

    /* ALGORITMA */
    CreateListDin(&l3, CAPACITY(l1));
    NEFF(l3) = NEFF(l1);

    for (i = getFirstIdx(l1); i <= getLastIdx(l1); i++)
    {
        if (plus)
        {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
        else
        {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
{
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    if (listLength(l1) == listLength(l2))
    {
        for (i = getFirstIdx(l1); i <= getLastIdx(l1); i++)
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                return false;
            }
        }
        return true;
    }

    return false;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
{
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
    /* Jika tidak ada, mengirimkan IDX_UNDEF */
    /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
    /* Skema Searching yang digunakan bebas */

    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    if (!isEmpty(l))
    {
        for (i = IDX_MIN; i <= getLastIdx(l); i++)
        {
            if (ELMT(l, i) == val)
            {
                return i;
            }
        }

        return IDX_UNDEF;
    }

    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min)
{
    /* I.S. List l tidak kosong */
    /* F.S. max berisi nilai maksimum l;
            min berisi nilai minimum l */

    /* KAMUS */
    IdxType i;
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);

    /* ALGORITMA */
    for (i = getFirstIdx(l); i <= getLastIdx(l); i++)
    {
        if (ELMT(l, i) > *max)
        {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min)
        {
            *min = ELMT(l, i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
{
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */

    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);

    for (i = IDX_MIN; i <= getLastIdx(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l)
{
    /* Menghasilkan hasil penjumlahan semua elemen l */
    /* Jika l kosong menghasilkan 0 */

    /* KAMUS */
    IdxType i;
    int sum = 0;

    /* ALGORITMA */
    if (!isEmpty(l))
    {
        for (i = getFirstIdx(l); i <= getLastIdx(l); i++)
        {
            sum += ELMT(l, i);
        }
    }

    return sum;
}

int countVal(ListDin l, ElType val)
{
    /* Menghasilkan berapa banyak kemunculan val di l */
    /* Jika l kosong menghasilkan 0 */

    /* KAMUS */
    IdxType i;
    int count = 0;

    /* ALGORITMA */
    if (!isEmpty(l))
    {
        for (i = getFirstIdx(l); i <= getLastIdx(l); i++)
        {
            if (ELMT(l, i) == val)
            {
                count += 1;
            }
        }
    }

    return count;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
{
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
       algoritma bebas */

    /* KAMUS */
    IdxType i, j;
    ElType temp;

    /* ALGORITMA */
    if (NEFF(*l) > 1)
    {
        for (i = IDX_MIN; i <= getLastIdx(*l); i++)
        {
            for (j = IDX_MIN; j <= getLastIdx(*l); j++)
            {
                if (asc)
                {
                    if (ELMT(*l, i) < ELMT(*l, j))
                    {
                        temp = ELMT(*l, i);
                        ELMT(*l, i) = ELMT(*l, j);
                        ELMT(*l, j) = temp;
                    }
                }
                else
                {
                    if (ELMT(*l, i) > ELMT(*l, j))
                    {
                        temp = ELMT(*l, i);
                        ELMT(*l, i) = ELMT(*l, j);
                        ELMT(*l, j) = temp;
                    }
                }
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
{
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */

    if (!isFull(*l))
    {
        ELMT(*l, getLastIdx(*l) + 1) = val;
        NEFF(*l) += 1;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
{
    /* Proses : Menghapus elemen terakhir list */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen list berkurang satu */
    /*      List l mungkin menjadi kosong */

    /* ALGORITMA */
    if (!isEmpty(*l))
    {
        *val = ELMT(*l, getLastIdx(*l));
        NEFF(*l) -= 1;
    }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
{
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */

    CAPACITY(*l) += num;
}

void shrinkList(ListDin *l, int num)
{
    /* Proses : Mengurangi capacity sebanyak num */
    /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
    /* F.S. Ukuran list berkurang sebanyak num. */

    CAPACITY(*l) -= num;
}

void compressList(ListDin *l)
{
    /* Proses : Mengubah capacity sehingga capacity = nEff */
    /* I.S. List tidak kosong */
    /* F.S. Ukuran capacity = nEff */

    if (!isEmpty(*l))
    {
        CAPACITY(*l) = NEFF(*l);
    }
}