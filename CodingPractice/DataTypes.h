#pragma once

#include <vector>
#include <algorithm>
#include "Utilities.h"

using namespace std;

class StdDataTypes
{
public:
    StdDataTypes();
    ~StdDataTypes();

    void Sorting();
};

void StdDataTypes::Sorting()
{
    int someArray[] = {1,5,3,7,6,0,9,8,4,5};

    vector<int> vectorArray;
    vectorArray.push_back( 1 );
    vectorArray.push_back( 4 );
    vectorArray.push_back( 7 );
    vectorArray.push_back( 2 );
    vectorArray.push_back( 3 );
    vectorArray.push_back( 0 );
    vectorArray.push_back( 3 );
    vectorArray.push_back( 5 );
    vectorArray.push_back( 2 );
    vectorArray.push_back( 7 );

    std::sort( vectorArray.begin(), vectorArray.end() );

    vector<int> v2;
    v2.insert( v2.end(), someArray, (someArray + 10) );

    vector<int>::iterator itr = std::find( v2.begin(), v2.end(), 3 );

    PrintArray( v2.data(), 0, v2.size(), true );

    cout << "index of 3: " <<  std::distance( v2.begin(), itr ) << endl;


}
