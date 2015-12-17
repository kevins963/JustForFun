#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class BucketSort
{
public:
    void TestAll( void );

    void TestSort( void );
    void Sort( vector<int> data, int maxValue, int radix );
private:
};

void BucketSort::TestAll( void )
{
    cout << dec;
    TestSort();
}

void BucketSort::TestSort( void )
{
    int t1[] = {1,45,23,2,423,56,4,23,8,29};
    vector<int> v1( t1, t1 + sizeof(t1) / sizeof( t1[0] ) );

    Sort( v1, 65, 0 );
}

void BucketSort::Sort( vector<int> data, int maxVal, int radix ) 
{
    vector<int> bucket( data.size(), 0 );
    
    int count[10] = {0};
    int bucketCount[10] = {0};

    
    int N = (radix == 0) ? 1 : radix * 10;

    for( int i = 0; i < data.size(); i++ )
    {
        int index = ( data[i] / N ) % 10 ;
        count[ index ]++;
    }

    for( int i = 1; i < data.size(); i++ )
    {
        int total = 0;
        //count[i] += total count[i-1];
    }

    for( int i = 0; i < data.size(); i++ )
    {
        int index = ( data[i] / N ) % 10 ; 

        cout << "data = " << data[i] << " " << bucketCount[index] << " + " << count[index] << " = " << bucketCount[index] + count[index] << endl; 
        bucket[ bucketCount[index] + count[index] - 1 ] = data[i];
        bucketCount[index]++;
    }
}



#endif