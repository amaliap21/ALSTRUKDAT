#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

int main()
{
    Word temp;
    int i;

    STARTWORD();
    int geser = currentWord.Length % 26;

    for (i = 0; i < currentWord.Length; i++)
    {
        temp.TabWord[i] = currentWord.TabWord[i] + geser;
        if (currentWord.TabWord[i] > 90)
        {
            temp.TabWord[i] - 26;
        }
        printf("%c", temp.TabWord[i]);
    }
    ADVWORD();

    while (!EndWord)
    {
        printf(" ");

        int len = currentWord.Length;
        temp.Length = len;

        for (int i = 0; i < len; i++)
        {
            /* code */
        }
    }

    return 0;
}