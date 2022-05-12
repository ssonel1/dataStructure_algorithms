
#include "queue.h"


static int doubleQueueCapacity(queue* q)
{
    binaryTree** bTree = new (binaryTree*[q->capacity * 2]);
    if (!bTree)
    {
        return 0;
    }

    for (int i = 0; i < q->size; i ++)
    {
        bTree[q->front + i] = q->q[(q->front + i) % q->capacity];
    }

    q->capacity *= 2;
    delete[] q->q;
    q->q = bTree;
    return 1;
}


queue* createQueue(int cap, bool isDynamic)
{
    queue* tmp = new queue;
    if (!tmp)
    {
        return 0;
    }
    tmp->capacity = cap;
    tmp->front = 0;
    tmp->rear = 0;
    tmp->size = 0;
    tmp->isDynamic = isDynamic;
    tmp->q = new (binaryTree * [cap]);

    if (!tmp->q)
    {
        delete tmp;
        return 0;
    }

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

    if (isQueueFull(q))
    {
        if (q->isDynamic == true)
        {
            if (!doubleQueueCapacity(q))
            {
                return 0;
            }
        }
        else
        {
            return 0; //it's full and cannot dynamically grow
        }
    }
    
    q->q[q->rear] = node;
    if ((q->size + 1) != q->capacity)     //buraya daha sonra bi daha bak, gece gece kafam almiyor.
    {
        q->rear = (q->rear + 1) % q->capacity;
    }
    else
    {
        q->rear++;
    }
    
    q->size++;
    return 1;    
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