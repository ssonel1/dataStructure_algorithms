
#include "queue.h"


queue* createQueue(int cap)
{
    queue* tmp = new queue;
    tmp->capacity = cap;
    tmp->front = 0;
    tmp->rear = 0;
    tmp->size = 0;
    tmp->q = new (binaryTree * [cap]);

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