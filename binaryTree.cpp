
#include "binaryTree.h"
#include "queue.h"
#include "stack.h"
#include <iostream>
using namespace std;

binaryTree* createNode(int data_)
{
    binaryTree* temp = new binaryTree;

    if (!temp)
    {
        return 0;   //couldn't allocate memory
    }

    temp->data = data_;
    temp->leftNode = NULL;
    temp->rightNode = NULL;
    return temp;

}


int deleteNode(binaryTree* node)
{
    if (!node)
    {
        return 0;
    }

    delete node;
    return 1;
}


int deleteTree(binaryTree* root)
{
    if (!root)
    {
        return 0;
    }

    if (root->leftNode)
    {
        deleteTree(root->leftNode);
    }

    if (root->rightNode)
    {
        deleteTree(root->rightNode);
    }

    deleteNode(root);

    return 1;
}



int insertNode(binaryTree* root, int data_)
{
    if (!root)
    {
        return 0;   //root is not valid
    }

    binaryTree* tmp;
    binaryTree* nodeToInsert = createNode(data_);

    queue* q = createQueue(50, true);
    enqueue(q, root);

    while (!isQueueFull(q))
    {
        tmp = dequeue(q);

        if (!tmp->leftNode)
        {
            //left node is empty
            tmp->leftNode = nodeToInsert;
            deleteQueue(q);
            return 1;
        }
        else
        {
            enqueue(q, tmp->leftNode);
        }

        if (!tmp->rightNode)
        {
            //right node is empty
            tmp->rightNode = nodeToInsert;
            deleteQueue(q);
            return 1;
        }
        else
        {
            enqueue(q, tmp->rightNode);
        }

    }

    deleteQueue(q);
    delete nodeToInsert;
    return 0;
}


int printTree(binaryTree* root)
{
    if (!root)
    {
        cout << "Tree not available. \r\n";
        return 0;
    }

    cout << "Node Data: " << root->data << "\r\n";

    if (root->leftNode)
    {
        printTree(root->leftNode);
    }

    if (root->rightNode)
    {
        printTree(root->rightNode);
    }

    return 1;
}


int printLevelOrder(binaryTree* root)
{
    if (!root)
    {
        cout << "Tree not available. \r\n";
        return 0;
    }

    queue* q = createQueue(50, true);
    binaryTree* tmp;

    enqueue(q, root);

    while (!isQueueEmpty(q))
    {
        tmp = dequeue(q);
        cout << "Node Data: " << tmp->data << "\r\n";

        if (tmp->leftNode)
        {
            enqueue(q, tmp->leftNode);
        }

        if (tmp->rightNode)
        {
            enqueue(q, tmp->rightNode);
        }
    }
    deleteQueue(q);
    return 1;
}



int printLevelOrderReverse(binaryTree* root)
{
    if (!root)
    {
        cout << "Tree not available. \r\n";
        return 0;
    }

    binaryTree* tmp;
    queue* q = createQueue(50, true);
    stack* s = createStack(50, true);

    enqueue(q, root);

    while (!isQueueEmpty(q))
    {
        tmp = dequeue(q);

        if (tmp->leftNode)
        {
            enqueue(q, tmp->leftNode);
        }

        if (tmp->rightNode)
        {
            enqueue(q, tmp->rightNode);
        }

        push(s, tmp);
    }

    while (!isStackEmpty(s))
    {
        tmp = pop(s);
        cout << " Node Data: " << tmp->data << "\r\n";
    }

    deleteStack(s);
    deleteQueue(q);
    return 1;
}


int treeSize(binaryTree* root)
{
    if (!root)
    {
        return 0;
    }

    return treeSize(root->leftNode) + 1 + treeSize(root->rightNode);
}


int treeSize2(binaryTree* root)
{
    if (!root)
    {
        return 0;
    }

    queue* q = createQueue(50, true);
    binaryTree* tmp;
    int treeSize = 1;

    enqueue(q, root);

    while (!isQueueEmpty(q))
    {
        tmp = dequeue(q);

        if (tmp->leftNode)
        {
            enqueue(q, tmp->leftNode);
            treeSize++;
        }

        if (tmp->rightNode)
        {
            enqueue(q, tmp->rightNode);
            treeSize++;
        }
    }


    deleteQueue(q);
    return treeSize;
}



int findMaxElement(binaryTree* root)
{
    if (!root)
    {
        return 0;
    }

    int maxVal = root->data;
    queue* q = createQueue(50, true);
    binaryTree* tmp;

    enqueue(q, root);

    while (!isQueueEmpty(q))
    {
        tmp = dequeue(q);

        if (tmp->rightNode)
        {
            enqueue(q, tmp->rightNode);
        }

        if (tmp->leftNode)
        {
            enqueue(q, tmp->leftNode);
        }

        if (tmp->data > maxVal)
        {
            maxVal = tmp->data;
        }
    }

    deleteQueue(q);
    return maxVal;
}


