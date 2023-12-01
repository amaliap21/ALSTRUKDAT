#include <stdio.h>
#include "queuelinked.h"

/* Prototype manajemen memori */
Address newNode(ElType x)
{
    /* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
       atau NIL jika alokasi gagal */
    Address P = (Address)malloc(sizeof(Node));

    if (P != NULL)
    {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}

boolean isEmpty(Queue q)
{
    /* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
    return (ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}

int length(Queue q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
    int len = 0;
    Address P = ADDR_HEAD(q);

    while (P != NULL)
    {
        len++;
        P = NEXT(P);
    }

    return len;
}

/*** Kreator ***/
void CreateQueue(Queue *q)
{
    /* I.S. sembarang */
    /* F.S. Sebuah q kosong terbentuk */
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayQueue(Queue q)
{
    /* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen
        dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah,
        atau di belakang, termasuk spasi dan enter */
    /* I.S. q boleh kosong */
    /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika Queue kosong : menulis [] */
    Address p = ADDR_HEAD(q);

    printf("[");
    while (p != NULL)
    {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL)
        {
            printf(",");
        }
    }
    printf("]");
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x)
{
    /* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
               jika alokasi berhasil; jika alokasi gagal q tetap */
    /* Pada dasarnya adalah proses insertLast */
    /* I.S. q mungkin kosong */
    /* F.S. x menjadi Tail, Tail "maju" */
    Address p = newNode(x);

    if (p != NULL)
    {
        if (isEmpty(*q))
        {
            ADDR_HEAD(*q) = p;
            ADDR_TAIL(*q) = p;
        }
        else
        {
            NEXT(ADDR_TAIL(*q)) = p;
            ADDR_TAIL(*q) = p;
        }
    }
}

void dequeue(Queue *q, ElType *x)
{
    /* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
    /* Pada dasarnya operasi deleteFirst */
    /* I.S. q tidak mungkin kosong */
    /* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
    Address p = ADDR_HEAD(*q);
    *x = INFO(p);

    if (length(*q) == 1)
    {
        ADDR_HEAD(*q) = NULL;
        ADDR_TAIL(*q) = NULL;
    }
    else
    {
        ADDR_HEAD(*q) = NEXT(p);
    }
    free(p);
}