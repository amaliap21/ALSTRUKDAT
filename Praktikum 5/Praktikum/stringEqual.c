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

// Returns string length
int stringLength(char *s)
{
    int result = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        result++;
        i++;
    }
    return result;
}

boolean IsKataSama(Word kata1, char *kata2)
{
    boolean result = true;
    int i = 0;

    if (kata1.Length != stringLength(kata2))
    {
        result = false;
    }
    else
    {
        while (i < kata1.Length && result)
        {
            if (kata1.TabWord[i] != kata2[i])
            {
                result = false;
            }
            i++;
        }
    }
    return result;
}

int main()
{
    Word kata;

    char *moveLeft = "MOVELEFT";
    char *moveRight = "MOVERIGHT";
    char *moveUp = "MOVEUP";
    char *moveDown = "MOVEDOWN";

    char *input;

    STARTWORD();

    printf("Moving ");
    printWord(currentWord);
    printf(" ");

    ADVWORD();

    if (IsKataSama(currentWord, moveLeft))
    {
        printf("square leftwards\n");
    }
    else if (IsKataSama(currentWord, moveRight))
    {
        printf("square rightwards\n");
    }
    else if (IsKataSama(currentWord, moveUp))
    {
        printf("square upwards\n");
    }
    else if (IsKataSama(currentWord, moveDown))
    {
        printf("square downwards\n");
    }

    return 0;
}