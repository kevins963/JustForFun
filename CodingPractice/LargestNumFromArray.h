#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

bool radixCmp( const int &lhs, const int &rhs );

//given an array of numbers find the largest number that can be created from it, return the string version
class LargestNumFromArray
{
    void Test();
    string largestNumber( const vector<int> &A );
};

void Test()
{
    cout << "LargestNumFromArray" << endl;
}

string LargestNumFromArray::largestNumber( const vector<int> &A )
{

std:vector<int> inputArray( A.begin(), A.end() );
    std::ostringstream s;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    std::sort( inputArray.begin(), inputArray.end(), radixCmp );

    //special case
    if( inputArray[ 0 ] == 0 )
    {
        s << 0;
    }
    else
    {
        for( int i = 0; i < inputArray.size(); i++ )
        {
            s << inputArray[ i ];
        }
    }

    return s.str();
}

bool radixCmp( const int &lhs, const int &rhs )
{
   
    //This compare sees what value is bigger, lhs appended to rhs OR rhs appended to lhs
    long tempL = lhs;
    long tempR = rhs;

    long cmpL;
    long cmpR;

    //special case when zero, undefined for log10
    int digitsL = ( tempL == 0 ) ? 1 : std::log10( tempL ) + 1;
    int digitsR = ( tempR == 0 ) ? 1 : std::log10( tempR ) + 1;

    int tL = digitsL;
    int tR = digitsR;

    cmpL = tempL;
    while( digitsR-- )
    {
        cmpL *= 10;
    }
    cmpL += tempR;

    cmpR = tempR;
    while( digitsL-- )
    {
        cmpR *= 10;
    }
    cmpR += tempL;



    //cout << " " << cmpL<< " " << cmpR << " " << tempL << " " << tempR << " " << tL << " " << tR <<  endl;

    return cmpL > cmpR;

}