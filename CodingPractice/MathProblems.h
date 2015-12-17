#include "stdint.h"
#include "stdio.h"
#include <iostream>
#include <vector>

using namespace std;

#define MAX_DIFFERENCE ( 0.00001f )
class MathProblems
{
public:
    MathProblems(){};
    ~MathProblems(){};

    void TestAll();
private:
    void TestSquareRoot();
    double SquareRoot( double value );
};

void MathProblems::TestAll()
{
    TestSquareRoot();
}

void MathProblems::TestSquareRoot()
{
    vector<std::pair<double,double>> test;

    test.push_back( make_pair(4.0f, 2.0f));
    test.push_back( make_pair(100.0f, 10.0f));
    test.push_back( make_pair(10.0f, 3.34f));
    cout << "************TESTING SQUARE***************\n";

    for( auto itr = test.begin(); itr < test.end(); ++itr )
    {
        cout << " test = " << itr->first << " expected = " << itr->second << " actual = ";
        cout << SquareRoot( itr->first ) << "\n";
    }
}

/*
Find square root by using binary search algorithm
min = 0, max =value, square root is somewhere inbetween
*/
double MathProblems::SquareRoot(double value)
{
    double min = 0;
    double max = value;
    double currentValue = 0;
    double difference = value;

    while( difference > MAX_DIFFERENCE ||
           difference < -MAX_DIFFERENCE )
    {

        if( difference > 0 )
        {
            min = currentValue;
            currentValue = ( max + currentValue ) / 2;
        }
        else
        {
            max = currentValue;
            currentValue = ( currentValue + min ) / 2;
        }

        int squaredValue = currentValue * currentValue;
        difference = value - squaredValue;

    }

    return currentValue;
}
