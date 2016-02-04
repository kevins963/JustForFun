#pragma once
#include <vector>
#include <stdlib.h>

using namespace std;

class DynamicProblems
{
    typedef struct rodCutPrice
    {
        struct rodCutPrice( int l, int p )
        {
            this->length = l;
            this->price = p;
        };

        int length;
        int price;
    } sRodCutPrices;

public:
    void TestAll( void );
protected:
private:
    void TestFindSmallestNumberCoins( void );
    int FindSmallestNumberCoins( int value );

    void TestTopcoderFlowerGarden( void );
    int* TopcoderFlowerGarden( int *heigh, int *bloom, int *wilt, int size );

    void TestMaximizeRodCut();
    int MaximizeRodCut( vector<sRodCutPrices> & rodCutPrices, int numOfCuts );

    void TestLongestSubsequenceLessThanX();
    void LongestSubsequenceLessThanX(int inputArray, int maxValue);
};


void DynamicProblems::TestAll(void)
{
    TestFindSmallestNumberCoins();
    TestMaximizeRodCut();
    //TestLongestSubsequenceLessThanX();
}

void DynamicProblems::TestFindSmallestNumberCoins(void)
{
    cout << "******** TestFindSmallestNumberCoins *********" << endl;

    vector<pair<int,int>> tests;
    tests.push_back( make_pair<int,int>( 1, 1 ) );
    tests.push_back( make_pair<int,int>( 2, 2 ) );
    tests.push_back( make_pair<int,int>( 3, 3 ) );
    tests.push_back( make_pair<int,int>( 4, 4 ) );
    tests.push_back( make_pair<int,int>( 5, 1 ) );
    tests.push_back( make_pair<int,int>( 6, 2 ) );
    tests.push_back( make_pair<int,int>( 7, 3 ) );
    tests.push_back( make_pair<int,int>( 8, 4 ) );
    tests.push_back( make_pair<int,int>( 9, 5 ) );
    tests.push_back( make_pair<int,int>( 10, 1 ) );
    for( auto itr = tests.begin(); itr != tests.end(); itr++ )
    {
        int result = FindSmallestNumberCoins( itr->first );
        cout << "input " << itr->first << " expected " << itr->second << " actual " << result << endl;
    }

}

/* 
Using dynamic programming find the smallest number of coins to equal a certain value
penny - 1
nickel - 5
dime - 10
quarter - 25

todo: use lookback array, starting from bottom up find the solution until problem is solved
runtime o(N)
space o(N*K)
N size of value
K number coins

Try each of the coins, if possible, see what is biggest
*/
int DynamicProblems::FindSmallestNumberCoins(int value)
{
    vector<int> lookupArray = vector<int>( value + 1, 0 );

    lookupArray[0] = 0;

    for( int i = 1; i <= value; i++ )
    {
        int minCoins = INT_MAX;

        minCoins = 1 + lookupArray[ i - 1 ];
        if( i >= 5 )
        minCoins = min( 1 + lookupArray[ i - 5 ], minCoins );
        if( i >= 10 )
        minCoins = min( 1 + lookupArray[ i - 10 ], minCoins );
        if( i >= 25 )
        minCoins = min( 1 + lookupArray[ i - 25 ], minCoins );

        lookupArray[i] = minCoins;
    }

    return lookupArray[value];
}

void DynamicProblems::TestTopcoderFlowerGarden(void)
{

}

/*
Flowers are planted so that none of the flowers block each others light
highest should be first if it can
bloom is the morning it will bloom
wilt is the evening it will wilt
*/
int* DynamicProblems::TopcoderFlowerGarden(int *height, int *bloom, int *wilt, int size)
{
    return 0;
}

void DynamicProblems::TestMaximizeRodCut()
{
    cout <<"*********TestMaximizeRodCut*********" <<endl;
    vector<sRodCutPrices> prices;
    prices.push_back( sRodCutPrices(2, 2 ) );
    prices.push_back( sRodCutPrices(3, 2 ) );
    prices.push_back( sRodCutPrices(5, 4 ) );
    prices.push_back( sRodCutPrices(6, 8 ) );

    vector<pair<int,int>> tests;
    tests.push_back( make_pair( 1, 0 ) );
    tests.push_back( make_pair( 2, 2 ) );
    tests.push_back( make_pair( 3, 2 ) );
    tests.push_back( make_pair( 4, 4 ) );
    tests.push_back( make_pair( 5, 4 ) );
    tests.push_back( make_pair( 6, 8 ) );
    tests.push_back( make_pair( 7, 8 ) );
    tests.push_back( make_pair( 8, 10 ) );

    for( auto itr = tests.begin(); itr != tests.end(); itr++ )
    {
        auto result = MaximizeRodCut( prices, itr->first );

        printf( "in=%d ex=%d ac=%d passed=%d\n", itr->first, itr->second, result,result == itr->second );
    }
}

/*
find the maximum profit for cutting a rod in x pieces

Best way to to us dynamic programming, bottom up approach.

Start with smallest solution and use previous maxes to current max;
try each cut if possible and look at remaining result, 

runtime O(N*P)
*/
int DynamicProblems::MaximizeRodCut(vector<sRodCutPrices> & rodCutPrices, int length )
{
    //want to include zero in price array
    vector<int> maxProfits = vector<int>( length + 1, 0 );
   //vector<int>();
    for( int curNumOfCuts = 1; curNumOfCuts < length + 1; curNumOfCuts++ )
    {
        int maxProfit = 0;

        for( auto itr = rodCutPrices.begin(); itr != rodCutPrices.end(); itr++ )
        {
            if( itr->length <= curNumOfCuts )
            {
                maxProfit =  __max( maxProfit, itr->price + maxProfits[ curNumOfCuts - itr->length ] );
            }
        }
        
        maxProfits[ curNumOfCuts ] = maxProfit;
    }

    return maxProfits[ length ];
}

void TestLongestSubsequenceLessThanX();
/*
This function will find the longest subsequence whose value is less than x

Using dynaic programming can keep the previous optimal solution, for this will
need to store the current max solution and who is is pointing to
max = 5
index =         0,  1,  2,  3,  4,  5 
array =         0,  5,  3,  2,  4,  1
current total   0   5   3   5   4   5
pointer         -   0   0   2   0   1
Total Seq       1   2   2   3   1   2
*/
void LongestSubsequenceLessThanX( int inputArray, int maxValue );
