#pragma once
#include "Utilities.h"
/*
recursively sort all items so all items
lower the the pivot point are on one side
and all items higher than pivot point on the other

9, 1, 4, 2, 6
l           h
fh=0 i=0 n

1, 9, 5, 2, 6
f  i y

1, 5, 9, , 2, 6
   f  i y

1, 5, 2, 9, 6
      f     i y

1, 5, 2, 6, 9 
         f  i y
QS
1. Sort items around pivot point
2. QS lower half
3. QS upper half
*/
class QuickSort
{
public:
    QuickSort() {};
    ~QuickSort() {};

public:
    void Sort( int* array, int start, int end );
    int Pivot( int* array, int start, int end );
    void Swap( int* array, int index1, int index2 );
};

void QuickSort::Sort( int* array, int start, int end )
{
    /* check size, pivot, sort lower, sort upper */

    if( end - start > 0 )
    {
        PrintArray( array, start, end - start + 1, true );

        int pivotIndex = Pivot( array, start, end );

        Sort( array, start, pivotIndex - 1 );
        Sort( array, pivotIndex + 1, end );

        PrintArray( array, start, end - start + 1, true );
    }

}

int QuickSort::Pivot( int* array, int start, int end )
{
    /* go through entire array and put items lower then end at beginning */

    int pivot = start;
    int i;
    
    for( i = start; i < end; i++ )
    {
        if( array[i] < array[end] )
        {
            Swap( array, pivot, i );
            pivot++;
        }
    }

    Swap( array, pivot, end );

    return pivot;
}

void QuickSort::Swap( int* array, int index1, int index2 )
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

