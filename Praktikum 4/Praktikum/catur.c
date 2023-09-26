#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(){
    Matrix m;
    IdxType i, j;

    int putih=0, hitam=0;
    readMatrix(&m,8,8);

    i = 0;
    while (i < 8){
        if (i%2==0){
            for (j=0; j<8; j++){
                if (ELMT(m,i,j) == 1 && j%2 == 0){
                    hitam += 1;
                }
                if (ELMT(m,i,j) == 1 && j%2 == 1){
                    putih += 1;
                }
            }
        }

        else{
            for (j=0; j<8; j++){
                if (ELMT(m,i,j) == 1 && j%2 == 0){
                    putih += 1;
                }
                if (ELMT(m,i,j) == 1 && j%2 == 1){
                    hitam += 1;
                }
            }
        }
        i++;
    }

    printf("%d %d\n", hitam, putih);
    return 0;
}