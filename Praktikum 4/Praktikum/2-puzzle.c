#include <stdio.h>
#include "matrix.h"

int main()
{
    Matrix puzzle;
    int N, M, K, A, B;
    scanf("%d %d", &N, &M);
    createMatrix(N, M, &puzzle);
    readMatrix(&puzzle, N, M);
    scanf("%d", &K);

    Matrix potongan[K];
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &A, &B);
        createMatrix(A, B, &potongan[i]);
        readMatrix(&potongan[i], A, B);
    }

    int count = 0;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j <= N - ROW_EFF(potongan[i]); j++)
        {
            for (int k = 0; k <= M - COL_EFF(potongan[i]); k++)
            {
                boolean found = true;
                for (int l = 0; l < ROW_EFF(potongan[i]); l++)
                {
                    for (int m = 0; m < COL_EFF(potongan[i]); m++)
                    {
                        if (ELMT(potongan[i], l, m) != ELMT(puzzle, j + l, k + m))
                        {
                            found = false;
                            break;
                        }
                    }
                    if (!found)
                    {
                        break;
                    }
                }
                if (found)
                {
                    count++;
                    break;
                }
            }
            if (count > 0)
            {
                break;
            }
        }
        if (count == 0)
        {
            break;
        }
    }

    if (count == K)
    {
        printf("Puzzle dapat diselesaikan.\n");
    }
    else
    {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }
    return 0;
}