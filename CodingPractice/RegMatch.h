#pragma once

#include <string>
#include <iostream>
//'.' matches single character
//'*' match 0 or more preceeding
//cover entire input string

using namespace std;
class RegMatch
{
public:
    RegMatch();
    ~RegMatch();

    bool IsMatch( char * inputString, char * matchString )
    {
        bool isWildChar = false;
        bool isLeadingChars = false;
        char currentChar;
        bool getNextMatch = false;
        bool isMatch = true;

        int inputStringCount = strlen( inputString );
        int matchStringCount = strlen( matchString );
        int matchPos = 0;
        int inputPos = 0;
        while ( matchPos < matchStringCount  && isMatch )
        {
            getNextMatch = false;

            switch ( matchString[matchPos] )
            {
            case '*':
                isLeadingChars = true;
                while( matchString[matchPos+1] == '*' )
                {
                    matchPos++;
                }
                getNextMatch = true;

                cout << "leading\n";
                break;
            case '.':
                isWildChar = true;
                cout << "wild\n";
                break;
            default:
                currentChar = matchString[matchPos];
                cout << "char\n";
                break;
            }

            matchPos++;
            if(!getNextMatch)
            {
                if(inputPos >= inputStringCount)
                {
                    isMatch = false;
                }
                else if(isLeadingChars)
                {
                    bool charMatch = false;
                    while((inputPos < inputStringCount) && !charMatch)
                    {
                        if(isWildChar)
                        {
                            charMatch = true;
                        }
                        else if(inputString[inputPos]==currentChar)
                        {
                            charMatch = true;
                        }

                        inputPos++;
                    }
                }
                else if(isWildChar)
                {
                    inputPos++;
                }
                else if( inputString[inputPos] == currentChar )
                {
                    inputPos++;
                }
                else
                {
                    isMatch = false;
                }
            }
        }
        return isMatch;
    }

private:

};

RegMatch::RegMatch()
{
}

RegMatch::~RegMatch()
{
}