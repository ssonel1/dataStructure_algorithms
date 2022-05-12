#pragma once

struct binaryTree; //forward declaration

struct queue
{
    int capacity;
    int size;
    int rear;
    int front;
    bool isDynamic;
    binaryTree** q;
};

queue* createQueue(int cap = 0, bool isDynamic = false);
void deleteQueue(queue* q);
bool isQueueFull(queue* q);
bool isQueueEmpty(queue* q);
int enqueue(queue* q, binaryTree* node);
binaryTree* dequeue(queue* q);


