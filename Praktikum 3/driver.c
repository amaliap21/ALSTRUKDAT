#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "listdin.c"

int main()
{
    ListDin T1, T2;

    CreateListDin(&T1, 100);
    CreateListDin(&T2, 100);
    readList(&T1);
    readList(&T2);
    printList(T1);
    printf("\n");
    printList(T2);
    printf("\n");
    printList(plusMinusList(T1, T2, true));
    printf("\n");
    printf("%d\n", CAPACITY(T1));

    return 0;
}