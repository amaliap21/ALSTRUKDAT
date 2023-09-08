#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l1, l2, l3;
    CreateListStatik(&l3);

    readList(&l1);
    readList(&l2);

    int idx;
    idx = listLength(l1) + listLength(l2);

    int i, j = 0;
    for (i = 0; i < idx; i++)
    {
        if (i < listLength(l1))
        {
            ELMT(l3, i) = ELMT(l1, i);
        }
        else if (i < idx && j < listLength(l2))
        {
            ELMT(l3, i) = ELMT(l2, j);
            j++;
        }
    }

    sortList(&l3, true);
    printList(l3);
    printf("\n");

    return 0;
}
