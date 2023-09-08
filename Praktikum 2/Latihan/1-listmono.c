#include <stdio.h>
#include "liststatik.h"
#include "liststatik.c"

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
        printf("Static Monotic list\n");
    }
    else if (isAsc)
    {
        printf("Non-descending Monotic list\n");
    }
    else if (isDesc)
    {
        printf("Non-ascending Monotic list\n");
    }
    else
    {
        printf("Non-monotic list\n");
    }

    return 0;
}