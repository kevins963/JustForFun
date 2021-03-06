#ifndef __SORTING_ALGORITHMS_H
#define __SORTING_ALGORITHMS_H

#include "Utilities.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct sPerson
{
    int height;
    int weight;

    sPerson( int h, int w )
    {
        height = h;
        weight = w;
    }
}
sPerson;

class SortingAlgorithms
{
public:
    void TestAll( void );
    
    void TestSortAllAnagrams( void );
    void SortAllAnagrams( string sentence );

    void TestFindValueInRotatedArray( void );
    int FindValueInRotatedArray( vector<int> inputArray, int findValue );

    void TestBuildTowerOfPeople( void );
    vector<sPerson> BuildTowerOfPeope( vector<sPerson>& poeple );
    int GetLongestListOfPeople( vector<sPerson>& people, int startIndex, int compareIndex, vector<int>& longestPath );
    static bool PersonCompare( const sPerson& p1, const sPerson& p2);

    void TestSelectionSort( void );
    void SelectionSort( vector<int> & inputArray );

    void TestInsertionSort( void );
    void InsertionSort( vector<int> & inputArray );

    void TestBubbleSort( void );
    void BubbleSort( vector<int> & inputArray );
};


void SortingAlgorithms::TestBuildTowerOfPeople( void )
{
    vector<sPerson> people;
    people.push_back( sPerson( 10, 100 ) );
    people.push_back( sPerson( 9, 90 ) );
    people.push_back( sPerson( 8, 105 ) );
    people.push_back( sPerson( 7, 70 ) );
    people.push_back( sPerson( 6, 85 ) );
    people.push_back( sPerson( 5, 50 ) );
    people.push_back( sPerson( 4, 40 ) );
    people.push_back( sPerson( 3, 30 ) );

    std::stable_sort( people.begin(), people.end(), PersonCompare );
    vector<sPerson> tower = BuildTowerOfPeope( people );

    cout << "<<<< TestBuildTowerOfPeople" << endl;

    cout << "Max Size = " << tower.size() << endl;
    for( vector<sPerson>::iterator itr = tower.begin(); itr < tower.end(); itr++ )
    {
        cout <<  "H=" << itr->height << "W=" << itr->weight << endl;
    }
}

vector<sPerson> SortingAlgorithms::BuildTowerOfPeope( vector<sPerson>& people )
{
    vector<int> longestPath = vector<int>( people.size(), -1 );
    vector<sPerson> tower;
    int maxTowerSize = 0;
    int maxTowerSizeIndex = 0;
    for( int i = 0; i < longestPath.size(); i++ )
    {
        if( longestPath[i] == -1 )
        {
            int towerSize = GetLongestListOfPeople( people, i, i, longestPath );

            if( towerSize > maxTowerSize )
            {
                maxTowerSize = towerSize;
                maxTowerSizeIndex = i;
            }
        }
    }

    /* Create tower */

    for( int i = maxTowerSizeIndex; i < people.size(); i++ )
    {
        if( tower.size() == 0 )
        {
            tower.push_back( people[i] );
        }
        else
        {
            if( PersonCompare( tower.back(), people[i] ) )
            {
                tower.push_back( people[i] );
            }
        }
    }

    return tower;

}

int SortingAlgorithms::GetLongestListOfPeople( vector<sPerson>& people, int startIndex, int compareIndex, vector<int>& longestPath )
{
    int value;

    if( compareIndex >= people.size())
    {
        return 0;
    }

    if( PersonCompare( people[startIndex], people[compareIndex] ) )
    {
        /* correct order */

        if( longestPath[compareIndex] == -1 )
        {
            longestPath[compareIndex] = 1 + GetLongestListOfPeople( people, compareIndex, compareIndex + 1, longestPath );
        }
        
        return longestPath[compareIndex];
    }

    return GetLongestListOfPeople( people, compareIndex, compareIndex + 1, longestPath );
}

bool SortingAlgorithms::PersonCompare( const sPerson& p1, const sPerson& p2)
{
    if( p1.height > p2.height && p1.weight > p2.weight)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void SortingAlgorithms::TestAll()
{
    TestSortAllAnagrams();
    TestFindValueInRotatedArray();
    TestBuildTowerOfPeople();
    TestSelectionSort();
    TestInsertionSort();
    TestBubbleSort();
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

void SortingAlgorithms::TestSelectionSort( void )
{
    int testArray[] = {6,1,5,8,0,7,4,9,3,2};

    vector<int> testVector(testArray, testArray + 10);

    cout << "**************TEST SELECTION SORT*****************" << endl;

    cout << "Input = ";
    PrintArray( testVector, true );

    SelectionSort( testVector );
    cout << "Output = ";
    PrintArray(testVector, true);
}

/*
Find the smallest item in the array and put in current position

Aux = 0
Runtime = n^2
*/
void SortingAlgorithms::SelectionSort( vector<int> & inputArray )
{
    for( int i = 0; i < inputArray.size() - 1; i++ )
    {
        int minIndex = i;
        
        for ( int j = i + 1; j < inputArray.size(); j++ )
        {
            if( inputArray[j] < inputArray[minIndex] )
            {
                minIndex = j;
            }
        }

        if( minIndex != i )
        {
            int temp = inputArray[minIndex];
            inputArray[minIndex] = inputArray[i];
            inputArray[i] = temp;
        }
    }
}

void SortingAlgorithms::TestInsertionSort( void )
{
    int testArray[] = {6,1,5,8,0,7,4,9,3,2};

    vector<int> testVector(testArray, testArray + 10);

    cout << "**************TEST Insertion SORT*****************" << endl;

    cout << "Input = ";
    PrintArray( testVector, true );

    InsertionSort( testVector );
    cout << "Output = ";
    PrintArray(testVector, true);
}

/*
increase index by one and go from highest to lowest until new index is in correct place

for i = 1
for j = i -> j--
  while j < j-1 
    swap

Aux = 0
Runtime = n^2
*/
void SortingAlgorithms::InsertionSort( vector<int> & inputArray )
{
    for( int i = 1; i < inputArray.size(); i++ )
    {

        for ( int j = i; j > 0; j-- )
        {
            while( inputArray[j] < inputArray[j-1])
            {
                int temp = inputArray[j];
                inputArray[j] = inputArray[j-1];
                inputArray[j-1] = temp;
            }
        }
    }
}


void SortingAlgorithms::TestBubbleSort( void )
{
    int testArray[] = {6,1,5,8,0,7,4,9,3,2};

    vector<int> testVector(testArray, testArray + 10);

    cout << "**************TEST BUBBLE SORT*****************" << endl;

    cout << "Input = ";
    PrintArray( testVector, true );

    BubbleSort( testVector );
    cout << "Output = ";
    PrintArray(testVector, true);
}

/*
compare each item in array to adjacent until no more swaps needed, highest is always taken to top


for i = arraysize -> 0, i--
for j = 0 -> i - 1, j++
    if( array[j] > array[j+1])
        swap

Aux = 0
Runtime = n^2
*/
void SortingAlgorithms::BubbleSort( vector<int> & inputArray )
{
    bool swapped = true;

    for( int i = inputArray.size(); i > 0 && swapped; i-- )
    {
        swapped = false;

        for ( int j = 0; j < i - 1; j++ )
        {
            if( inputArray[j] > inputArray[j+1])
            {
                int temp = inputArray[j];
                inputArray[j] = inputArray[j+1];
                inputArray[j+1] = temp;
                
                swapped = true;
            }
        }
    }
}
#endif
