#include <stdio.h>
#include "listdin.c"

int main()
{
    ListDin l;
    CreateListDin(&l, 100);
    ListDin l2;
    CreateListDin(&l2, 100);

    printf("L1\n");
    readList(&l);
    printList(l);
    printf("\n\n");

    printf("L2\n");
    readList(&l2);
    printList(l2);
    printf("\n\n");

    // plus minus list
    printf("plus minus list\n");
    printList(plusMinusList(l, l2, true));
    printf("\n\n");

    // minus plus list
    printf("minus plus list\n");
    printList(plusMinusList(l, l2, false));
    printf("\n\n");

    // indexOf
    printList(l);
    printf("\n");
    int x = 3;
    int idx = indexOf(l, x);
    printf("Index of %d is %d\n\n", x, idx);

    // extremeValues
    int max, min;
    extremeValues(l, &max, &min);
    printf("Max: %d, Min: %d\n\n", max, min);

    // sort
    printf("Asc\n");
    sort(&l, true);
    printList(l);
    printf("\nDesc\n");
    sort(&l, false);
    printList(l);
    printf("\n\n");

    // insertLast
    printf("Insert Last\n");
    insertLast(&l, 999);
    printList(l);
    printf("\n\n");

    // deleteLast
    printf("Delete Last\n");
    ElType e = 999;
    deleteLast(&l, &e);
    printList(l);
    printf("\n\n");

    // expandList
    printf("Expand List\n");
    expandList(&l, 5);
    printList(l);
    printf("\n\n");

    // shrinkList
    printf("Shrink List\n");
    shrinkList(&l, 5);
    printList(l);
    printf("\n\n");

    return 0;
}