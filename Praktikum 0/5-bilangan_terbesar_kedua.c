#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    if (n < 2)
    {
        return 1;
    }

    int terbesar1 = 0;
    int terbesar2 = 0;
    int num;

    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);

        if (num > terbesar1)
        {
            terbesar2 = terbesar1;
            terbesar1 = num;
        }
        else if (num > terbesar2 && num != terbesar1)
        {
            terbesar2 = num;
        }
    }

    printf("%d\n", terbesar2);

    return 0;
}
