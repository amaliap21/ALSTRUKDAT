#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "listdin.c"

int main()
{
    IdxType i;
    ListDin l1, l2, l3;
    CreateListDin(&l1, 200);
    CreateListDin(&l2, 200);
    CreateListDin(&l3, 400);

    readList(&l1);
    readList(&l2);

    sort(&l1, true);
    sort(&l2, true);

    for (i = getFirstIdx(l1); i <= getLastIdx(l1); i++)
    {
        if (indexOf(l3, ELMT(l1, i)) == IDX_UNDEF)
        {
            insertLast(&l3, ELMT(l1, i));
        }
    }

    for (i = getFirstIdx(l2); i <= getLastIdx(l2); i++)
    {
        if (indexOf(l3, ELMT(l2, i)) == IDX_UNDEF)
        {
            insertLast(&l3, ELMT(l2, i));
        }
    }

    sort(&l3, true);
    printf("%d\n", listLength(l3));
    printList(l3);
    printf("\n");

    return 0;
}