#pragma once

#include <iostream>
#include "ListNode.h"
#include <vector>

using namespace std;

int GetMatrixIndex( int row, int col, int maxCol ); 
void PrintArray( int * someArray, int start, int length, char newline );
void PrintArray( vector<int>& v1, bool newLine );
void PrintList( ListNode* list, bool newLine );
void PrintMatrix( int* matrix, int width, int height );

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

void PrintArray( vector<int>& v1, bool newline )
{
    cout << "[";

    for( int i = 0; i < v1.size(); i++ )
    {
        cout << v1[i] << ",";
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

void PrintMatrix( int* matrix, int width, int height )
{

    for( int i = 0; i < width; i++ )
    {
        cout << "[";

        for( int j = 0; j < height; j++ )
        {
            cout << matrix[GetMatrixIndex( i, j, width)] << ",";
        }
        cout << "]";
        cout << endl;

    }
    cout << endl;
}

int GetMatrixIndex( int row, int col, int maxCol )
{
    return row + col * maxCol;
}
