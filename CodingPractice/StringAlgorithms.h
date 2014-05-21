#ifndef STRING_ALGORITHMS_H__
#define STRING_ALGORITHMS_H__

#include <iostream>
#include <map>
#include <set>
#include <stdint.h>

using namespace std;

class StringAlgorithms
{
public:
    StringAlgorithms( void ) {};
    ~StringAlgorithms( void ) {};
public:
    void TestAll( void );
    
    bool AreAllCharactersUnique( const char* inString, int32_t size );
    char* ReverseString( const char* inString);
   
private:
    void TestAreAllCharactersUnique( void );
    void TestReverseString( void );
};


void StringAlgorithms::TestAll( void )
{
    TestAreAllCharactersUnique();
}

void StringAlgorithms::TestAreAllCharactersUnique( void )
{
    static char* t1 = "abc";
    static char* t2 = "abcc";
    char* tests[] = { t1, t2 };
    bool expected[] = { true, false };

    cout << ">>>> ARE ALL CHARACTERS UNIQUE <<<<";

    for( int i = 0; i < 2; i++ )
    {
        cout << "Test = " << tests[i] << endl << "Expected = " << expected[i] << endl << "Result   = " << AreAllCharactersUnique( tests[i], strlen( tests[i] ) ) << endl << endl; 
    }
}

void StringAlgorithms::TestReverseString( void )
{
    char* t1 = "abc";
    char* t2 = "abcd";
    char* e1 = "cba";
    char* e2 = "dcba";

    char* tests[] = { t1, t2 };
    char* expected[] = { e1, e2 };

    cout << ">>>> ARE ALL CHARACTERS UNIQUE <<<<";

    for( int i = 0; i < 2; i++ )
    {
        char* reverseString = ReverseString( tests[i] ); 
        cout << "Test = " << tests[i] << endl << "Expected = " << expected[i] << endl << "Result   = " << reverseString << endl << endl;
        delete[] reverseString;
    }
}


/*
*
* Easiest way to to go through all characters in the string and insert into a set and if duplicate return false
*
*/
bool StringAlgorithms::AreAllCharactersUnique( const char* inString, int32_t size )
{
    set<char> characterSet;
    bool isUnique;

    isUnique = true;
    while( size-- && isUnique )
    {
        if( characterSet.find( *inString ) == characterSet.end() )
        {
            characterSet.insert( *inString++ );
        }
        else
        {
            isUnique = false;
        }
    }

    return isUnique;
}

/**
* To reverse a string you will need pointer swap( character[x], character[size - x] )
* "abc\0" array size == 4, strlen = 3
* since returning new string dont need swap
* outString[x] = inString[length - x]
*/
char* StringAlgorithms::ReverseString( const char* inString )
{
    int length = strlen( inString );
 
    char* reversedString = new char[ length + 1 ];

    /* evaluate and then decrement */
    for( int i = 0; i < length; i++ )
    {
        reversedString[ i ] = inString[ length - i ];
    }

    reversedString[length] = '/0';

    return reversedString;
}

#endif // !STRING_ALGORITHMS_H__
