#ifndef __CODE_CHEF_H
#define __CODE_CHEF_H

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;


class CodeChef
{

public:
    typedef struct knapsackItem
    {
        int weight;
        int cost;
    } sKnapsackItem;

public:
    void TestAll( void );

    void TestFindNextPalindroneNumber( void );
    int FindNextPalindroneNumber( int num );

    void TestFindMaxKnapsackCost( void );
    vector<sKnapsackItem> FindMaxKnapsackCost( int maxWeight );
};

void CodeChef::TestAll( void )
{
    TestFindNextPalindroneNumber();
    TestFindMaxKnapsackCost();
}

void CodeChef::TestFindNextPalindroneNumber( void )
{
    int test[] = {808, 2133, 12300};
    int expected[] = {818, 2222, 12321};

    cout << "********** TEST NEXT PALINDRONE NUMBER***********" << endl;

    for( int i = 0; i < sizeof(test) / sizeof(int); i++)
    {
        cout << "input = " << test[i] << " expected = " << expected[i] << " result = " << FindNextPalindroneNumber( test[i] ) << endl;
    }
}

/*
Find the next smallest palindrone number (number that is same when backwards, 818, 222, 1221)
*/
int CodeChef::FindNextPalindroneNumber( int num )
{

    int currentNumber = num;
    int tempNumber;;
    int reversed = 0;

    do
    {
        currentNumber++;
        tempNumber = currentNumber;
        reversed = 0;

        while( tempNumber != 0 )
        {
            reversed = (reversed * 10) + tempNumber % 10;
            tempNumber = (tempNumber/10);
        }
    }
    while(currentNumber != reversed);

    return currentNumber;
}

void CodeChef::TestFindMaxKnapsackCost( void )
{

}

vector<CodeChef::sKnapsackItem> CodeChef::FindMaxKnapsackCost( vector<CodeChef::sKnapsackItem> items, int maxWeight )
{
    std::sort( items.begin(), items.end(), SortKnapsackItem );
}

bool SortKnapsackItem( const CodeChef::sKnapsackItem & item1, const CodeChef::sKnapsackItem & item2 )
{
    if( item1.weight == item2.weight )
    {
        return item1.cost < item2.cost;
    }
    else
    {
        return item1.weight < item2.weight;
    }
}

#endif
