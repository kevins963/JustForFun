#ifndef __SORTING_ALGORITHMS_H
#define __SORTING_ALGORITHMS_H

#include "Utilities.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SortingAlgorithms
{
public:
	void TestAll( void );
	
	void TestSortAllAnagrams( void );
	void SortAllAnagrams( string sentence );

	void TestFindValueInRotatedArray( void );
	int FindValueInRotatedArray( vector<int> inputArray, int findValue );
};

void SortingAlgorithms::TestAll()
{
	TestSortAllAnagrams();
	TestFindValueInRotatedArray();
}

void SortingAlgorithms::TestSortAllAnagrams( void )
{	 
	string t1( "jlk dfe cab nmo igh" );
	string e1( "abc def ghi jkl mno" );
}

void SortingAlgorithms::SortAllAnagrams( string inputString )
{
}


void SortingAlgorithms::TestFindValueInRotatedArray( void )
{
    int findValue = 5;

    int t0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int t1[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 1};
    int t2[] = { 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
    int t3[] = { 4, 5, 6, 7, 8, 9, 10, 1, 2, 3};
    int t4[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int t5[] = { 6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    int t6[] = { 7, 8, 9, 10, 1,2, 3, 4, 5, 6 };
    int t7[] = { 8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    int t8[] = { 9, 10, 1, 2, 3, 4, 5, 6, 7, 8};
    int t9[] = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int t10[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int t11[] = { 2, 3, 4, 5, 6, 7, 8, 9, 1};
    int t12[] = { 3, 4, 5, 6, 7, 8, 9, 1, 2};
    int t13[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3};
    int t14[] = { 5, 6, 7, 8, 9, 1, 2, 3, 4};
    int t15[] = { 6, 7, 8, 9, 1, 2, 3, 4, 5};
    int t16[] = { 7, 8, 9, 1,2, 3, 4, 5, 6 };
    int t17[] = { 8, 9, 1, 2, 3, 4, 5, 6, 7};
    int t18[] = { 9, 1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> v0( t0, t0 + sizeof( t0 ) / sizeof( t1[0] ) );
    vector<int> v1( t1, t1 + sizeof( t1 ) / sizeof( t1[1] ) );
    vector<int> v2( t2, t2 + sizeof( t2 ) / sizeof( t1[2] ) );
    vector<int> v3( t3, t3 + sizeof( t3 ) / sizeof( t1[3] ) );
    vector<int> v5( t5, t5 + sizeof( t5 ) / sizeof( t1[5] ) );
    vector<int> v6( t6, t6 + sizeof( t6 ) / sizeof( t1[6] ) );
    vector<int> v7( t7, t7 + sizeof( t7 ) / sizeof( t1[7] ) );
    vector<int> v8( t8, t8 + sizeof( t8 ) / sizeof( t1[8] ) );
    vector<int> v9( t9, t9 + sizeof( t9 ) / sizeof( t1[9] ) );
    
    int e0 = 4;
    int e1 = 3;
    int e2 = 2;
    int e3 = 1;
    int e4 = 0;
    int e5 = 9;
    int e6 = 8;
    int e7 = 7;
    int e8 = 6;
    int e9 = 5;
    int e10 = 4;
    int e11 = 3;
    int e12 = 2;
    int e13 = 1;
    int e14 = 0;
    int e15 = 8;
    int e16 = 7;
    int e17 = 6;
    int e18 = 5;

    int * t[] = {t0, t1, t2, t3, t4, t5, t6, t7, t8, t9 };
    int e[] = {e0, e1, e2, e3, e4, e5, e6, e7, e8, e9 };

    int * tt[] = {t10, t11, t12, t13, t14, t15, t16, t17, t18 };
    int ee[] = {  e10, e11, e12, e13, e14, e15, e16, e17, e18 };


    cout << "<<<< TestFindValueInRotatedArray" << endl;

    for( int i = 0; i < sizeof( t ) / sizeof( t[0]); i++ )
    {
        vector<int> v( t[i], t[i] + sizeof( t0 ) / sizeof( t1[0] ) );
        cout << "expected = " << e[i] << endl;
        cout << "result   = " << FindValueInRotatedArray( v, findValue ) << endl;
    }

    for( int i = 0; i < sizeof( tt ) / sizeof( tt[0]); i++ )
    {
        vector<int> v( tt[i], tt[i] + sizeof( t10 ) / sizeof( t10[0] ) );
        cout << "expected = " << ee[i] << endl;
        cout << "result   = " << FindValueInRotatedArray( v, findValue ) << endl;
    }


}

/*
Find an item in an array that has been rotated, assuming integers are insertedin increasing order.
Runtime should be log(n)

Ex [15 16 19 20 25 1 3 4 5 7 10 14], find 5
Output = 8

With sorted array we can do a binary search to get log(n)
We can still do it if we modify the algorithm

15 16 19 20 25 1 3 4 5 7 10 14
Sorted array we know left > right, if left < right we know rotated 

Find left so that < find value, find right > value
L=1,15 -> L = (size - L) / 2 => L=6, 1
Now find L so that L[i] <


*/ 

int SortingAlgorithms::FindValueInRotatedArray( vector<int> inputArray, int findValue )
{
    int leftIndex, rightIndex, midIndex;

    leftIndex = 0;
    rightIndex = inputArray.size();
    midIndex = (rightIndex - leftIndex) / 2;

    while(  inputArray[midIndex] != findValue && 
            leftIndex != rightIndex )
    {
        if( inputArray[ midIndex ] > findValue )
        {
            if( inputArray[ leftIndex ] > inputArray[ midIndex ] )
            {
                leftIndex = midIndex;
            }
            else
            {
                rightIndex = midIndex;
            }
        }
        else
        {
            leftIndex = midIndex;
        }

        midIndex = ( rightIndex + leftIndex) / 2;
    }

    if( inputArray[ midIndex ] == findValue )
    {
        return midIndex;
    }

    return -1;
}

#endif
