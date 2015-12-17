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
    void TestAddNumbersTogether( void );

    ListNode* FindNthElementFromEnd( ListNode* list, int nthFromEnd );
    void RemoveDuplicates( ListNode* list );
    ListNode* AddNumbersTogether( ListNode* node1, ListNode* node2 );

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
    TestAddNumbersTogether();
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


void LinkedListAlgorithms::TestCreateList( void )
{
    int t1[] = {1, 2, 3, 4, 5};
    int e1[] = {1, 2, 3, 4, 5};

    ListNode* list = CreateListFromArray( t1, 5 );

    cout << ">>>> Create List Test";

    cout << "Result = ";
    PrintArray( t1, 0, 5, true );
    cout << "Expected = ";
    PrintArray( e1, 0, 5, true ); 
    cout << "Returned = ";
    PrintList( list, true );
}

void LinkedListAlgorithms::TestAddNumbersTogether( void )
{
    int ta1[] = {9,6};
    int tb1[] = {1,8};
    int e1[] = {0,5,1};
    ListNode* na1 = CreateListFromArray( ta1, sizeof( ta1) / sizeof( int ) );
    ListNode* nb1 = CreateListFromArray( tb1, sizeof( tb1) / sizeof( int ) );

    cout << "<<<< Test Add Numbers Together" << endl;

    ListNode* result = AddNumbersTogether( na1, nb1 );

    cout << "Test     = ";
    PrintArray( ta1, 0, sizeof( ta1 ) / sizeof( int ), false );
    cout << " + " ;
    PrintArray( tb1, 0, sizeof( tb1 ) / sizeof( int ), true );
    cout << "Expected = ";
    PrintArray( e1, 0, sizeof( e1 ) / sizeof( int ), true );
    cout << "Results  = ";
    PrintList( result, true );
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

/*
* Create function that take in two linked list each representing a number and add them together.
* The numbers are stored in reversed order
*Ex:345+456 -> {5,4,3}+{6,5,4} = {1,0,8} -> 801
* Go through each number and add them together keeping the carry over
*/
ListNode* LinkedListAlgorithms::AddNumbersTogether( ListNode* node1, ListNode* node2 )
{
    ListNode* head = 0;
    ListNode* sum = 0;
    int carryOver = 0;
    int value1 = 0;
    int value2 = 0;

    /* Go through each number */
    while( node1 || node2 )
    {
        if( node1 )
        {
            value1 = node1->GetData();
            node1 = node1->GetNextNode();
        }

        if( node2 )
        {
            value2 = node2->GetData();
            node2 = node2->GetNextNode();
        }

        if( !sum )
        {
            sum = new ListNode( ( value1 + value2 ) % 10 );
            head = sum;
        }
        else
        {
            sum->SetNextNode( new ListNode( ( value1 + value2 ) % 10 + carryOver ) );
            sum = sum->GetNextNode();
        }

        carryOver = ( value1 + value2  >= 10 ) ? 1 : 0;
        value1 = 0;
        value2 = 0;
    }

    if( carryOver ) 
    {
        sum->SetNextNode( new ListNode( carryOver ) );
        sum = sum->GetNextNode();
    }

    return head;
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