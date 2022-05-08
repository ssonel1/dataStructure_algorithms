// dataStructuers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "binaryTree.h"
#include "queue.h"
#include "stack.h"

using namespace std;


int main()
{
    binaryTree* root = createNode(0);

    for (int i = 1; i < 31; i++)
    {
        insertNode(root, i);
    }

    cout << "Tree Size2 is: " << treeSize2(root) << "\r\n";
    cout << "*****************************************\r\n";
    cout << "Tree Size is: " << treeSize(root) << "\r\n";
    cout << "*****************************************\r\n";
    printTree(root);
    cout << "*****************************************\r\n";
    printLevelOrder(root);
    cout << "*****************************************\r\n";
    printLevelOrderReverse(root);
    cout << "*****************************************\r\n";
  



    cout << "Hello World!\n";

    while (1)
    {


    }

}

