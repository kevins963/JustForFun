#ifndef __CODE_CHEF_H
#define __CODE_CHEF_H

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef struct knapsackItem
{
	int weight;
	int cost;
} sKnapsackItem;

class CodeChef
{

public:
    void TestAll( void );

    void TestFindNextPalindroneNumber( void );
    int FindNextPalindroneNumber( int num );

    void TestFindMaxKnapsackCost( void );
    vector<sKnapsackItem> FindMaxKnapsackCost( vector<sKnapsackItem> &items, int maxWeight );
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

/*
Create a weight/cost table
*/
vector<sKnapsackItem> CodeChef::FindMaxKnapsackCost( vector<sKnapsackItem> &items, int maxWeight )
{
    return vector<sKnapsackItem>();

    /*std::sort( items.begin(), items.end(), SortKnapsackItem );
	
	vector<vector<int>> costWeightMatrix;

	for( int itemCount = 0; itemCount <= items.size() + 1; itemCount++ )
	{
		costWeightMatrix.push_back( vector<int>(maxWeight, 0) );

		for( int currentWeight = 0; currentWeight <= maxWeight; currentWeight++ )
		{
			if( itemCount == 0 || currentWeight == 0 )
			{
				if( items[i-1].weight <= currentWeight )
				{
					costWeightMatrix[i][w] = max( items[i-1] + costWeightMatrix[i-1][])
				}
				else
				{
					costWeightMatrix[i][w] = costWeightMatrix[i-1][currentWeight];
				}
			}
		}
	}

	if(maxWeight <= 0 || currentIndex < 0 || currentIndex >= items.size() || items[currentIndex].weight > maxWeight)
		return vector<sKnapsackItem>();

	vector<sKnapsackItem> knapsack = FindMaxKnapsackCost( items, maxWeight, currentIndex + 1);
	vector<sKnapsackItem> knapsackCurrent = FindMaxKnapsackCost( items, maxWeight - items[currentIndex].weight, currentIndex + 1)
	knapsackCurrent.push_back( items[currentIndex] );


	return the max knap sack
	vector<sKnapsackItem> knapsack;

	
	int weight = 0;
    */
}

bool SortKnapsackItem( const sKnapsackItem & item1, const sKnapsackItem & item2 )
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
