#pragma once

#include "Utilities.h"

class Heapsort
{
public:
    void Sort( int * inArray, int size );
    void Heapify( int * inArray, int size );
    void SinkDown( int * inArray, int index, int size );

	void PerculateUpMax( int * inArray, int index, int size );
};

void Heapsort::Sort( int * inArray, int size )
{
    int temp, i;
    for ( i = size -1; i >= 1; i-- )
    {
		PrintArray( inArray, 0, size, true );
        Heapify( inArray, i );
        temp = inArray[1];
        inArray[1] = inArray[i];
        inArray[i] = temp;
    }
	
	PrintArray( inArray, 0, size, true );

}

// 5 7 4
void Heapsort::Heapify( int * inArray, int size )
{
    //Turn array into a heap
	//foreach item in array "Add" it to the heap and purculate up until it is in correct place
	//Heap max heap mean all item below are great value

	for( int i = 0; i < size; i++ )
	{
		PerculateUpMax( inArray, i, size );
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

	if( index == 0 )
	{
		return;
	}

	int parent = ( index - 1 ) / 2;

	if( inArray[parent] > inArray[index] )
	{
		swap( inArray[parent], inArray[index] );
		PerculateUpMax( inArray, parent, size );
	}
}
