#include <stdio.h>
#include "queue.h"
#include "math.h"

int max(int a, int b)
{
    int res;
    (a > b) ? (res = a) : (res = b);
    return res;
}

int minSteps(int N)
{
    Queue qNums;
    CreateQueue(&qNums);
    enqueue(&qNums, N);

    Queue qSteps;
    CreateQueue(&qSteps);
    enqueue(&qSteps, 0);

    boolean isFound = false;

    int valNum, valStep, divNum;
    while (!isFound)
    {
        dequeue(&qNums, &valNum);
        dequeue(&qSteps, &valStep);

        if (valNum == 0)
        {
            isFound = true;
        }
        else
        {
            enqueue(&qNums, valNum - 1);
            enqueue(&qSteps, valStep + 1);

            int sqNum = sqrt(valNum);

            int i;
            for (i = 2; i <= sqNum; i++)
            {
                if (valNum % i == 0)
                {
                    divNum = valNum / i;
                    if (!isFull(qNums))
                    {
                        enqueue(&qNums, max(i, divNum));
                        enqueue(&qSteps, valStep + 1);
                    }
                }
            }
        }
    }

    return valStep;
}

int main()
{
    int n, num, res = 1;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &num);
        res *= minSteps(num);
    }
    printf("%d\n", res);
}