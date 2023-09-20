#include <stdio.h>
#include "matrix.h"
#include "matrix.c"

int main()
{
    Matrix m;
    int capacity;
    scanf("%d", &capacity);

    createMatrix(capacity, capacity, &m);
    readMatrix(&m, capacity, capacity);
    printf("\n");
    displayMatrix(m);
    printf("\n");

    // print transpose matrix
    printf("Transpose matrix:\n");
    pTranspose(&m);
    displayMatrix(m);

    return 0;
}