#include <vector>

using namespace std;

class SelectionAlgorithms
{
public:
    void TestAll( void );

private:
    void TestQuickSelection( void );
    int QuickSelection( int* inArray, int kthMinValue, int leftIndex, int rightIndex );
    int QuickSelectionPivotSort( int* inArray, int leftIndex, int rightIndex, int indexToPivot );
};

void SelectionAlgorithms::TestAll( void )
{
    TestQuickSelection();
}

struct quick_selection_item
{
    quick_selection_item( int expected, int kthValue, vector<int> inArray )
    {
        this->expected = expected;
        this->kthValue = kthValue;
        this->inArray = inArray;
    }

    int expected;
    int kthValue;
    vector<int> inArray;
};
void SelectionAlgorithms::TestQuickSelection( void )
{
    cout <<  "***************TESTING TestQuickSelection***************" << endl;
    vector< struct quick_selection_item > quickSelectItems;
    int testArray[] = {1,2,3,4,5};
    quickSelectItems.push_back( struct quick_selection_item( 5, 5, vector<int>() ));

    vector<int> newArray;
    for(int i = 0; i < 100; i++)
    {
        int newValue = rand() % 1000 + 10;
        newArray.push_back( newValue );
    }

    for( int i = 0; i < 5; i++ )
    {
        int newIndex = rand() % newArray.size();
        newArray.insert( newArray.begin() + newIndex, testArray[i] );
    }

   
    int result = QuickSelection( newArray.data(), 5, 0, newArray.size() - 1 );

    cout << "Result = " << result << " expected = " << quickSelectItems[0].expected << endl;
}

/*
Quick Selection taken from QuickSort to find kth value
- Randomly select value (pivot point) and all min values on left, max on right of pivot point
- if left side is less than k values chose random from that side else from other side until (k - 1) values on left
*/
int SelectionAlgorithms::QuickSelection( int* inArray, int kthMinValue, int leftIndex, int rightIndex )
{
    //Choose random value, just do last   
    if( leftIndex == rightIndex )
    {
        return -1;
    }

    //Just choose middle value
    int pivotIndex = QuickSelectionPivotSort( inArray, leftIndex, rightIndex, ( leftIndex + rightIndex ) / 2 );

    if( kthMinValue == ( pivotIndex + 1 ) )
    {
        return inArray[pivotIndex];
    }

    if( kthMinValue < ( pivotIndex + 1 ) )
    {
        return QuickSelection( inArray, kthMinValue, leftIndex, pivotIndex - 1 );
    }
    else
    {
        return QuickSelection( inArray, kthMinValue, pivotIndex + 1, rightIndex );
    }
}

//int SelectionAlgorithms::QuickSelection( int* inArray, int size, int kthMinValue )
//{
//    //Choose random value, just do last
//    int pivotIndex = -1;
//
//    int leftIndex = 0;
//    int rightIndex = size - 1;
//
//    while( pivotIndex != kthMinValue - 1)
//    {
//        pivotIndex = QuickSelectionPivotSort( inArray, size, leftIndex, rightIndex );
//
//        if( ( kthMinValue - 1 ) < pivotIndex)
//        {
//            rightIndex = pivotIndex - 1;
//        }
//        else
//        {
//            leftIndex = pivotIndex + 1;
//        }
//    }
//
//    return inArray[pivotIndex];
//}

int SelectionAlgorithms::QuickSelectionPivotSort( int* inArray, int leftIndex, int rightIndex, int indexToPivot )
{
    //Put all values less than pivotIndex to left all else to right
	//Put pivit in last index
    int temp = inArray[indexToPivot];
    inArray[indexToPivot] = inArray[rightIndex];
    inArray[rightIndex] = temp;
    
    //put pivot value to end
    int pivotIndex = leftIndex;

    for( int i = leftIndex; i < rightIndex; i++ )
    {
        if( inArray[i] < inArray[rightIndex] )
        {
            int temp = inArray[pivotIndex];
            inArray[pivotIndex] = inArray[i];
            inArray[i] = temp;

            pivotIndex++;
        }
    }

    temp = inArray[pivotIndex];
    inArray[pivotIndex] = inArray[rightIndex];
    inArray[rightIndex] = temp;

    return pivotIndex;
    
}



