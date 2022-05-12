
#include "stack.h"



/*Static Functions*/
static int doubleStackCapacity(stack* s)
{
    
    binaryTree** newStack = new (binaryTree*[s->capacity * 2]);
    if (!newStack)
    {
        return 0; //check if memory allocated
    }

    for (int i = 0; i < s->size; i++)
    {
        newStack[i] = s->stck[i];
    }
    delete[] s->stck;
    s->capacity *= 2;
    s->stck = newStack;

    return 1;
}






/*Functions*/


stack* createStack(int cap = 0, bool isDynamic = false)
{
    stack* stck = new stack;
    if (!stck)
    {
        return 0;
    }

    stck->capacity = cap;
    stck->size = 0;
    stck->stck = new (binaryTree * [cap]);
    stck->isDynamic = isDynamic;

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
        if (s->isDynamic == false)
        {
            return 0;
        }
        else
        {
            //if it's full then we will double the amount of memory allocated for stack
            if (!doubleStackCapacity(s))
            {
                return 0;
            }
        }
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