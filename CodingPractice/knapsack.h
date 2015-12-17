#ifndef knapsack_h__
#define knapsack_h__

#include <stdint.h>
#include <vector>

using namespace std;

typedef struct costWeight
{
    int32_t cost;
    int32_t weight;

    costWeight(int32_t c, int32_t w)
    {
        cost = c;
        weight = w;
    }
}
sCostWeight;

class Knapsack
{

public:
    Knapsack();
    ~Knapsack();

private:
    void TestAll();

    void TestMinimizeCostWeight();
    void MinimizeCostWeight( const int32_t targetWeight, const sCostWeight itemList );
};

Knapsack::Knapsack()
{
}

Knapsack::~Knapsack()
{
}

void Knapsack::TestAll()
{

}

void Knapsack::TestMinimizeCostWeight()
{
    vector<sCostWeight> costList;
    costList.push_back(sCostWeight(2, 2));
    costList.push_back(sCostWeight(5, 5));
    costList.push_back(sCostWeight(10, 10));

}

/* 
Problem: You are on plane and need to lose X pounds and dropping cargo.  
You have list of cargo that you may drop off, but you want to drop off enough cargo to equal the target weight while miniming the cost of the lost cargo

each item has unlimited number of peices to use

This is a type of knapsack problem
*/
void Knapsack::MinimizeCostWeight( const int32_t targetWeight, const sCostWeight itemList )
{
    /* solve by dynamic programming */
    /* sort items by weight */
    /* recursively call problem */
}

#endif // knapsack_h__
