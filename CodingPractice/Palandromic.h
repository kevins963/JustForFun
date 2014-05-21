#pragma once

#include <string>
#include <map>
#include <vector>
#include <cctype>

using namespace std;

/*
Palandromic is a set of letters that is the same backwards as forwards

mom
to mot
no x in nixon
Do not include whitespace or puncuations

Requirements word[start + pos] == word_len[end - pos]

Option 1: Go through ever single possibility, each letter to every other leter
 run time = n^2
Option 2:
2.1 Find all letters that are the same throughout entire sentence, those are the only possibilities are palandromic
2.2 Iterate through each possible palandromic, check if each meets requirement
2.3 Store in hash, fast look up


*/
class Palandromic
{
public:
    Palandromic();
    ~Palandromic();

    string GetLongestPalandromic( string &sentence );
    
private:
    bool IsValidChar( char charactor );
    bool CheckIfPalandrom( string &inputString, int startIndex, int stopIndex );
    
};

Palandromic::Palandromic()
{
}

Palandromic::~Palandromic()
{
}

string Palandromic::GetLongestPalandromic( string &sentence )
{
    int palandromStart = 0;
    int palandromStop = 0;

    map<char, vector<int>> charMap;

    string whitespaceRemovedSentence;

    for( int i = 0, index = 0; i < sentence.size(); i++)
    {
        char charactor = sentence[i];

        if( IsValidChar(charactor) )
        {
            whitespaceRemovedSentence.push_back(charactor);
            //vector<int> &indicies = 
            charMap[charactor].push_back(index++);

        }
    }

    for( map<char, vector<int>>::iterator itr = charMap.begin(); 
         itr != charMap.end();
         itr++)
    {
        vector<int> &indecies = itr->second;

        bool isPalidromFound = false;
        //Start from back, first one found will be longest
        for( int i = 0; i < indecies.size() && !isPalidromFound ; i++ )
        {           

            for( int j = indecies.size() - 1 && !isPalidromFound; j > i; j-- )
            {
                int frontIndex =  indecies[i];
                int backIndex = indecies[j];
                if( CheckIfPalandrom( whitespaceRemovedSentence, frontIndex, backIndex ) )
                {
                    isPalidromFound = true;
                    
                    //Only want to larges palindrome
                    if( ( backIndex - frontIndex ) > ( palandromStop - palandromStart ) )
                    {
                        palandromStart = frontIndex;
                        palandromStop = backIndex;
                    }
                }
            }
        }
    }

    if( palandromStart != palandromStop )
    {
        return whitespaceRemovedSentence.substr( palandromStart, (palandromStop - palandromStart) + 1 ); 
    }

    return string();
}

bool Palandromic::IsValidChar( char charactor )
{
    if( ( ( charactor >= 'a' ) && ( charactor <= 'z' ) ) ||
        ( ( charactor >= 'A' ) && ( charactor <= 'Z' ) ) )
    {
        return true;
    }

    return false;
}

bool Palandromic::CheckIfPalandrom( string &inputString, int startIndex, int stopIndex )
{
    bool isPalandrom = true;

    while( ( startIndex < stopIndex ) && isPalandrom )
    {
        if( std::toupper( inputString[startIndex] ) != std::toupper( inputString[stopIndex] ) )
        {
            isPalandrom = false;
        }

        startIndex++;
        stopIndex--;
    }

    return isPalandrom;
}



