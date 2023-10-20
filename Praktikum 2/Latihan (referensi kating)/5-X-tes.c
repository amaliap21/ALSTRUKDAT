#include <stdio.h>
#include "liststatik.h"
#include "liststatik.c"

int main()
{
    // Baca list
    ListStatik l;
    readList(&l);

    // 1. Get Xocc
    int x, xocc = 0;
    scanf("%d", &x);

    int i;
    for (i = 0; i < listLength(l); i++)
    {
        if (x == ELMT(l, i))
        {
            xocc++;
        }
    }

    // 2. Print list
    printList(l);
    printf("\n");

    printf("%d\n", xocc);

    // 3. Get Elm last idx
    int idx;

    if (indexOf(l, x) != IDX_UNDEF)
    {
        for (i = 0; i < listLength(l); i++)
        {
            if (x == ELMT(l, i))
            {
                idx = i;
            }
        }
        printf("%d\n", idx);
    }
    else
    {
        printf("%d tidak ada\n", x);
    }

    // 4. Extreme Val
    int min, max;
    extremeValues(l, &max, &min);

    if (x == max)
    {
        printf("maksimum\n");
    }

    if (x == min)
    {
        printf("minimum\n");
    }

    // 5. Median Val
    sortList(&l, true);
    int med = ELMT(l, getLastIdx(l) / 2);

    if (x == med)
    {
        printf("median\n");
    }

    return 0;
}
