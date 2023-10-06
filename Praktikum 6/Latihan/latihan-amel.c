#include <stdio.h>
#include <string.h>
#include "stack.h"

int charToNum(char c)
{
    return (c - 48);
}

boolean isGreater(char arr1[100], char arr2[100])
{
    int temp1, temp2;

    if (strlen(arr1) > strlen(arr2))
    {
        return true;
    }
    else if (strlen(arr1) < strlen(arr2))
    {
        return false;
    }
    else
    {
        int i = 0;
        while (i < strlen(arr1))
        {
            if (strlen(arr1) > strlen(arr2))
            {
                return true;
            }
            else if (strlen(arr1) < strlen(arr2))
            {
                return false;
            }
            i++;
        }
    }
    return true;
}

int main(){
    
    
    return 0;
}