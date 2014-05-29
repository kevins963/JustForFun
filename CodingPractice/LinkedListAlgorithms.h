#ifndef LINKED_LIST_ALGORITHMS_H__
#define LINKED_LIST_ALGORITHMS_H__

#include "ListNode.h"
#include "Utilities.h"

class LinkedListAlgorithms
{
public:
	LinkedListAlgorithms( void ) {}
	~LinkedListAlgorithms( void ) {};

	void TestAll( void );
	void TestFindNthFromLastElemenet( ListNode* list );
	void TestRemoveDuplicates( void );
    void TestCreateList( void );

	ListNode* FindNthElementFromEnd( ListNode* list, int nthFromEnd );
	void RemoveDuplicates( ListNode* list );

	ListNode* CreateListFromArray( const int* elements, int count );
	void DeleteList( ListNode* list );

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
    TestRemoveDuplicates();
    TestCreateList();
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
	int t1[] = {1,1,1,2,2,2,1,1,1,2,2,2};
    int e1[] = {1,2};
    ListNode* n1 = CreateListFromArray( t1, sizeof( t1) / sizeof( int ) );

    cout << "<<<< Test Remove Duplicates" << endl;

    RemoveDuplicates( n1 );

    cout << "Test     = ";
    PrintArray( t1, 0, sizeof( t1 ) / sizeof( int ), true );
    cout << "Expected = ";
    PrintArray( e1, 0, sizeof( e1 ) / sizeof( int ), true );
    cout << "Results  = ";
    PrintList( n1, true );
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

void LinkedListAlgorithms::TestCreateList( void )
{
    int t1[] = {1, 2, 3, 4, 5};
    int e1[] = {1, 2, 3, 4, 5};

    ListNode* list = CreateListFromArray( t1, 5 );

    cout < ">>>> Create List Test";

    cout << "Result = ";
    PrintArray( t1, 0, 5, true );
    cout << "Expected = ";
    PrintArray( e1, 0, 5, true ); 
    cout << "Returned = ";
    PrintList( list, true );
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

	while( currentNode->GetNextNode() )
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

		while( iteratorNode->GetNextNode() )
		{
			ListNode* validatingNode = iteratorNode->GetNextNode();

			if( currentNode->GetData() == validatingNode->GetData() )
			{
				iteratorNode->SetNextNode( validatingNode->GetNextNode() );

				delete validatingNode;
			}
			else
			{
				iteratorNode = iteratorNode->GetNextNode();
			}
		}

		if( currentNode->GetNextNode() )
		{
			currentNode = currentNode->GetNextNode();
		}
	}
}
	
ListNode* LinkedListAlgorithms::CreateListFromArray( const int* elements, int count )
{
	ListNode* startNode = 0;
	ListNode* currentNode = 0;

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


#endif