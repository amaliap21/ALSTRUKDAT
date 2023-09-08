#include <stdio.h>
#include "liststatik.h"
#include "liststatik.c"

int main()
{
    int x, min, max, median, idx;
    ListStatik l;
    readList(&l);

    printList(l);
    printf("\n");

    scanf("%d", &x);
    idx = indexOf(l, x);

    sortList(&l, true);
    extremeValues(l, &max, &min);

    if (listLength(l) % 2 != 0)
    {
        median = ELMT(l, listLength(l) / 2);
    }
    else
    {
        median = ELMT(l, listLength(l) / 2 - 1);
    }

    if (idx == -1)
    {
        printf("%d tidak ada\n", x);
    }
    else
    {
        printf("%d\n", idx);
        if (x == max)
        {
            printf("maksimum\n");
        }
        if (x == min)
        {
            printf("minimum\n");
        }
        if (x == median)
        {
            printf("median\n");
        }
    }

    return 0;
}