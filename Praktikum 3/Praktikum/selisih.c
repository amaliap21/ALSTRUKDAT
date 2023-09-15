#include <stdio.h>
#include "listdin.h"

int main(){
    ListDin l;
    CreateListDin(&l,100);
    readList(&l);

    int max,min;
    extremeValues(l,&max,&min);
    max += 1;

    int selisih = max-min;

    if (listLength(l) != 1){
        printf("%d\n", selisih);
    }
    else{
        printf("%d\n", selisih-1);
    }
    return 0;
}