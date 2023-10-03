#include <stdio.h>
#include "point.h"
// #include "point.c"

int main()
{
    POINT P1, P2, P3;
    int a, c;
    int x1, x2, x3, y1, y2, y3;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    CreatePoint(&P1, x1, y1);
    CreatePoint(&P2, x2, y2);
    CreatePoint(&P3, x3, y3);

    c = ((x2 - x3) * (y1 - y2) - (x1 - x2) * (y2 - y3)) / ((x1 - x2) * (x2 - x3) * ((x1 + x2) - (x2 + x3)));
    a = (y1 + y2 + 2 * c * x1 * x2 - (x1 + x2) * ((y2 - y1) / (x2 - x1))) / 2;

    printf("%d\n", a);
    return 0;
}