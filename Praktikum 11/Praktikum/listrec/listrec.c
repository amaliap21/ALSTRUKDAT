/* File: listrec.c */

#include "listrec.h"
#include <stdlib.h>

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

boolean isEmpty(List l)
{
    return l == NIL;
}

boolean isOneElmt(List l)
{
    return !isEmpty(l) && NEXT(l) == NIL;
}

ElType head(List l)
{
    return INFO(l);
}

List tail(List l)
{
    return NEXT(l);
}

List konso(List l, ElType e)
{
    Address P = newNode(e);
    if (P != NIL)
    {
        NEXT(P) = l;
        return P;
    }
    else
    {
        return l;
    }
}

List konsb(List l, ElType e)
{
    if (isEmpty(l))
    {
        return newNode(e);
    }
    else
    {
        NEXT(l) = konsb(NEXT(l), e);
        return l;
    }
}

List copy(List l)
{
    if (isEmpty(l))
    {
        return NIL;
    }
    else
    {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2)
{
    if (isEmpty(l1))
    {
        return l2;
    }
    else
    {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

int length(List l)
{
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x)
{
    if (isEmpty(l))
    {
        return false;
    }
    else
    {
        return (head(l) == x) || isMember(tail(l), x);
    }
}

void displayList(List l)
{
    if (!isEmpty(l))
    {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

List insertAt(List l, ElType e, int idx)
{
    if (idx == 0)
    {
        return konso(l, e);
    }
    else if (isEmpty(l))
    {
        return l;
    }
    else
    {
        NEXT(l) = insertAt(tail(l), e, idx - 1);
        return l;
    }
}

List deleteFirst(List l)
{
    if (isEmpty(l))
    {
        return l;
    }
    else
    {
        Address temp = l;
        l = NEXT(l);
        free(temp);
        return l;
    }
}

List deleteAt(List l, int idx)
{
    if (isEmpty(l))
    {
        return l;
    }
    else if (idx == 0)
    {
        return deleteFirst(l);
    }
    else
    {
        NEXT(l) = deleteAt(tail(l), idx - 1);
        return l;
    }
}

List deleteLast(List l)
{
    if (isEmpty(l))
    {
        return l;
    }
    else if (NEXT(l) == NIL)
    {
        free(l);
        return NIL;
    }
    else
    {
        NEXT(l) = deleteLast(tail(l));
        return l;
    }
}

List inverseList(List l)
{
    List result = NIL;
    while (!isEmpty(l))
    {
        result = konso(result, head(l));
        l = tail(l);
    }
    return result;
}

void splitPosNeg(List l, List *l1, List *l2)
{
    *l1 = NIL;
    *l2 = NIL;

    while (!isEmpty(l))
    {
        if (head(l) >= 0)
        {
            *l1 = konso(*l1, head(l));
        }
        else
        {
            *l2 = konso(*l2, head(l));
        }
        l = tail(l);
    }
}

void splitOnX(List l, ElType x, List *l1, List *l2)
{
    *l1 = NIL;
    *l2 = NIL;

    while (!isEmpty(l))
    {
        if (head(l) < x)
        {
            *l1 = konso(*l1, head(l));
        }
        else
        {
            *l2 = konso(*l2, head(l));
        }
        l = tail(l);
    }
}

List removeDuplicate(List l, List unique)
{
    if (isEmpty(l))
    {
        return unique;
    }
    else
    {
        if (!isMember(unique, head(l)))
        {
            unique = konso(unique, head(l));
        }
        return removeDuplicate(tail(l), unique);
    }
}
