#ifndef STRING_ALGORITHMS_H__
#define STRING_ALGORITHMS_H__

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stdint.h>
#include <string.h>

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
    void ReverseStringInplace( char* inString );
    void RemoveAllDuplicateCharsNoExtraBuffer( string& inString );
    void RemoveAllDuplicateCharsNoExtraBufferKeys( string& inString );
    bool HasSubstring(string input, string findString );
    string HasSubstringDisregardNonChar(string input, string findString );
	bool IsAnagram( string* string1, string* string2 );
    

private:
    void TestAreAllCharactersUnique( void );
    void TestReverseString( void );
    void TestReverseStringInplace( void );
	void TestRemoveAllDuplicateCharsNoExtraBuffer( void );
    void TestHasSubstring( void );
    void TestHasSubstringDisregardNonChar( void );
    void TestRemoveAllDuplicateCharsNoExtraBufferKeys( void );
	void TestIsAnagram( void );
};


void StringAlgorithms::TestAll( void )
{
    TestAreAllCharactersUnique();
    TestReverseString();
    TestReverseStringInplace();
	TestRemoveAllDuplicateCharsNoExtraBuffer();
    TestHasSubstring();
    TestHasSubstringDisregardNonChar();
    TestRemoveAllDuplicateCharsNoExtraBufferKeys();
	TestIsAnagram();
}

void StringAlgorithms::TestAreAllCharactersUnique( void )
{
    static char* t1 = "abc";
    static char* t2 = "abcc";
    char* tests[] = { t1, t2 };
    bool expected[] = { true, false };

    cout << ">>>> ARE ALL CHARACTERS UNIQUE <<<<" << endl;

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

    cout << ">>>> REVERSE STRING <<<<" << endl;

    for( int i = 0; i < 2; i++ )
    {
        char* reverseString = ReverseString( tests[i] ); 
        cout << "Test = " << tests[i] << endl << "Expected = " << expected[i] << endl << "Result   = " << reverseString << endl << endl;
        delete[] reverseString;
    }
}

void StringAlgorithms::TestReverseStringInplace( void )
{
    char t1[] = "abc";
    char t2[] = "abcd";
    char* e1 = "cba";
    char* e2 = "dcba";

    char* tests[] = { t1, t2 };
    char* expected[] = { e1, e2 };

    cout << ">>>> REVERSE STRING INPLACE <<<<" << endl;

    for( int i = 0; i < 2; i++ )
    {
        cout << "Test = " << tests[i] << endl << "Expected = " << expected[i] << endl << "Result   = ";
        ReverseStringInplace( tests[i] ); 
        cout << tests[i] << endl << endl;
    }
}

void StringAlgorithms::TestRemoveAllDuplicateCharsNoExtraBuffer( void )
{
	string t1( "abc" );
	string t2( "aababccddaabbccdd" );
    string e1("abc");
    string e2("abcd");

    string tests[] = { t1, t2 };
    string expected[] = { e1, e2 };

    cout << ">>>> REMOVE ALL DUPLICATES FROM STRING <<<<" << endl;

    for( int i = 0; i < 2; i++ )
    {
        cout << "Test = " << tests[i] << endl << "Expected = " << expected[i] << endl << "Result   = ";
        RemoveAllDuplicateCharsNoExtraBuffer( tests[i] ); 
        cout << tests[i] << endl << endl;
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
* 
* runtime = O(N) 
* This increases linearly with the size of the string
*
* memory requirements = O(N)
* This algorithm returns a string the same size as the input string
*/
char* StringAlgorithms::ReverseString( const char* inString )
{
    int length = strlen( inString );
 
    char* reversedString = new char[ length + 1 ];

    /* evaluate and then decrement */
    for( int i = 0; i < length; i++ )
    {
        reversedString[ i ] = inString[ length - i - 1 ];
    }

    reversedString[length] = '\0';

    return reversedString;
}

/***
*
*This function reversess the string as an inplace
*
*
*
*/

void StringAlgorithms::ReverseStringInplace( char* inString )
{
    int32_t length = strlen( inString );

    char tempChar;
    char* ptrTail = &inString[0];
    char* ptrHead = &inString[length - 1];

    /* "ab" length = 2 */
    /* lh = l /2 = 1, */

    while( ptrTail < ptrHead )
    {
        tempChar = *ptrTail;
        *ptrTail++ = *ptrHead;
        *ptrHead-- = tempChar;
    }

}

/*
o(n^2)
*/
void StringAlgorithms::RemoveAllDuplicateCharsNoExtraBuffer( string& inString )
{
	
    int outStringLength;
	bool found;
	
	outStringLength = 1;
	for( int i = 1; i < inString.length(); i++ )
	{
		found = false;

		for( int j = 0; j < i; j++ )
		{
			if( inString[j] == inString[i] )
			{
				found = true;
			}
		}

		if( !found )
		{
			swap( inString[i], inString[outStringLength] );
			outStringLength++;
		}
	}

	inString.resize( outStringLength );
}

void StringAlgorithms::RemoveAllDuplicateCharsNoExtraBufferKeys( string& inString )
{
    char characters[256] = {0};

    int outStringLength;
    bool found;

    outStringLength = 1;
    
    int j = 0;
 
    for( int i = 0; i < inString.length(); i++ )
    {
        if( characters[inString[i]] == 0 )
        {
            characters[inString[i]] = 1;

            inString[j++] = inString[i];
        }
    }

    inString.resize(j);
}


void StringAlgorithms::TestRemoveAllDuplicateCharsNoExtraBufferKeys( void )
{
    cout << "TestRemoveAllDuplicateCharsNoExtraBufferKeys" << endl;
    vector<pair<string, string>> test;
    
    test.push_back( make_pair("abc", "abc"));
    test.push_back( make_pair("aaabbbbcccc", "abc"));
    test.push_back( make_pair("abcabcabcabcacbb", "abc"));
    test.push_back( make_pair("aabababccabbc", "abc"));

    for( auto itr = test.begin(); itr != test.end(); itr++ )
    {
        cout << "test = " << itr->first << " expected = " << itr->second;
        RemoveAllDuplicateCharsNoExtraBufferKeys( itr->first );
        cout << " actual = " << itr->first << endl;
    }
}

bool StringAlgorithms::HasSubstring( string input, string findString )
{
    bool isFound = false;

    for( int i = 0; i <= input.length() - findString.length() && input.length() > 0 && !isFound; i++ )
    {
        if( input[i] == findString[0] )
        {
            bool isMatchError = false;

            for( int j = 0; j < findString.length() && !isMatchError; j++ )
            {
                if( input[i+j] != findString[j] )
                {
                    isMatchError = true;
                }
            }
            
            isFound = !isMatchError;
        }
    }

    return isFound;
}

void StringAlgorithms::TestHasSubstring( void )
{
    string matchString = "abc";
   
    cout << "************** HAS SUBSTRING ************";
    vector<pair<string,bool>> test;
    test.push_back(make_pair("abc", true));
    test.push_back(make_pair(".abc", true));
    test.push_back(make_pair("abc.", true));
    test.push_back(make_pair("a.bc", false));
    test.push_back(make_pair("ab.aabc", true));
    test.push_back(make_pair("aaab", false));

    for( auto itr = test.begin(); itr != test.end(); itr++ )
    {
        cout << "match = " << matchString << " string = " << itr->first << endl;
        cout << "expected= " << itr->second << " actual = " << HasSubstring( itr->first, matchString ) << endl;
    }
}


string StringAlgorithms::HasSubstringDisregardNonChar( string input, string findString )
{
    bool isFound = false;
    string subString;
    int start = 0;
    int end = 0;

    for( int i = 0; i < input.length()&& input.length() > 0 && !isFound; i++ )
    {
        if( input[i] == findString[0] )
        {
            int matchError = false;
            int matchCount = 0;

            int j = 0;
            int k = i;
            
            while( j < findString.length() && k < input.length() && !matchError)
            {
                if( !isalnum(input[k]) )
                {
                    k++;
                }
                else if( input[k] != findString[j] )
                {
                    matchError = true;
                }
                else
                {
                    matchCount++;
                    k++;
                    j++;
                }
            }

            if( matchCount == findString.length() )
            {
                isFound = true;
                start = i;
                end = k;

                subString = input.substr( start, ( end - start ) );
            }
        }
    }

    return subString;
}

void StringAlgorithms::TestHasSubstringDisregardNonChar( void )
{
    string matchString = "abc";

    cout << "************** HAS SUBSTRING DISREGARD NON CHAR ************" << endl;
    vector<pair<string,string>> test;
    test.push_back(make_pair("abc", "abc"));
    test.push_back(make_pair(".abc", "abc"));
    test.push_back(make_pair("abc.", "abc"));
    test.push_back(make_pair("a.bc", "a.bc"));
    test.push_back(make_pair("ab.aabc", "abc"));
    test.push_back(make_pair("...a., b  /c/.,", "a., b  /c"));
    test.push_back(make_pair("...a., b  /dc/.,", ""));

    for( auto itr = test.begin(); itr != test.end(); itr++ )
    {
        cout << "match = " << matchString << " string = " << itr->first << endl;
        cout << "expected= " << itr->second << " actual = " << HasSubstringDisregardNonChar( itr->first, matchString ) << endl << endl;
    }
}

void StringAlgorithms::TestIsAnagram( void )
{
	cout << "***************TEST IS ANAGRAM******************\n";
	vector<pair<pair<string, string>, bool>> test;

	test.push_back( make_pair( make_pair( "abc", "abc" ), true ) );
	test.push_back( make_pair( make_pair( "abc", "cab" ), true ) );
	test.push_back( make_pair( make_pair( "abbbc", "cbbba" ), true ) );
	test.push_back( make_pair( make_pair( "abc", "ca" ), false ) );
	test.push_back( make_pair( make_pair( "abc", "cabb" ), false ) );

	for( auto itr = test.begin(); itr != test.end(); ++itr )
	{
		cout << "str1 = " << itr->first.first << " str2 = " << itr->first.second << endl;
		cout << "expected = " << itr->second << " actual = " << IsAnagram( &itr->first.first, &itr->first.second ) << endl << endl;
	}

}

bool StringAlgorithms::IsAnagram(string* string1, string* string2)
{
	char isAnagram;
	char characterCount[256];

	int strLen1;
	int strLen2;

	memset( characterCount, 0, 256 );

	strLen1 = string1->size();
	strLen2 = string2->size();

	// case 0: strings must be same size

	if( strLen1 != strLen2 )
	{
		isAnagram = false;
	}
	// case 1: same number of characters in each string
	else
	{
		// traverse each string and count total chars
		for( int i = 0; i < strLen1; ++i )
		{
			characterCount[ string1->at( i ) ]++;
		}

		// traverse each string and count total chars
		for( int i = 0; i < strLen2; ++i )
		{
			characterCount[ string2->at( i ) ]--;
		}

		// if both counts are same then it is an anagram

		isAnagram = true;

		for( int i = 0; i < 256; ++i )
		{
			if( characterCount[i] != 0 )
			{
				isAnagram = false;
			}
		}
	}

	return isAnagram;
	
}

#endif // !STRING_ALGORITHMS_H__
