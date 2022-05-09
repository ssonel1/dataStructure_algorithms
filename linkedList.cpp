#include "linkedList.h"


linkedList* createList(int data_)
{
	linkedList* listHead = new linkedList;
	if (!listHead)
	{
		return 0; //couldn't allocate memory
	}

	listHead->data = data_;
	listHead->nextNode = NULL;
	
	return listHead;
}


int insertListNode(linkedList** head, int index, int data_)
{
	if ((!(*head)) || (index < 0))
	{
		return 0;
	}

	linkedList* tmpNode = *head;
	linkedList* nodeToInsert = new linkedList;
	nodeToInsert->data = data_;

	
	if (index == 0)
	{
		nodeToInsert->nextNode = *head;
		*head = nodeToInsert;
		return 1;
	}

	for (int i = 0; i < (index - 1); i++)
	{
		tmpNode = tmpNode->nextNode;

		//check if index is out of boundry
		if (!tmpNode)
		{
			delete nodeToInsert;
			return 0;		//tmpNode will be NULL if index is out of boundry
		}
	}

	nodeToInsert->nextNode = tmpNode->nextNode;
	tmpNode->nextNode = nodeToInsert;

	return 1;
}

