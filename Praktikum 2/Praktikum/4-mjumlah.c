#include <stdio.h>
#include <math.h>
#include "liststatik.h"

int main()
{
    ListStatik l1, l2, l3;
    readList(&l1);
    readList(&l2);
    CreateListStatik(&l3);

    int i, num1, digit1 = listLength(l1) - 1;
    for (i = 0; i < listLength(l1); i++)
    {
        if (i == 0)
        {
            num1 = ELMT(l1, i) * pow(10, digit1);
        }
        else
        {
            num1 += ELMT(l1, i) * pow(10, digit1);
        }
        digit1--;
    }

    int num2, digit2 = listLength(l2) - 1;
    for (i = 0; i < listLength(l2); i++)
    {
        if (i == 0)
        {
            num2 = ELMT(l2, i) * pow(10, digit2);
        }
        else
        {
            num2 += ELMT(l2, i) * pow(10, digit2);
        }
        digit2--;
    }

    int sum = num1 + num2, sumDigit = sum;

    int idx3 = -1;
    while (sumDigit != 0)
    {
        idx3++;
        sumDigit /= 10;
    }

    while (sum != 0)
    {
        if (sum % 10 == 0)
        {
            ELMT(l3, idx3) = 0;
            sum /= 10;
        }
        else
        {
            ELMT(l3, idx3) = sum % 10;
            sum /= 10;
        }
        idx3--;
    }

    ELMT(l3, listLength(l3)) = MARK;
    printList(l3);
    printf("\n");
    return 0;
}
