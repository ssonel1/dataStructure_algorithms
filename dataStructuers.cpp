// dataStructuers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

 struct binaryTree
{
     int data;
     binaryTree* rightNode;
     binaryTree* leftNode;
};


 binaryTree* createNode(int data_);
 int deleteTree(binaryTree* root);
 int insertNode(binaryTree* root, int data_);  //insert node with level order traversal
 int printTree(binaryTree* root);
 int printLevelOrder(binaryTree* root);
 int printLevelOrderReverse(binaryTree* root);
 int treeSize(binaryTree* root);    //with recursion
 int treeSize2(binaryTree* root);   //without recursion

 /***********************************************************************/

 struct queue
 {
     int capacity;
     int size;
     int rear;
     int front;
     binaryTree** q;
 };

 queue* createQueue(int cap);
 void deleteQueue(queue* q);
 bool isQueueFull(queue* q);
 bool isQueueEmpty(queue* q);
 int enqueue(queue* q, binaryTree* node);
 binaryTree* dequeue(queue* q);


  /***********************************************************************/

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

  /***********************************************************************/

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

    cout << "Hello World!\n";

    while (1)
    {


    }

}


/****************************************************************************/
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


int deleteTree(binaryTree* root)
{
    if (!root)
    {
        return 0;
    }

    delete root;
    return 1;
}




int insertNode(binaryTree* root, int data_)
{
    if (!root)
    {
        return 0;   //root is empty??
    }

    binaryTree* tmp;
    binaryTree* nodeToInsert = createNode(data_);

    queue* q = createQueue(50);
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
        return 0;
    }

    queue* q = createQueue(50);
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
        return 0;
    }

    binaryTree* tmp;
    queue* q = createQueue(50);
    stack* s = createStack(50);

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

    queue* q = createQueue(50);
    binaryTree* tmp;
    int treeSize = 1;  

    enqueue(q,root);

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

/******************************************************************************/

queue* createQueue(int cap)
{
    queue* tmp = new queue;
    tmp->capacity = cap;
    tmp->front = 0;
    tmp->rear = 0;
    tmp->size = 0;
    tmp->q = new (binaryTree*[cap]);

    return tmp;
}


void deleteQueue(queue* q)
{
    if (q)
    {
        if (q->q)
        {
            delete[] q->q;
        }
        delete q;
    }
}


bool isQueueFull(queue* q)
{
    if (!q)
    {
        return 0;
    }

    if (q->capacity == q->size)
    {
        return 1;
    }

    return 0;
}

bool isQueueEmpty(queue* q)
{
    if (!q)
    {
        return 0;
    }

    if (q->size == 0)
    {
        return 1;
    }

    return 0;
}


int enqueue(queue* q, binaryTree* node)
{
    if ((!q) || (!node))
    {
        return 0; //it's null
    }

    if (!isQueueFull(q))
    {
        q->q[q->rear] = node;

        q->rear = (q->rear + 1) % q->capacity;
        q->size++;
        return 1;
    }

    return 0;
}



binaryTree* dequeue(queue* q)
{
    if (!q)
    {
        return 0;
    }

    if (!isQueueEmpty(q))
    {
        binaryTree* tmp = q->q[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size--;

        return tmp;
    }

    return 0;
}


/******************************************************************************/

stack* createStack(int cap)
{
    stack* stck = new stack;
    if (!stck)
    {
        return 0;
    }

    stck->capacity = cap;
    stck->size = 0;
    stck->stck = new (binaryTree*[cap]);

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