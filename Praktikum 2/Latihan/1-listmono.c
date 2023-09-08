#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main()
{
    boolean isAsc = true, isDesc = true, isStat = true;
    ListStatik l;
    readList(&l);

    int i = 1;
    while ((isAsc == true | isDesc == true) && i < listLength(l))
    {
        if (ELMT(l, i) < ELMT(l, i - 1))
        {
            isAsc = false;
        }
        if (ELMT(l, i) > ELMT(l, i - 1))
        {
            isDesc = false;
        }
        if (ELMT(l, i) != ELMT(l, i - 1))
        {
            isStat = false;
        }
        i++;
    }

    if (isStat)
    {
        printf("Static Monotonic List\n");
    }
    else if (isAsc)
    {
        printf("Non-descending Monotonic List\n");
    }
    else if (isDesc)
    {
        printf("Non-ascending Monotonic List\n");
    }
    else
    {
        printf("Non-monotonic List\n");
    }

    return 0;
}