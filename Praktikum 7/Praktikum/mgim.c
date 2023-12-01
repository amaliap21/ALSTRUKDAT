#include <stdio.h>
#include "queue.h"

int modulus(int N)
{
    boolean found = false;
    int mod = N - 1;
    while (mod >= 2 && found == false)
    {
        if (N % mod == 0)
        {
            found = true;
        }
        else
        {
            mod--;
        }
    }
    if (found == true)
    {
        return mod;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Queue q;
    CreateQueue(&q);

    int N;
    scanf("%d", &N);

    int i;
    for (i = 0; i < N; i++)
    {
        int Ni;
        scanf("%d", &Ni);

        int r = 0;
        while (Ni > 0)
        {
            int bagi = modulus(Ni);
            if (bagi != 0)
            {
                int bagi2 = Ni / bagi;
                if (bagi >= bagi2)
                {
                    Ni = bagi;
                }
                else
                {
                    Ni = bagi2;
                }
            }
            else
            {
                Ni = Ni - 1;
            }
            r++;
        }
        enqueue(&q, r);
    }

    int mult = 1;
    while (!isEmpty(q))
    {
        int val;
        dequeue(&q, &val);
        mult = mult * val;
    }

    printf("%d\n", mult);

    return 0;
}
