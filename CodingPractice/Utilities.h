#pragma once

#include <iostream>
#include "ListNode.h"

using namespace std;

void PrintArray( int * someArray, int start, int length, char newline );
void PrintList( ListNode* list, bool newLine );

void PrintArray( int * someArray, int start, int length, char newline )
{
    cout << "[";

    for( int i = start; i < start + length; i++ )
    {
        cout << someArray[i] << ",";
    }

    cout << "]";

    if(newline)
        cout << endl;
}

void PrintList( ListNode* list, bool newLine )
{
    ListNode* printNode = list;

    cout << "[";

    while( printNode != 0 )
    {
        cout << printNode->GetData() << ",";
        printNode = printNode->GetNextNode();
    }

    cout << "]";

    if( newLine )
    {
        cout << endl;
    }
}