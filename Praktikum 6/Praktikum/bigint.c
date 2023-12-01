#include <stdio.h>
#include "stack.h"
#include "wordmachine.h"
#include "charmachine.h"

int angka (char karakter)
{
    return karakter - 48;
}

int main(){
    Word listWords[100];
    int countWord = 0;

    START();
    while(currentChar != MARK){
        ADVWORD();
 
        listWords[countWord] = currentWord;
        countWord++;
    }
    int hasil;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < countWord; i++)
    {
        int panjang = listWords[i].Length;
        int j;
        for (j = panjang-1; j >= 0; j--){
            int k;
            int sepuluh = 1;
            for (k = 0; k < ((panjang-1)-j); k++){
                sepuluh = sepuluh*10;
            }
            if (i == 0){
                sum1 = sum1 + angka(listWords[i].TabWord[j])*sepuluh; 
            }
            else{
                sum2 = sum2 + angka(listWords[i].TabWord[j])*sepuluh; 
            }
        }
    }
    hasil = sum1 - sum2;
    printf("%d\n", hasil);    
}