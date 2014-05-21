#pragma once

#include <deque>
#include <iostream>
using namespace std;

/*
Recursivly split array into two
Combine two arrays into sorted array
*/

class MergeSort
{
public:
	MergeSort( ){}
	~MergeSort(){}

	deque<int> Sort( deque<int> inputArray )
	{
		if(inputArray.size() > 1)
		{
			deque<int> sortedArray1;
			deque<int> sortedArray2;

			int halfwayIndex = ( inputArray.size() / 2 );

			deque<int> arrayFirst;
			deque<int> arraySecond;

			
			for(int i = 0; i < inputArray.size(); i++)
			{
				if( i < halfwayIndex )
				{
					arrayFirst.push_back( inputArray[i] );
				}
				else
				{
					arraySecond.push_back( inputArray[i] );
				}
			}
			
			sortedArray1 = Sort( arrayFirst);
			sortedArray2 = Sort( arraySecond);
			cout << "Pre: ";
			Print( sortedArray1 );
			Print( sortedArray2 );
			cout << "\n ";
			deque<int> mergedArray = Merge(sortedArray1, sortedArray2);

			cout << "Post: ";
			Print( mergedArray );
			cout << "\n";

			return mergedArray;
			
		}
		else
		{
			return inputArray;
		}
		

	}
private:

	deque<int> Merge( deque<int> array1, deque<int> array2 )
	{
		deque<int> mergedArray;

		while(array1.size() > 0 && array2.size() > 0)
		{
			if( array1.front() < array2.front() )
			{
				mergedArray.push_back(array1.front());
				array1.pop_front();
			}
			else
			{
				mergedArray.push_back(array2.front());
				array2.pop_front();
			}
		}

		while(array1.size() > 0 )
		{

			mergedArray.push_back(array1.front());
			array1.pop_front();
		}

		while(array2.size() > 0 )
		{

			mergedArray.push_back(array2.front());
			array2.pop_front();
		}

		return mergedArray;
	}

	void Print( deque<int> &data )
	{
		cout << "{";
		for( int i = 0; i < data.size(); i++ )
		{
			cout << data[i] << ", ";
		}
		cout << "}";
	}
};
