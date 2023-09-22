// Tanur Rizaldi Rahardjo 13519214

#include <stdio.h>
#include "matrix.c"

void MaxMinKol(Matrix M, IdxType j, ElType *max, ElType *min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
    IdxType i;
    *max = ELMT(M, 0, j);
    *min = ELMT(M, 0, j);

    for (i = 0; i <= getLastIdxRow(M); i++)
    {
        if (ELMT(M, i, j) > *max)
        {
            *max = ELMT(M, i, j);
        }
        if (ELMT(M, i, j) < *min)
        {
            *min = ELMT(M, i, j);
        }
    }
}

void MaxMinBrs(Matrix M, IdxType i, ElType *max, ElType *min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
    IdxType j;
    *max = ELMT(M, i, 0);
    *min = ELMT(M, i, 0);

    for (j = 0; j <= getLastIdxCol(M); j++)
    {
        if (ELMT(M, i, j) > *max)
        {
            *max = ELMT(M, i, j);
        }
        if (ELMT(M, i, j) < *min)
        {
            *min = ELMT(M, i, j);
        }
    }
}

float RataKol(Matrix M, IdxType j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
    IdxType i;
    float rata2, sum = 0;
    int count = 0;

    for (i = 0; i <= getLastIdxRow(M); i++)
    {
        sum += ELMT(M, i, j);
        count += 1;
    }

    rata2 = sum / count;

    return rata2;
}

float RataBrs(Matrix M, IdxType i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    IdxType j;
    float rata2, sum = 0;
    int count = 0;

    for (j = 0; j <= getLastIdxCol(M); j++)
    {
        sum += ELMT(M, i, j);
        count += 1;
    }

    rata2 = sum / count;

    return rata2;
}

int CountXKol(Matrix M, IdxType j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
    IdxType i;
    int count = 0;

    for (i = 0; i <= getLastIdxRow(M); i++)
    {
        if (ELMT(M, i, j) == X)
        {
            count += 1;
        }
    }

    return count;
}

// procedure TulisNilaiX (input M : Matriks, input j : indeks, input X : ElType)
// { Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. }
// { Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. }
// { Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir }
// { I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi }
// { F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
// Jika tidak ada elemen dengan nilai = X, menuliskan [] */
// { Contoh: Jika M adalah matrix 3x3 dan isinya adalah:
// 1 3 3
// 2 5 6
// 7 3 9
// maka jika j = 1 dan X = 3, akan tercetak: [0,2]
// }
void TulisNilaiX(Matrix M, int j, int X)
{
    IdxType i;
    int xCt = CountXKol(M, j, X);

    printf("[");
    for (i = 0; i < ROW_EFF(M); i++)
        if ((xCt > 0) && (ELMT(M, i, j) == X))
        {
            if (xCt-- == 1)
            {
                printf("%d", i);
            }
            else
            {
                printf("%d,", i);
            }
        }
    printf("]");
}

// procedure TulisStatistikMhs (input M : Matriks, input i : indeks)
// { Menuliskan statistik untuk mahasiswa dengan nomor urut i. }
// { Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. }
// { Pada dasarnya: menuliskan statistik untuk data pada baris ke-i }
// { I.S. M terdefinisi, i adalah indeks baris efektif M }
// { F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
// [i] <rata-rata> <nilai max> <nilai min> }
// { Contoh: Jika M adalah matrix 3x3 dan isinya adalah:
// 100 83 83
// 72 55 60
// 77 93 90
// maka jika i = 1 akan tercetak:
// [1] 62.33 72 55
// }
void TulisStatistikMhs(Matrix M, int i)
{
    int tMax = -9999, tMin = 9999;
    float tRat = RataBrs(M, i);
    MaxMinBrs(M, i, &tMax, &tMin);
    printf("[%d] %.2f %d %d", i, tRat, tMax, tMin);
}

// procedure TulisStatistikMK (input M : Matriks, input j : indeks)
// { Menuliskan statistik untuk mata kuliah dengan nomor urut j. }
// { Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya). }
// { Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j }
// { I.S. M terdefinisi, j adalah indeks kolom efektif M }
// { F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
// [j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
// { Contoh: Jika M adalah matrix 3x3 dan isinya adalah:
// 100 83 83
// 72 55 60
// 77 93 90
// maka jika j = 1 akan tercetak:
// [1] 77.00 [93 1 [2]] [55 1 [1]]
// }
void TulisStatistikMK(Matrix M, int j)
{
    int tMax = -9999, tMin = 9999;
    float tRat = RataKol(M, j);
    MaxMinKol(M, j, &tMax, &tMin);
    printf("[%d] %.2f [%d %d ", j, tRat, tMax, CountXKol(M, j, tMax));
    TulisNilaiX(M, j, tMax);
    printf("] [%d %d ", tMin, CountXKol(M, j, tMin));
    TulisNilaiX(M, j, tMin);
    printf("]");
}

int main()
{
    Matrix S;
    int r = 0, c = 0;
    scanf("%d %d", &r, &c);
    readMatrix(&S, r, c);
    printf("STATISTIK PER MAHASISWA\n");
    for (int i = 0; i < ROW_EFF(S); i++)
    {
        TulisStatistikMhs(S, i);
        printf("\n");
    }

    printf("STATISTIK PER MATA KULIAH\n");
    for (int j = 0; j < COL_EFF(S); j++)
    {
        TulisStatistikMK(S, j);
        printf("\n");
    }

    return 0;
}