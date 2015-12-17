#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <xutility>
#include <queue>

using namespace std;

class GraphTypeProblems
{
public:
    void TestAll();
private:
    void TestShortestPathConvertWordToAnother( void );
    vector<string> ShortestPathConvertWordToAnother( vector<string> dictionary, string s1, string s2 );
};

void GraphTypeProblems::TestAll()
{
    TestShortestPathConvertWordToAnother();
}

void GraphTypeProblems::TestShortestPathConvertWordToAnother(void)
{
    vector<pair<string, string>> tests;
    vector<string> dictionary;
    dictionary.push_back( "aaa" );
    dictionary.push_back( "aab" );
    dictionary.push_back( "abb" );
    dictionary.push_back( "bbb" );
    dictionary.push_back( "bab" );
    dictionary.push_back( "bat" );
    dictionary.push_back( "cat" );
    tests.push_back( make_pair( "aaa", "aab") );
    tests.push_back( make_pair( "aaa", "cat") );

    cout << "*********** TestShortestPathConvertWordToAnother *****************" << endl;

    for( auto itr = tests.begin(); itr != tests.end(); itr++ )
    {
        auto result = ShortestPathConvertWordToAnother( dictionary, itr->first, itr->second );

        cout << "s1=" << itr->first << " s2= " << itr->second << " result " << endl << "{ " << endl;
        for( auto itrResult = result.begin(); itrResult != result.end(); itrResult++ )
        {
            cout << *itrResult << endl;
        }
        cout << "}"<< endl;
    }
    
}

/*
Find the shortest path to converting one word to another using a dictionary.  You can
change at most one letter at a time to convert it to another word

* remember *
BFS typically best for finding shortest path
DFS typically best for findingh cycles

Using BFS to find shortest path to new word

*/
vector<string> GraphTypeProblems::ShortestPathConvertWordToAnother(vector<string> dictionary, string s1, string s2)
{
    vector<int> visistedArray = vector<int>( dictionary.size(), -1 );
    queue<string> searchQueue;
    vector<string> shortestPathOut;

    //push first item onto queue
    auto searchItr = std::find(dictionary.begin(), dictionary.end(), s1 );
    
    if( searchItr != dictionary.end() )
    {
        visistedArray.at( searchItr - dictionary.begin() ) = searchItr - dictionary.begin();
        searchQueue.push( *searchItr );
    }

    bool isFound = false;
    while( searchQueue.size() > 0 && isFound == false )
    {
        //try changing every letter in the array and see if it matches, if it matches then solved
        //else push onto queue if not already visited
        string currentString = searchQueue.front();
        string tempString;
        searchQueue.pop();

        for( int i = 0; i < currentString.size(); i++ && isFound == false )
        {
            int currentStringIndex = find( dictionary.begin(), dictionary.end(), currentString ) - dictionary.begin();
            tempString = currentString;

            for( char letter = 'a'; letter <= 'z'; letter++ && isFound == false )
            {
                tempString.at(i) = letter;
                
                auto newWordItr = find( dictionary.begin(), dictionary.end(), tempString );

                if( newWordItr != dictionary.end() )
                {
                    int index = newWordItr - dictionary.begin();

                    if( visistedArray.at( index ) == -1 )
                    {
                        visistedArray.at( index ) = currentStringIndex;

                        if( tempString == s2 )
                        {
                            isFound = true;

                            //Trace backwards for new string
                            int backSearchPathIndex = index;

                            while( backSearchPathIndex != visistedArray.at( backSearchPathIndex ) && backSearchPathIndex != -1 )
                            {
                                shortestPathOut.push_back( dictionary.at( backSearchPathIndex ) );
                                backSearchPathIndex = visistedArray.at(backSearchPathIndex);
                            }

                            shortestPathOut.push_back( dictionary.at( backSearchPathIndex ) );

                        }
                        else
                        {
                            //Push string onto stack and set the backtrack index
                            searchQueue.push( tempString );
                        }
                    }
                }
                //search for in dictory, if not visisted check if match for s2 else push to queue
            }
        }
    }
    return shortestPathOut;
}
