#include <stdio.h>
#include "liststatik.h"

int main()
{
    int x, min, max, median;
    ListStatik l;
    readList(&l);
    scanf("%d", &x);

    int i;
    float average, sum = 0;
    for (i = 0; i < listLength(l); i++)
    {
        sum += ELMT(l, i);
    }

    average = sum / listLength(l);

    sortList(&l, true);
    printList(l);
    printf("\n");
    printf("Average: %.02f\n", average);

    int idx;
    boolean isFound = true;
    for (i = 0; i < listLength(l); i++)
    {
        if (x == ELMT(l, i))
        {
            idx = i;
            isFound = false;
            break;
        }
    }

    if (!isFound)
    {
        printf("%d\n", idx);

        extremeValues(l, &max, &min);
        if (x == max)
        {
            printf("X maksimum\n");
        }
        if (x == min)
        {
            printf("X minimum\n");
        }

        // median = ELMT(l, getLastIdx(l) / 2);
        if (listLength(l) % 2 != 0)
        {
            median = ELMT(l, listLength(l) / 2);
        }
        else
        {
            median = ELMT(l, listLength(l) / 2 - 1);
        }

        if (x == median)
        {
            printf("X median\n");
        }
    }

    else
    {
        printf("%d tidak ada\n", x);
    }
    return 0;
}