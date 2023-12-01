#include "listganda.h"
#include <stdlib.h>

Address newNode(ElType val) {
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = val;
        NEXT(P) = NULL;
        PREV(P) = NULL;
    }
    return P;
}

void createListGanda(ListGanda *l) {
    CURRENT(*l) = NULL;
}

boolean isEmpty(ListGanda l) {
    return CURRENT(l) == NULL;
}

boolean isOneElement(ListGanda l) {
    return CURRENT(l) != NULL && NEXT(CURRENT(l)) == CURRENT(l);
}

int length(ListGanda l) {
    int count = 0;
    if (!isEmpty(l)) {
        Address P = CURRENT(l);
        do {
            count++;
            P = NEXT(P);
        } while (P != CURRENT(l));
    }
    return count;
}

void rotate(ListGanda *l, int k) {
    if (!isEmpty(*l)) {
        int n = length(*l);
        if (n > 1) {
            k = k % n;
            if (k < 0) k += n;
            for (int i = 0; i < k; i++) {
                CURRENT(*l) = NEXT(CURRENT(*l));
            }
        }
    }
}

void insertAfterCurrent(ListGanda *l, ElType x) {
    Address P = newNode(x);
    if (P != NULL) {
        if (isEmpty(*l)) {
            CURRENT(*l) = P;
            NEXT(P) = P;
            PREV(P) = P;
        } else {
            NEXT(P) = NEXT(CURRENT(*l));
            PREV(NEXT(CURRENT(*l))) = P;
            NEXT(CURRENT(*l)) = P;
            PREV(P) = CURRENT(*l);
        }
    }
}

void deleteCurrent(ListGanda *l, ElType *x) {
    if (!isEmpty(*l)) {
        Address P = CURRENT(*l);
        *x = INFO(P);
        if (isOneElement(*l)) {
            CURRENT(*l) = NULL;
            free(P);
        } else {
            NEXT(P) = NEXT(CURRENT(*l));
            PREV(NEXT(CURRENT(*l))) = PREV(P);
            if (P == CURRENT(*l)) {
                CURRENT(*l) = NEXT(P);
            }
            free(P);
        }
    }
}
