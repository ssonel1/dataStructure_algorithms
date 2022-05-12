// dataStructuers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "binaryTree.h"
#include "queue.h"
#include "stack.h"
#include "linkedList.h"

using namespace std;


int main()
{
    
    
    //test
    queue* q = createQueue(1, true);
    
    

    for (int i = 0; i < 4; i++)
    {
        enqueue(q, createNode(i));
    }

    dequeue(q);
    dequeue(q);

    for (int k = 0; k < 16; k++)
    {
        enqueue(q, createNode(k));
    }

    cout << "Hello World!\n";

    while (1)
    {


    }

}

