#pragma once

#include "ListNode.h"
#include <string>
#include <iostream>
/*

1. new list set entry node to zero
2. sorted insert 
  
  2.0 
  if current list is null set as null with self being next 
  2.1 inserting into middle of list
  if next node >= and current node <= insert new node
  [4]
  3 4 5 6 1 2 

*/

using namespace std;

class CyclicList
{
public:
    CyclicList(void)
    {
        _pList = nullptr;
    }

    ~CyclicList(void)
    {
        //Delete All
    };

public:

    void Insert( int value )
    {
        ListNode * pNewNode = new ListNode( value );

        ListNode * pCurrentNode;

        
        // 2.0 - Check if list is empty
        if(_pList == nullptr)
        {
            _pList = pNewNode;
            _pList->SetNextNode(_pList);
            return;
        }
        //2.1 find when value is between go until reaching beginning
        else
        {
            pCurrentNode = _pList;

            do
            {
                // 5,4
                if( ( pCurrentNode->GetData() > pCurrentNode->GetNextNode()->GetData() ) && 
                    ( pCurrentNode->GetNextNode()->GetData() >= pNewNode->GetData() )
                    )
                {
                    pNewNode->SetNextNode( pCurrentNode->GetNextNode() );
                    pCurrentNode->SetNextNode( pNewNode );
                    return;
                }
                else if( ( pCurrentNode->GetData() < pNewNode->GetData() ) && 
                    ( pCurrentNode->GetNextNode()->GetData() >= pNewNode->GetData() )
                    )
                {
                    // [x]->[z], [y]->[z], [x]->[y], x->y->z
                    pNewNode->SetNextNode( pCurrentNode->GetNextNode() );
                    pCurrentNode->SetNextNode( pNewNode );
                    return;
                }
                else if( pCurrentNode->GetNextNode() == _pList )
                {
                    // [x]->[z], [y]->[z], [x]->[y], x->y->z
                    // x -> z y ->
                    
                    pNewNode->SetNextNode( pCurrentNode->GetNextNode() );
                    pCurrentNode->SetNextNode( pNewNode );

                    return;
                }

            }
            while( pCurrentNode = pCurrentNode->GetNextNode() );
        }
    }

    void PrintData()
    {
        char tempString[250];
        int pos = 0;

        ListNode * currentNode = _pList;

        do
        {
            pos += sprintf_s((tempString+pos), 250 - pos, "%d, ", currentNode->GetData());

            currentNode = currentNode->GetNextNode();
        }
        while( currentNode != _pList );

        pos += sprintf_s((tempString+pos), 250 - pos, "\n\n ");

        cout << tempString;
    }

private:

    ListNode * _pList; 
};

