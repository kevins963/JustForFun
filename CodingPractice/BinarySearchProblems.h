#pragma once
#include <vector>
#include <iostream>

using namespace std;
class BinarySearchProblems
{
public:
    void TestAll();

private:
    void TestIsValueInSortedArray();
    int IsValueInSortedArray( vector<int> & someArray, int findValue );


    void TestFindIndexOfFirstOccuranceSortedArray();
    int FindIndexOfFirstOccuranceSortedArray( vector<int> & someArray, int findValue );
};

void BinarySearchProblems::TestAll()
{
    TestIsValueInSortedArray();
    TestFindIndexOfFirstOccuranceSortedArray();
}

void BinarySearchProblems::TestIsValueInSortedArray()
{
    cout << "******* BINARY SEARCH TEST: TEST IS VALUE IN SORTED ARRAY" << endl;
    int arrayEven[] = {2, 4, 6, 8, 10, 12, 14, 16};

    vector<int> testArrayEven = vector<int>( &arrayEven[0], &arrayEven[7] + 1 );
    vector<pair<int,int>> tests;

    tests.push_back( make_pair( 2, 0 ) );
    tests.push_back( make_pair( 4, 1) );
    tests.push_back( make_pair( 6, 2) );
    tests.push_back( make_pair( 8, 3) );
    tests.push_back( make_pair( 10, 4) );
    tests.push_back( make_pair( 12, 5) );
    tests.push_back( make_pair( 14, 6) );
    tests.push_back( make_pair( 16, 7) );
    tests.push_back( make_pair( 0, -1) );
    tests.push_back( make_pair( 17, -1) );
    tests.push_back( make_pair( 13, -1) );
    tests.push_back( make_pair( 3, -1) );

    for( auto itr = tests.begin(); itr != tests.end(); itr++ )
    {
        auto result = IsValueInSortedArray( testArrayEven, itr->first );
        printf( "in=%d, exp=%d, result=%d, pass=%d\n", itr->first, itr->second, result, result == itr->second );
    }

}

/*
binary search we look at low, high and mid.  Compare find value to mid
if lower adjust high, if greater adjust low.  High should be 1 less than mid
and low should move to +1 of mid since actual mid value has already be tested
1 + (5-1)/2 = 1+ 2 = 3
1+5/2 = 3
0 + (5-0) = 2.5 = 2

*/
int BinarySearchProblems::IsValueInSortedArray(vector<int> & someArray, int findValue)
{
    int low = 0;
    int high = someArray.size() - 1;
	int mid;// = (high + low) / 2;

    while( high >= low )
    {

		mid = (low + high) / 2;
		
		//found
        if( someArray[mid] == findValue )
        {
            return mid;
        }

        //between mid and low
        else if( someArray[mid] > findValue )
        {
            high = mid - 1;
        }

        // between mid and high
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

void BinarySearchProblems::TestFindIndexOfFirstOccuranceSortedArray()
{

    cout << "******* BINARY SEARCH TEST: TEST IS VALUE IN SORTED ARRAY" << endl;
    int arrayEven[] = { 2, 2, 2, 2, 3, 4, 4 ,4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };

    vector<int> testArrayEven = vector<int>( &arrayEven[0], &arrayEven[27] + 1 );
    vector<pair<int,int>> tests;

    tests.push_back( make_pair( 2, 0 ) );
    tests.push_back( make_pair( 3, 4) );
    tests.push_back( make_pair( 4, 5) );
    tests.push_back( make_pair( 5, 8 ) );
    
    for( auto itr = tests.begin(); itr != tests.end(); itr++ )
    {
        auto result = FindIndexOfFirstOccuranceSortedArray( testArrayEven, itr->first );
        printf( "in=%d, exp=%d, result=%d, pass=%d\n", itr->first, itr->second, result, result == itr->second );
    }

}

/*
use binary search, whenever m == value save index, and set upper index
*/
int BinarySearchProblems::FindIndexOfFirstOccuranceSortedArray(vector<int> & someArray, int findValue)
{
    int l=0;
    int r=someArray.size() - 1;
    int m;

    int valueIndex = -1;

    while( l <= r )
    {
        m = l + (r - l) / 2;

        if( someArray[m] == findValue )
        {
            valueIndex = m;
            r = m - 1;
        }
        else if( someArray[m] < findValue )
        {
            l = m + 1;
        }
        else if( someArray[m] > findValue )
        {
            r = m - 1;
        }
    }

    return valueIndex;

}
