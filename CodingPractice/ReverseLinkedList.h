#pragma once

#include "LinkedList_C.h"

class ReverseLinkedList
{
public:
	void Test();
	linked_list * ReverseLinkedListSegment(linked_list * A, int m, int n);
};

void ReverseLinkedList::Test()
{
	LinkedList_C linkedList;

	linked_list * data = linkedList.create_node(1);
	linkedList.push_back(&data, 2);
	linkedList.push_back(&data, 3);
	linkedList.push_back(&data, 4);

	ReverseLinkedListSegment(data, 1, 2);
}

linked_list * ReverseLinkedList::ReverseLinkedListSegment(linked_list * A, int m, int n)
{
	if (m == n)
	{
		return A;
	}

	linked_list * headNode = A;
	linked_list * prevNode = NULL;
	linked_list * nextNode = NULL;
	linked_list * mPrevNode;
	linked_list * mNode;

	//Go to node M

	for (int i = 1; i < m - 1; i++)
	{
		headNode = headNode->pNextNode;
	}

	//We are at m so reverse until n
	//we need previous pointer to point to n and m to point to where n was pointing too
	if (m == 1)
	{
		mPrevNode = NULL;
		mNode = headNode;
	}
	else
	{
		mPrevNode = headNode;
		headNode = headNode->pNextNode;
		mNode = headNode;
	}



	for (int i = m; i <= n; i++)
	{
		nextNode = headNode->pNextNode;
		headNode->pNextNode = prevNode;
		prevNode = headNode;

		headNode = nextNode;

	}

	//we are at n so
	//nextNode = headNode->next;
	if (mPrevNode != NULL)
	{
		mPrevNode->pNextNode = prevNode;
	}

	if (headNode != NULL)
	{
		mNode->pNextNode = headNode;
	}

	if (m > 1)
	{
		return A;
	}
	else
	{
		return prevNode;
	}
}
