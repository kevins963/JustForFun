#pragma once

#include <iostream>

using namespace std;


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