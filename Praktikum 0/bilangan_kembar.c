#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    int i, sum = 0;
    for (i = a; i <= b; i++)
    {
        if (i % 11 == 0 || i % 111 == 0 || i % 1111 == 0 || i % 11111 == 0 || i % 111111 == 0)
        {
            sum += 1;
        }
    }

    printf("%d\n", sum);
    return 0;
}