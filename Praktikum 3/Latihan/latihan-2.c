#include <stdio.h>
#include <stdlib.h>
#include <listdin.h>
#include <listdin.c>

int main()
{
    ListDin l;
    IdxType i;
    int capacity, query, op, num;

    scanf("%d", capacity);
    CreateListDin(&l, capacity);
    readList(&l);

    scanf("%d", &query);

    for (i = 0; i < query; i++)
    {
        scanf("%d", &op);

        if (op == 1)
        {
            scanf("%d", &num);

            if (!isFull(l))
            {
                insertLast(&l, num);

                printf("%d ", CAPACITY(l));
                printList(l);
                printf("\n");
            }
            else
            {
                printf("list sudah penuh\n");
            }
        }
        else if (op == 2)
        {
            scanf("%d", &num);

            expandList(&l, num);

            printf("%d ", CAPACITY(l));
            printList(l);
            printf("\n");
        }
        else if (op == 3)
        {
            scanf("%d", &num);

            if (CAPACITY(l) >= num)
            {
                shrinkList(&l, num);
                NEFF(l) = CAPACITY(l);

                printf("%d ", CAPACITY(l));
                printList(l);
                printf("\n");
            }
            else
            {
                printf("list terlalu kecil\n");
            }
        }
        else if (op == 4)
        {
            compressList(&l);

            printf("%d ", CAPACITY(l));
            printList(l);
            printf("\n");
        }
    }

    dealocateList(&l);
    return 0;
}