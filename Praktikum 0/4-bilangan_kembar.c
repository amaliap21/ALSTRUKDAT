#include <stdio.h>

int main()
{
    int count, rAwl, rAkh, a, b, digit, lastDigit, benar;

    scanf("%d", &rAwl);
    scanf("%d", &rAkh);

    count = 0;
    a = rAwl;

    while (a <= rAkh)
    {
        benar = 1;
        lastDigit = a % 10;
        b = a;

        while (benar == 1 && b != 0)
        {
            digit = b % 10;
            if (lastDigit != digit)
            {
                benar = 0;
            }
            b /= 10;
        }

        if (benar == 1)
        {
            count++;
        }

        a++;
    }

    printf("%d\n", count);
    return 0;
}