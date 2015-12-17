#include <vector>

using namespace std;

class BucketSorting
{
    /* bucket sort is the idea to sort a group of items into smaller groups and then combining them
    at the end to get a complete sorted list
     abbd, abba, acd, abbe, ace
     |(ab) abbd, abba, abbe,| (ac) acd, ace
     |(abb?) abba, abbd,abbe | acd, ace|

    */
public:
    void TestAll( void );

private:
    /* recursiviely call bucket sort to break up the sorted items by index */
    void BucketSort( vector<string> &items, int leftIndex, int rightIndex, int sortIndex );
};

void BucketSorting::TestAll(void)
{
    vector<string> testArray;
    testArray.push_back( "acac" );
    testArray.push_back( "aba" );
    testArray.push_back( "acaa" );
    testArray.push_back( "abb" );
    testArray.push_back( "a" );
    testArray.push_back( "acaa" );
    testArray.push_back( "acab" );

    BucketSort( testArray, 0, testArray.size() - 1, 0 );
}

void BucketSorting::BucketSort(vector<string> &items, int leftIndex, int rightIndex, int sortIndex)
{
    //go through each item and sort by index [sortIndex]
    for( int i = 0; i <= rightIndex; i++ )
    {
        for( int j = 0; )
    }
}
