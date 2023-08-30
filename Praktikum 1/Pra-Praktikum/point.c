/* Nama     : Amalia Putri */
/* NIM      : 13522042 */
/* Kampus   : Ganesha */
/* File     : point.c */
/* Tanggal  : 30 Agustus 2023 */

#include <stdio.h>
#include <math.h>
#include "point.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**** Konstruktor membentuk POINT ****/
void CreatePoint(POINT *P, float X, float Y)
{
    /* Membentuk sebuah POINT dari komponen-komponennya */

    /* ALGORITMA */
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT(POINT *P)
{ /* Membaca nilai absis dan ordinat dari keyboard dan membentuk
     POINT P berdasarkan dari nilai absis dan ordinat tersebut */

    /* KAMUS */
    float X, Y;

    /* ALGORITMA */
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P)
{ /* Nilai P ditulis ke layar dengan format "(X,Y)"
    tanpa spasi, enter, atau karakter lain di depan, belakang,
    atau di antaranya
    Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
 */

    /* ALGORITMA */
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/**** Kelompok operasi relasional terhadap POINT ****/
boolean EQ(POINT P1, POINT P2)
{ /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEQ(POINT P1, POINT P2)
{
    /* Mengirimkan true jika P1 tidak sama dengan P2 */
    return (!EQ(P1, P2));
}

boolean IsOrigin(POINT P)
{ /* Menghasilkan true jika P adalah titik origin */
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX(POINT P)
{ /* Menghasilkan true jika P terletak Pada sumbu X */
    return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P)
{ /* Menghasilkan true jika P terletak pada sumbu Y */
    return (Absis(P) == 0);
}

int Kuadran(POINT P)
{ /* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */

    /* ALGORITMA */
    /* Prekondisi : P bukan titik origin dan P tidak terletak di salah satu sumbu */
    if (Absis(P) > 0 && Ordinat(P) > 0)
    {
        return 1;
    }
    else if (Absis(P) < 0 && Ordinat(P) > 0)
    {
        return 2;
    }
    else if (Absis(P) < 0 && Ordinat(P) < 0)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

/**** KELOMPOK OPERASI LAIN TERHADAP TYPE ****/
POINT NextX(POINT P)
{ /* Mengirim salinan P dengan absis ditambah satu */

    /* ALGORITMA */
    Absis(P) += 1;
    return P;
}

POINT NextY(POINT P)
{ /* Mengirim salinan P dengan ordinat ditambah satu */

    /* ALGORITMA */
    Ordinat(P) += 1;
    return P;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY)
{ /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan
     ordinatnya adalah Ordinat(P) + deltaY */

    /* ALGORITMA */
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}
POINT MirrorOf(POINT P, boolean SbX)
{ /* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu
     Jika SbX bernilai true, maka dicerminkan terhadap sumbu X
     Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */

    /* ALGORITMA */
    if (SbX)
    {
        Ordinat(P) *= -1;
    }
    else
    {
        Absis(P) *= -1;
    }
    return P;
}

float Jarak0(POINT P)
{ /* Menghitung jarak P ke (0,0) */

    /* ALGORITMA */
    return (sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2)));
}

float Panjang(POINT P1, POINT P2)
{ /* Menghitung panjang garis yang dibentuk P1 dan P2 */
    /* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
    /* Tuliskan spec fungsi yang lebih tepat. */

    /* ALGORITMA */
    return (sqrt(pow(Absis(P1) - Absis(P2), 2) + pow(Ordinat(P1) - Ordinat(P2), 2)));
}

void Geser(POINT *P, float deltaX, float deltaY)
{ /* I.S. P terdefinisi */
    /* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

    /* ALGORITMA */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P)
{ /* I.S. P terdefinisi */
    /* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
    /* Proses : P digeser ke sumbu X. */
    /* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */

    /* ALGORITMA */
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P)
{ /* I.S. P terdefinisi*/
    /* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
    /* Proses : P digeser ke sumbu Y. */
    /* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */

    /* ALGORITMA */
    Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX)
{ /* I.S. P terdefinisi */
    /* F.S. P dicerminkan tergantung nilai SbX atau SbY */
    /* Jika SbX true maka dicerminkan terhadap sumbu X */
    /* Jika SbX false maka dicerminkan terhadap sumbu Y */

    /* ALGORITMA */
    if (SbX)
    {
        Ordinat(*P) *= -1;
    }
    else
    {
        Absis(*P) *= -1;
    }
}

void Putar(POINT *P, float Sudut)
{ /* I.S. P terdefinisi */
    /* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */

    /* KAMUS */
    float initialAbsis, initialOrdinat;

    /* ALGORITMA */
    initialAbsis = Absis(*P);
    initialOrdinat = Ordinat(*P);
    Sudut = (360 - Sudut) * M_PI / 180;
    Absis(*P) = initialAbsis * cos(Sudut) - initialOrdinat * sin(Sudut);
    Ordinat(*P) = initialAbsis * sin(Sudut) + initialOrdinat * cos(Sudut);
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2)
{ /* I.S. P1 dan P2 terdefinisi */
    /* Prekondisi: dijamin a dan b merupakan bilangan bertipe integer */
    /* F.S. Dibentuk sebuah persamaan garis y = ax + b yang memenuhi untuk P1 dan P2 */
    /* Keluarkan nilai a dan b */
    /* Output a dan b tercetak di layar sebagai bilangan bertipe integer dengan format "(a,b)" */

    /* ALGORITMA */
    int a, b;
    a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    b = Ordinat(P1) - a * Absis(P1);
    printf("(%d,%d)", a, b);
}