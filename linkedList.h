#pragma once

#include <iostream>

struct linkedList
{
	int data;
	linkedList* nextNode;
};


linkedList* createList(int data_);
int deleteList(linkedList* head);
int insertListNode(linkedList** head, int index, int data_);
int deleteListNode(linkedList** head, int index);
int listSize(linkedList* head);


