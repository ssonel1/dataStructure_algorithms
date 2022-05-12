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
    stack* stck = createStack(2, true); //starting with capacity 2 

    

    for (int i = 0; i < 16; i++)
    {
        push(stck, createNode(i));
    }

    cout << "Hello World!\n";

    while (1)
    {


    }

}

