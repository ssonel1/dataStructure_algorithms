
#include "stack.h"



stack* createStack(int cap)
{
    stack* stck = new stack;
    if (!stck)
    {
        return 0;
    }

    stck->capacity = cap;
    stck->size = 0;
    stck->stck = new (binaryTree * [cap]);

    return stck;
}


int deleteStack(stack* stck)
{
    if (!stck)
    {
        return 0;
    }

    if (stck->stck)
    {
        delete[] stck->stck;
    }

    delete stck;
    return 1;
}


bool isStackFull(stack* stck)
{
    if (!stck)
    {
        return  0;
    }

    if (stck->size == stck->capacity)
    {
        return 1;
    }

    return 0;
}


bool isStackEmpty(stack* stck)
{
    if (!stck)
    {
        return 0;
    }

    if (stck->size == 0)
    {
        return 1;
    }

    return 0;
}


int push(stack* s, binaryTree* node)
{
    if ((!s) || (!node))
    {
        return 0;
    }

    if (isStackFull(s))
    {
        return 0;
    }

    s->stck[s->size] = node;
    s->size++;

    return 1;
}


binaryTree* pop(stack* s)
{
    if (!s)
    {
        return 0;
    }

    if (isStackEmpty(s))
    {
        return 0;
    }

    s->size--;
    return s->stck[s->size];
}