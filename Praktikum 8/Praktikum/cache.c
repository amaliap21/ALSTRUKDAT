#include <stdio.h>
#include "listlinier.h"

int main()
{
    int n,q,x,temp;

    float hit =0;

    List l;
    CreateList(&l);

    scanf("%d",&n);
    scanf("%d", &q);

if (q > 0){
        for (int i = 0 ; i < q ; i ++){
            scanf("%d", &x);
            if (isEmpty(l)){
                if (length(l) < n)
                {
                    insertFirst(&l, x);
                }
                printf("miss ");
                displayList(l);
                printf("\n");
            }
            else if (indexOf(l, x) != IDX_UNDEF){
                hit++;
                deleteAt(&l, indexOf(l, x), &temp);
                insertFirst(&l, x);
                printf("hit ");
                displayList(l);
                printf("\n");
            }
            else if (length(l) == n){
                deleteLast(&l, &temp);
                insertFirst(&l, x);

                printf("miss ");
                displayList(l);
                printf("\n");
            }
            else{
                insertFirst(&l, x);
                printf("miss ");
                displayList(l);
                printf("\n");
            }
	    }

        double ratio = hit / q;
        printf("hit ratio: %.2f\n",ratio);
    }

    else{
        printf("hit ratio: %.2f\n",0.00);
    }
    return 0;
}