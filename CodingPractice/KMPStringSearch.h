#pragma once

#include <string>
#include <vector>

using namespace std;

class KmpStringSearch
{
public:
    void Test();
    int FindString( const string & haystack, const string & needle );
    vector<int> CalcJumpTable( const string &needle );
};

void KmpStringSearch::Test()
{
    string haystack = "babbaaabaaaabbababaaabaabbbbabaaaabbabbabaaaababbabbbaaabbbaaabbbaabaabaaaaababbaaaaaabababbbbba";
    string needle = "bababbbbbbabbbaabbaaabbbaababa";

    FindString( haystack, needle );

}

int KmpStringSearch::FindString( const string & haystack, const string & needle )
{
    vector<int> jumpTable = CalcJumpTable( needle );

    int i = 0;
    int j = 0;
    while( i < haystack.size() )
    {

        if( needle[ j ] == haystack[ i ] )
        {
            i++;
            j++;

            if( j == needle.size() )
            {
                return i - j;
            }
        }
        else if( j > 0 )
        {
            //check lookback table
            j = jumpTable[ j ];
        }
        else
        {
            i++;
        }

        cout << "[ " << i << ", " <<j << " ]";
    }

    return -1;
}

vector<int> KmpStringSearch::CalcJumpTable( const string &needle )
{
    vector<int> jumpTable( needle.size(), 0 );

    int j = 0;

    for( int i = 2; i < needle.size(); i++ )
    {
        //get current largest match
        j = jumpTable[ i - 1 ];

        //essentially find patterns
        while( true )
        {

            //match so increment
            if( needle[ j ] == needle[ i - 1 ] )
            {
                jumpTable[ i ] = j + 1;
                break;
            }
            //no matches found, set to start
            else if( j == 0 )
            {
                jumpTable[ i ] = 0;
                break;
            }
            //if there was previous pattern search for next best
            else
            {
                j = jumpTable[ j ];
            }
        }

    }

    return jumpTable;
}
