#include <stdio.h>
#include "stacklinked.h"

int main()
{
    int t;
    scanf("%d", &t);
    for (t; t > 0; t--)
    {
        Stack come, small, parkir;
        CreateStack(&come);
        CreateStack(&small);
        CreateStack(&parkir);

        int n;
        scanf("%d", &n);
        int i;
        int arr[n];

        for (i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            arr[n - i - 1] = temp;
        }

        for (i = 0; i < n; i++)
        {
            push(&come, arr[i]);
        }

        boolean isCapable = true;

        int current = 1;
        int dump;
        while ((length(come) > 0 || length(small) > 0) && isCapable)
        {
            if (!isEmpty(come))
            {
                if (TOP(come) == current)
                {
                    push(&parkir, TOP(come));
                    pop(&come, &dump);
                    current++;
                    continue;
                }
            }

            if (!isEmpty(small))
            {
                if (TOP(small) == current)
                {
                    push(&parkir, current);
                    pop(&small, &dump);
                    current++;
                    continue;
                }
            }

            if (!isEmpty(come))
            {
                pop(&come, &dump);
                push(&small, dump);
                continue;
            }
            isCapable = false;
        }

        if (isCapable)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}