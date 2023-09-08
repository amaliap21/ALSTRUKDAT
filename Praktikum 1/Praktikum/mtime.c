/* NIM = 13522042*/
/* Nama = Amalia Putri*/
/* Tanggal = 1 September 2023*/
/* Topik praktikum = ADT Sederhana*/
/* Membuatlah sebuah program yang digunakan untuk membaca beberapa pasangan TIME yang merepresentasikan waktu mulai dan waktu selesai pembicaraan telepon di suatu perusahaan penyedia layanan telepon, misalnya <T1, T2>.  */
/* Source: Gare IF'20*/

#include <stdio.h>
#include "time.h"

int main()
{
    int p;
    TIME a, b, c, d;
    scanf("%d", &p);

    int i;
    for (i = 0; i < p; i++)
    {
        printf("[%d]\n", i + 1);
        BacaTIME(&a);
        BacaTIME(&b);
        TIME min, max;

        if (TLT(a, b))
        {
            min = a;
            max = b;
        }
        else if (TGT(a, b))
        {
            min = b;
            max = a;
        }
        else if (TEQ(a, b))
        {
            min = a;
            max = a;
        }

        if (i == 0)
        {
            c = min;
            d = max;
        }
        else
        {
            if (!TLT(c, min))
            {
                c = min;
            }
            if (!TGT(d, max))
            {
                d = max;
            }
        }
        printf("%d\n", Durasi(min, max));
    }

    TulisTIME(c);
    printf("\n");
    TulisTIME(d);
    printf("\n");
    return 0;
}
