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
	bool switched;
	int prevValue;
	int currentIndex = 0;

	prevValue = findValue;

	switched = ( prevValue > inputArray[currentIndex] ) ? true : false;
	
	while
}

#endif
