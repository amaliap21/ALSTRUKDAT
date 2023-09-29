#include <stdio.h>
#include "wordmachine.h"

void LowerCase()
{
    /*I.S. currentword terdefinisi sembarang tetapi tidak kosong*/
    /*F.S. currentword menjadi lowercase di setiap karakternya*/
    int i;
    for (i = 0; i < currentWord.Length; i++)
    {
        if (currentWord.TabWord[i] >= 65 && currentWord.TabWord[i] <= 90)
        {
            currentWord.TabWord[i] += 32;
        }
    }
}

int main()
{
    // BANDUNG BONDOWOSO MEMBUAT SERIBU CANDI. = bandung bondowoso membuat seribu candi.
    STARTWORD();
    while (!EndWord)
    {
        LowerCase();
        int i;
        for (i = 0; i < currentWord.Length; i++)
        {
            printf("%c", currentWord.TabWord[i]);
        }
        if (currentChar == MARK)
        {
            break;
        }
        else
        {
            printf(" ");
        }
        ADVWORD();
    }
    printf(".\n");

    return 0;
}