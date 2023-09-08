#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l1, l2;
    readList(&l1);
    readList(&l2);

    int i;
    insertFirst(&l2, 0);

    for (i = 1; i < listLength(l2); i++)
    {
        ELMT(l2, i) += ELMT(l2, i - 1);
    }

    IdxType idx = 0, idx1 = 0, idx2 = 0;
    ElType c1 = 0, c2 = 0, c3 = 0;

    for (i = 0; i < listLength(l2); i++)
    {
        if (ELMT(l1, i) == 0)
        {
            continue;
        }
        else if (ELMT(l1, i) == 1)
        {
            c1 += 1;
            idx = i;
        }
        else if (ELMT(l1, i) == 2)
        {
            c2 += 1;
            idx1 = i;
        }
        else if (ELMT(l1, i) == 3)
        {
            c3 += 1;
            idx2 = i;
        }
    }

    int total = c1 + c2 + c3 + (ELMT(l2, idx) + ELMT(l2, idx1) + ELMT(l2, idx2)) * 2;

    printf("%d\n", total);
    return 0;
}
