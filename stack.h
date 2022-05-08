#pragma once

struct binaryTree;  //forward declaration to prevent circular dependency


struct stack
{
    int capacity;
    int size;
    binaryTree** stck;
};

stack* createStack(int cap);
int deleteStack(stack* stck);
bool isStackFull(stack* stck);
bool isStackEmpty(stack* stck);
int push(stack* s, binaryTree* node);
binaryTree* pop(stack* s);


