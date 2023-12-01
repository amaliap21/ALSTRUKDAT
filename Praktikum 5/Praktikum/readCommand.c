#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

// Prints word from Mesin Kata
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
    Word kata;
    kata.Length = 0;

    START();
    IgnoreBlanks();
    while (currentChar != MARK)
    {
        kata.TabWord[kata.Length] = currentChar;
        kata.Length++;
        ADV();
    }

    printWord(kata);
    printf("\n");
    printf("%d\n", kata.Length);

    return 0;
}