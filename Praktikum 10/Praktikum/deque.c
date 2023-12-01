/* File: deque.c */
#include "deque.h"

Address newNode(ElType x)
{
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL)
    {
        INFO(P) = x;
        NEXT(P) = NIL;
    }
    return P;
}

void CreateDeque(Deque *q)
{
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

boolean isEmpty(Deque q)
{
    return ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL;
}

int length(Deque q)
{
    int count = 0;
    Address P = ADDR_HEAD(q);
    while (P != NIL)
    {
        count++;
        P = NEXT(P);
    }
    return count;
}

void DisplayDeque(Deque q)
{
    printf("[");
    Address P = ADDR_HEAD(q);
    while (P != NIL)
    {
        printf("%d", INFO(P));
        P = NEXT(P);
        if (P != NIL)
        {
            printf(",");
        }
    }
    printf("]");
}

void EnqueueHead(Deque *q, ElType x)
{
    Address P = newNode(x);
    if (P != NULL)
    {
        NEXT(P) = ADDR_HEAD(*q);
        ADDR_HEAD(*q) = P;
        if (ADDR_TAIL(*q) == NIL)
        {
            ADDR_TAIL(*q) = P;
        }
    }
}

void DequeueHead(Deque *q, ElType *x)
{
    Address P = ADDR_HEAD(*q);
    *x = INFO(P);
    ADDR_HEAD(*q) = NEXT(P);
    free(P);
    if (ADDR_HEAD(*q) == NIL)
    {
        ADDR_TAIL(*q) = NIL;
    }
}

void EnqueueTail(Deque *q, ElType x)
{
    Address P = newNode(x);
    if (P != NULL)
    {
        if (ADDR_TAIL(*q) != NIL)
        {
            NEXT(ADDR_TAIL(*q)) = P;
            ADDR_TAIL(*q) = P;
        }
        else
        {
            ADDR_HEAD(*q) = ADDR_TAIL(*q) = P;
        }
    }
}

void DequeueTail(Deque *q, ElType *x)
{
    Address P = ADDR_HEAD(*q);
    Address prev = NIL;
    while (NEXT(P) != NIL)
    {
        prev = P;
        P = NEXT(P);
    }
    *x = INFO(P);
    if (prev != NIL)
    {
        NEXT(prev) = NIL;
        ADDR_TAIL(*q) = prev;
    }
    else
    {
        ADDR_HEAD(*q) = ADDR_TAIL(*q) = NIL;
    }
    free(P);
}
