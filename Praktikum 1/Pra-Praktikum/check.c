#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.c"

int main()
{
    POINT P1, P2;
    BacaPOINT(&P1);
    // BacaPOINT(&P2);
    Putar(&P1, 270);

    TulisPOINT(P1);

    // PersamaanLinearDuaVariabel(P1, P2);
    // PersamaanLinearDuaVariabel(P1, P2);
    // EQ(POINT P1, POINT P2)

    // SAMPE DI KUADRAN!!! - 29/08/2023 | 23:10

    return 0;
}