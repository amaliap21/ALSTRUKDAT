#include <stdio.h>
#include "matrix.h"

int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    Matrix m;
    createMatrix(N, M, &m);
    readMatrix(&m, N, M);

    int max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                for (int l = k; l < M; l++)
                {
                    int sum = 0;
                    for (int x = i; x <= j; x++)
                    {
                        for (int y = k; y <= l; y++)
                        {
                            sum += ELMT(m, x, y);
                        }
                    }
                    if (sum > max && (j - i + 1) * (l - k + 1) == K)
                    {
                        max = sum;
                    }
                }
            }
        }
    }

    printf("%d\n", max);
    return 0;
}
