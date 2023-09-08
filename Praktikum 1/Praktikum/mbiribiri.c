/*
Saya gembala biri-biri. Semua dijaga rapi-rapi
Sudah dibawa makan mari. Boleh berehat senang hati
Tuan Mike memiliki total n ekor biri-biri yang terletak pada point (xi, yi) dengan i < n. Biri-biri memiliki musuh alami serigala. Serigala ini dimiliki oleh Tuan Man yang kejam dan keji. Serigala hanya dapat bergerak sepanjang jalur serigala, yaitu persamaan garis yang melalui titik (x1, y1) dan (x2, y2).
Misalkan d didefinisikan sebagai jarak terdekat antara biri-biri dengan jalur serigala. Biri-biri dapat dimangsa oleh serigala jika d <= b. Bantu Tuan Mike menghitung jumlah biri-biri yang perlu ia selamatkan!
Masukan pertama adalah b, diikuti dengan dua point untuk membentuk persamaan garis. Masukan berikutnya adalah n dan diikuti dengan n buah point.
Gunakan ADT Point dan ADT Garis yang sudah kalian buat sebelumnya (tidak perlu dikumpulkan).
*/

/*
Masukan	Keluaran	Penjelasan
5                   b = 5
1 2                 (1,2) dan (3,4) adalah PAwal dan PAkhir
3 4
2                   n = 2
1 1                 (1,1) dan (2,2) adalah point dimana biri-biri berada
2 2	       2
*/

#include <stdio.h>
#include "point.h"
#include "garis.h"

int main()
{
    int b, n, count;
    float d;
    POINT P;
    GARIS L1, L2;

    scanf("%d\n", &b);
    BacaGARIS(&L1);

    scanf("%d\n", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        BacaPOINT(&P);
        d = JarakGARIS(L1, P);

        if (d <= b)
        {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}