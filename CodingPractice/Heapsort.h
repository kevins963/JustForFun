#pragma once

#include "Utilities.h"

class Heapsort
{
public:
    void Sort( int * inArray, int size );
    void Heapify( int * inArray, int size );
    void SinkDown( int * inArray, int index, int size );
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

void Heapsort::Heapify( int * inArray, int size )
{
    int i, j, k, v, heap;

    for( int i = size / 2; i >= 1; i-- )
    {
        k = i;
        v = inArray[k];
        heap = 0;

        while( heap == 0 && ( 2*k ) <= size )
        {

            j = 2 * k;
         
            if ( j < size )
            {
                if( inArray[j] < inArray[j+1] )
                {
                    j++;
                }
            }

            if( v >= inArray[j] )
            {
                heap = 1;
            }
            else
            {
                inArray[k] = inArray[j];
                k = j;
            }
        }

        inArray[k] = v;
    }
}

void Heapsort::SinkDown( int * inArray, int index, int size )
{

}

