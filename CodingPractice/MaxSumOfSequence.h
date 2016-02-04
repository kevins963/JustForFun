#pragma once

#include <vector>

using namespace std;
class MaxSumOfSequence
{
public:
    int maxSubArray( const vector<int> &A );
};


int MaxSumOfSequence::maxSubArray( const vector<int> &A )
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int maxSequenceValue = A[ 0 ];

    vector<int> sumArray = vector<int>( A.size(), 0 );

    sumArray[ 0 ] = A[ 0 ];

    for( int i = 1; i < A.size(); i++ )
    {
        //three cases use value in A, value in Sum, or current value
        int maxValue;
        maxValue = A[ i ];

        if( maxValue < A[ i ] + A[ i - 1 ] )
        {
            maxValue = A[ i ] + A[ i - 1 ];
        }

        if( maxValue < A[ i ] + sumArray[ i - 1 ] )
        {
            maxValue = A[ i ] + sumArray[ i - 1 ];
        }

        sumArray[ i ] = maxValue;

        if( maxValue > maxSequenceValue )
        {
            maxSequenceValue = maxValue;
        }
    }

    return maxSequenceValue;
}
