#include <stdio.h>
#include <math.h>
#include "listdin.h"

int main(){
    ListDin l;
    IdxType i;
    int query, tipe, num;

    CreateListDin(&l, 0);

    scanf("%d", &query);
    for (i=0; i<query;i ++){
        scanf("%d", &tipe);

        if (tipe==1){
            scanf("%d", &num);

            if (!isFull(l)){
                insertLast(&l, num);
            }
            else {
                if (CAPACITY(l)!=0){
                    expandList(&l, CAPACITY(l));
                }
                else{
                    expandList(&l, 1);
                }
                insertLast(&l, num);
            }

        }
        else if (tipe==2){
            deleteLast(&l, &ELMT(l,getLastIdx(l)));

            if (NEFF(l) <= round(CAPACITY(l)/2)){
                CAPACITY(l) = round(CAPACITY(l)/2);
            }

        }
        else {
            printf("%d ", CAPACITY(l));
            printList(l);
            printf("\n");
        }
    }
    return 0;
}