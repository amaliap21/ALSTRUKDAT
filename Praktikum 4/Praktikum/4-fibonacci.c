#include <stdio.h>
#include "matrix.h"

Matrix powerMatrix(Matrix m, long long pangkat)
{
    if (pangkat == 0)
    {
        Matrix identityMatrix;
        createMatrix(2, 2, &identityMatrix);
        ELMT(identityMatrix, 0, 0) = 1;
        ELMT(identityMatrix, 0, 1) = 0;
        ELMT(identityMatrix, 1, 0) = 0;
        ELMT(identityMatrix, 1, 1) = 1;
        return identityMatrix;
    }
    else if (pangkat == 1)
    {
        return m;
    }
    else
    {
        Matrix m2 = powerMatrix(m, pangkat / 2);
        Matrix mulMatrix = multiplyMatrixWithMod(m2, m2, 2003);
        if (pangkat % 2 == 1)
        {
            mulMatrix = multiplyMatrixWithMod(mulMatrix, m, 2003);
        }
        return mulMatrix;
    }
}

int main()
{
    long long k;
    scanf("%lld", &k);

    if (k == 1 || k == 2)
    {
        printf("%d\n", 1);
    }
    else
    {
        Matrix matrixFibonacci;
        createMatrix(2, 2, &matrixFibonacci);
        ELMT(matrixFibonacci, 0, 0) = 1;
        ELMT(matrixFibonacci, 0, 1) = 1;
        ELMT(matrixFibonacci, 1, 0) = 1;
        ELMT(matrixFibonacci, 1, 1) = 0;

        Matrix resultMatrix = powerMatrix(matrixFibonacci, k - 1);
        int fibonacci = ELMT(resultMatrix, 0, 0);

        printf("%d\n", fibonacci % 2003);
    }
    return 0;
}