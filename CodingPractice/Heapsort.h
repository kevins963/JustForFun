#pragma once

#include "Utilities.h"

class Heapsort
{
public:
    void Test( void );
    void Sort( int * inArray, int size );
    void Heapify( int * inArray, int size );
    void SinkDown( int * inArray, int index, int size );

    void PerculateUpMax( int * inArray, int index, int size );
    void PerculateDownMax( int * inArray, int index, int size );

	int FindKthLargestValue( int * inArray, int size, int kthValue );
};

void Heapsort::Sort( int * inArray, int size )
{
    //Convert array to unorded heap
    Heapify( inArray, size );

    //Now that array is a heap we can take the 
    //first value which is max and put swap it 
    //with the last value and then purculate down to create heap again

    for( int i = 0; i < size; i++ )
    {
        //swap max with last index
        swap( inArray[0], inArray[ size - i - 1 ] );

        //size the size to be one less and purculate down since we do not want to have the now sort max value
        //to be moved
        PerculateDownMax( inArray, 0, size - i - 1 );
    }
}

// 5 7 4
void Heapsort::Heapify( int * inArray, int size )
{
    //Turn array into a heap
    //foreach item in array "Add" it to the heap and purculate up until it is in correct place
    //Heap max heap mean all items above are greater

    for( int i = ( size / 2 ) - 1; i >= 0; i-- )
    {
        PerculateDownMax( inArray, i, size );
    }
}

void Heapsort::SinkDown( int * inArray, int index, int size )
{

}

/*
  0
1  2
34 56
  */
void Heapsort::PerculateUpMax( int * inArray, int index, int size )
{
    //Get max value of current siblings, if less than parent switch

    //case statement at root

    if( index <= 0 )
    {
        return;
    }

    int parent = ( index - 1 ) / 2;

    if( inArray[parent] < inArray[index] )
    {
        swap( inArray[parent], inArray[index] );
        PerculateUpMax( inArray, parent, size );
    }
}

void Heapsort::PerculateDownMax(int * inArray, int index, int size)
{
    //We want to put the top value in the correct place to ensure the 
    //heap property is met

    if( size <= 1 )
    {
        return;
    }

    //find max value between siblings and parent
    int maxIndex = index;
    int leftSiblingIndex = index * 2 + 1;
    int rightSiblingIndex = index * 2 + 2;
    if( inArray[maxIndex] < inArray[leftSiblingIndex] && 
        leftSiblingIndex < size )
    {
        maxIndex = leftSiblingIndex;
    }

    if( inArray[maxIndex] < inArray[rightSiblingIndex] && 
        rightSiblingIndex < size )
    {
        maxIndex = rightSiblingIndex;
    }

    if( maxIndex != index )
    {
        swap( inArray[index], inArray[maxIndex] );
        PerculateDownMax( inArray, maxIndex, size );
    }

}

int Heapsort::FindKthLargestValue( int * inArray, int size, int kthValue )
{
	//we want to make a heap of size k, we can either create new array
	//or use existing one, max heap if value is less than current max
	//swap max value with new value, and heapify

	Heapify(inArray, kthValue);

	PrintArray(inArray, 0, 20, true);

	for (int i = kthValue; i < size; i++)
	{
		if (inArray[i] < inArray[0])
		{
			//swap
			int temp = inArray[i];
			inArray[i] = inArray[0];
			inArray[0] = temp;
		}
		PerculateDownMax(inArray, 0, kthValue);

		PrintArray(inArray, 0, 20, true);
	}

	return inArray[0];
}

void Heapsort::Test(void)
{

    cout << "***********TEST HEAP SORT ********** " << endl;
	int inputArray[] = { 9,0,5,1,3,4,6,8,7,2,2,1,0,7,3,8,6,4,9,5 };
	int inputArray2[] = { 9,0,5,1,3,4,6,8,7,2,2,1,0,7,3,8,6,4,9,5 };

    Sort( inputArray, 20 );

    PrintArray( inputArray, 0, 20, true );
    

	cout << "***********TEST HEAP FIND KTH LARGEST VALUE**************" << endl;

	FindKthLargestValue(inputArray2, 20, 6);

	PrintArray(inputArray2, 0, 20, true);

}


