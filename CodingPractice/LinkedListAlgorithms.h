#ifndef LINKED_LIST_ALGORITHMS_H__
#define LINKED_LIST_ALGORITHMS_H__

#include "ListNode.h"

class LinkedListAlgorithms
{
public:
	LinkedListAlgorithms( void ) {}
	~LinkedListAlgorithms( void ) {};

	void TestAll( void );
	void TestFindNthFromLastElemenet( ListNode* list );
	void TestRemoveDuplicates( void );

	ListNode* FindNthElementFromEnd( ListNode* list, int nthFromEnd );
	void RemoveDuplicates( ListNode* list );

	ListNode* CreateListFromArray( const int* elements, int count );
	void DeleteList( ListNode* list );
	void PrintList( ListNode* list );

private:
};

void LinkedListAlgorithms::TestAll( void )
{
	ListNode node(0);
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);

	node.SetNextNode( &node1 );
	node1.SetNextNode( &node2 );
	node2.SetNextNode( &node3 );

	TestFindNthFromLastElemenet( &node );
}

void LinkedListAlgorithms::TestFindNthFromLastElemenet( ListNode* list )
{
	int ex[] = {3, 2, 1, 0};
	ListNode* nodeOut;

	cout << ">>>> Find nth from last element" << endl;

	nodeOut = FindNthElementFromEnd( list, 1 );

	for( int i = 0; i < 4; i++ )
	{
		nodeOut = FindNthElementFromEnd( list, i );

		cout << "Test nth value = " << i << endl << "Expected = " << ex[i] << endl << "Result   = " ;
		
		if(nodeOut)
			cout << nodeOut->GetData() << endl;
		else
			cout << "NULL" << endl;
	}
}

void LinkedListAlgorithms::TestRemoveDuplicates( void )
{
	
}
/*
* To get this one count n Pointers and then start another pointer n behind the head
* Assumtion: 0 == last element, 1 = 2nd to last
* [1,2,3] 
* 0 = 3, 1 = 2
*/
ListNode * LinkedListAlgorithms::FindNthElementFromEnd( ListNode* list, int nthFromEnd )
{
	ListNode* headPtr = list;
	ListNode* tailPtr = 0;
	// 0,1,2 : nth=2 , element = 2
	// headPtr=0,1| 1,1 | 2 
	while( headPtr->GetNextNode() != 0 &&
		   nthFromEnd
		   )
	{
		nthFromEnd--;
		headPtr = headPtr->GetNextNode();
	}

	if( nthFromEnd == 0 )
	{
		tailPtr = list;
	
		while( headPtr->GetNextNode() != 0 )
		{
			headPtr = headPtr->GetNextNode();
			tailPtr = tailPtr->GetNextNode();
		}
	}

	return tailPtr;
}

/*
* This will remove all duplicate data in a list
*
for( i->lastNode )
   for( j = i; j->lastNode )
     if( node[i] == node[i] )
	 {
		replace pointer
		delete
	 }
*/

void LinkedListAlgorithms::RemoveDuplicates( ListNode* list )
{
	ListNode* currentNode;

	if( list == 0 )
	{
		return;
	}
	
	currentNode = list;

	while( currentNode->GetNextNode() == 0 )
	{
		/* itr = cur 
		* validatingNode = itr->next;
		* if validatingNode is duplicate
		*  cur->next = validating->next;
		   delete validating
		  else
		   cur = cur->next
	    */
		
		ListNode* iteratorNode = currentNode;

		while( iteratorNode->GetNextNode() != 0 )
		{
			ListNode* validatingNode = iteratorNode->GetNextNode();

			if( currentNode->GetData() == validatingNode->GetData() )
			{
				iteratorNode->SetNextNode( validatingNode->GetNextNode() );

				delete validatingNode;
			}
			else
			{
				iteratorNode->SetNextNode( iteratorNode->GetNextNode() );
			}
		}

		if( currentNode->GetNextNode() )
		{
			currentNode->SetNextNode( currentNode->GetNextNode() );
	
		}
	}
}
	
ListNode* LinkedListAlgorithms::CreateListFromArray( const int* elements, int count )
{
		
	ListNode* startNode;
	ListNode* currentNode;

	while( count-- )
	{
		if( currentNode == 0 )
		{
			currentNode = new ListNode( *elements );
			startNode = currentNode;
		}
		else
		{
			currentNode->SetNextNode( new ListNode( *elements ) );
			currentNode = currentNode->GetNextNode();
		}
		
		elements++;
	}

	return startNode;
}

void LinkedListAlgorithms::DeleteList( ListNode* list )
{
	if( list != 0 )
	{
		DeleteList( list->GetNextNode() );
		delete list;
	}
}

void LinkedListAlgorithms::PrintList( ListNode* list )
{
	ListNode* printNode = list;

	cout << "[ ";
	
	while( printNode != 0 )
	{
		cout << printNode->GetData() << ", ";
	}

	cout << " ]";


	while(
}

#endif