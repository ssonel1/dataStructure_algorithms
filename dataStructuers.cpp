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
    linkedList* head = createList(0);
    insertListNode(&head, 1, 1);
    insertListNode(&head, 2, 2);
    insertListNode(&head, 3, 3);
    insertListNode(&head, 1, 11);
    insertListNode(&head, 0, 22);
    insertListNode(&head, 0, 33);
    insertListNode(&head, 1, 44);
    insertListNode(&head, 5, 5);
    insertListNode(&head, 55, 1);   
    deleteListNode(&head, 1);
    deleteListNode(&head, 0);
    deleteListNode(&head, 0);
    deleteListNode(&head, 1);
    deleteListNode(&head, 4);
    deleteListNode(&head, 30);
    deleteList(head);

    cout << "Hello World!\n";

    while (1)
    {


    }

}

