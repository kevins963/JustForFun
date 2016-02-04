#pragma once

#include <vector>
#include <iostream>

using namespace std;

class PascalsTriangle
{
    public:
    void Test();

    vector<int> PascalsTriangle::getRow( int A );
    vector<int> CreatePascalsRecursive( int rows );
    vector<int> PascalsTriangle::PascalsRecursive( vector<int> & pascalsTriangle, int indexLeft, int indexRight );

 
};

void PascalsTriangle::Test()
{
    cout << "PascalsTriangle" << endl;

    for( int i = 0; i < 10; i++ )
    {
        auto row = getRow( i );

        for( int j = 0; j <= i; j++ )
        {
            cout << row[j] << " ";
        }

        cout << endl;
    }
}

vector<int> PascalsTriangle::getRow( int A )
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int size = A + 1;

    vector<int> arrayOut = vector<int>( size, 0 );

    int curVal0, curVal1;
    arrayOut[ 0 ] = 1;

    for( int i = 1; i < arrayOut.size(); i++ )
    {
        curVal0 = 0;
        curVal1 = 0;

        for( int j = 0; j <= i / 2; j++ )
        {
            curVal0 = curVal1;
            curVal1 = arrayOut[ j ];

            arrayOut[ j ] = curVal0 + curVal1;
            arrayOut[ i - j ] = curVal0 + curVal1;
        }

    }

    return arrayOut;
}


vector<int> PascalsTriangle::CreatePascalsRecursive( int rows )
{

    //create vector with correct number of rows;
    int cellCount = 0;
    for( int i = 0; i < rows; i++ )
    {
        cellCount += (i+1);
    }
    
    vector<int> pascalsTriangle( cellCount, 0 );

    PascalsRecursive( pascalsTriangle, 0, -1 );
}

vector<int> PascalsTriangle::PascalsRecursive( vector<int> )
{

}