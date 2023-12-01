#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

boolean isLess(Word word1, Word word2)
{
    int len;
    if (word1.Length < word2.Length)
    {
        len = word1.Length;
    }
    else
    {
        len = word2.Length;
    }

    int i;
    for (i = 0; i < len; i++)
    {
        if (word1.TabWord[i] != word2.TabWord[i])
        {
            if (word1.TabWord[i] - 'a' < word2.TabWord[i] - 'a')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return word1.Length <= word2.Length;
}

void bubbleSort(Word array[], int count)
{
    int i, j;
    Word temp;
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count - 1; j++)
        {
            if (!isLess(array[j], array[j + 1]))
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printWord(Word word)
{
    int i;
    for (i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }
}

int main()
{
    Word listWord[50];

    int count = 0;
    STARTWORD();
    while (!EndWord)
    {
        listWord[count] = currentWord;
        count++;
        ADVWORD();
    }

    bubbleSort(listWord, count);

    int i;
    for (i = 0; i < count; i++)
    {
        printWord(listWord[i]);
        printf("\n");
    }
    return 0;
}