#include <stdio.h>
#include "liststatik.h"
#include "liststatik.c"

int main()
{
    ListStatik l1, l2, l3;
    CreateListStatik(&l3);
    readList(&l1);
    readList(&l2);

    if (isEmpty(l1) || isEmpty(l2))
    {
        printf("%d\n[]\n", 0);
    }

    else
    {
        sortList(&l1, true);
        sortList(&l2, true);
        int i, j, nim, temp;
        int count = 0;

        for (i = 0; i < listLength(l1); i++)
        {
            for (j = 0; j < listLength(l2); j++)
            {
                if (ELMT(l1, i) == ELMT(l2, j))
                {
                    nim = ELMT(l1, i);
                    insertLast(&l3, nim);
                    count++;
                }
            }
        }

        printf("%d\n", count);
        printList(l3);
        printf("\n");
    }

    return 0;
}