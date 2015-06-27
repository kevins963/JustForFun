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
    string GetLongestIncreasingSubstring( const string & inString );
	string MultiplyBigIntWithString( string a, string b );
	string RunLengthEncoding( string input );
	string GetLongestCommonSubstringDynamic( const string & input, const string & pattern );
	string GetLongestCommonSubsequenceDynamic( const string & input, const string & pattern );
	bool IsPatternInString( const string & input, const string & pattern );

private:
    void TestAreAllCharactersUnique( void );
    void TestReverseString( void );
    void TestReverseStringInplace( void );
	void TestRemoveAllDuplicateCharsNoExtraBuffer( void );
    void TestHasSubstring( void );
    void TestHasSubstringDisregardNonChar( void );
    void TestRemoveAllDuplicateCharsNoExtraBufferKeys( void );
	void TestIsAnagram( void );
	void TestGetLongestIncreasingSubstring( void );
	void TestMultiplyBigIntWithString( void );
	void TestRunLengthEncoding( void );
	void TestGetLongestCommonSubstringDynamic( void );
	void TestGetLongestCommonSubsequenceDynamic( void );
	void TestIsPatternInString( void );
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
	TestGetLongestIncreasingSubstring();
    TestMultiplyBigIntWithString();
	TestRunLengthEncoding();
	TestGetLongestCommonSubstringDynamic();
	TestGetLongestCommonSubsequenceDynamic();
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

void StringAlgorithms::TestGetLongestIncreasingSubstring(void)
{
	vector<pair<string,string>> tests;

	tests.push_back( make_pair( "abc", "abc" ) );
	tests.push_back( make_pair( "aabc", "abc" ) );
	tests.push_back( make_pair( "aabcc", "abc" ) );
	tests.push_back( make_pair( "aabccabcda", "abcd" ) );

	for( auto itr = tests.begin(); itr != tests.end(); itr++ )
	{
		string result = GetLongestIncreasingSubstring( itr->first );

		printf( "in=%s, ex=%s, act=%s, pass=%d\n", itr->first.c_str(), itr->second.c_str(), result.c_str(), itr->second.compare( result ) == 0 );
	}
}

/*
To do this simple search store first index and last index of sequence, replace with longest sequence.
*/
std::string StringAlgorithms::GetLongestIncreasingSubstring(const string & inString)
{
	int startMax = -1;
	int endMax = -1;
	int count = 0;
	
	// [0,1,2,3,4]
	// 
	for( int index = 0; index < inString.length() - 1; index++ )
	{
		if( inString[ index ] < inString[ index + 1 ] )
		{
			count++;
		}
		else
		{
			if( count > ( endMax - startMax ) )
			{
				startMax = index - count;
				endMax = index;
				count = 0;
			}
		}
	}

	//if goes to in save
	if( count > ( endMax - startMax ) )
	{
		startMax = inString.length() - ( count + 1 );
		endMax = inString.length() - 1;
	}

	string out;

	if( startMax != -1 )
	{
		out = inString.substr( startMax, endMax - startMax + 1 );
	}
	else
	{
		out = "";
	}

	return out;
}

/*
to multiply string need to convert to a single digit and hold offset
*/
void StringAlgorithms::TestMultiplyBigIntWithString(void)
{
    
    string result = MultiplyBigIntWithString( "123456789", "123456789" );

    printf( "result = %s", result.c_str() );
}

std::string StringAlgorithms::MultiplyBigIntWithString(string a, string b)
{
	//int size = ( a.length() > b.length() ) ? a.length() : b.length();

	//max size is 2 x length
	string product = string( a.length() + b.length(), '0' );
    // 98 x 2
    // 016
    // 180
    // 196
	//get digit should mult each, and add to current spot
	for( int i = 0; i < a.length() ; i++ )
	{
		int carryOver = 0;
        int valA = ( int )( a[ a.length() - i - 1] - '0' );

		for( int j = 0; j < b.length(); j++ )
		{	
            int valB = ( int )( b[ b.length( ) -j - 1 ] - '0' );
			int offset = i+j;           
            int prod = valA * valB + carryOver;

			//get tens and ones, tens carryover, ones goes to array
            while( prod )
            {
                int currentProd = ( int )( product[ offset ] - '0' );
                prod += currentProd;
                product[ offset++ ] = '0' + prod % 10;
                prod /= 10;
            }           
		}
	}
    
    string output;

    for( auto ritr = product.rbegin(); ritr != product.rend(); ritr++ )
    {
		output.push_back( *ritr );
    }

    return output;
}

void StringAlgorithms::TestRunLengthEncoding(void)
{
	vector<pair<string, string>> tests;

	tests.push_back( make_pair( "abbcccddddeeeee", "a2b3c4d5e" ) );
	tests.push_back( make_pair( "abbcdddeffff", "a2bc3de4f" ) );

	for( auto itr = tests.begin(); itr != tests.end(); itr++ )
	{
		string result = RunLengthEncoding( itr->first );

		printf( "in=%s, ex=%s, rslt=%s, pass=%0d\n", itr->first.c_str(), itr->second.c_str(), result.c_str(), result.compare( itr->second ) == 0 );
	}
}

/*
Run Length Encoding is a way to suppress string with repeated letters
abbcccddddeeeee
a2b3c4d5e
use an index start/end to get count
*/
std::string StringAlgorithms::RunLengthEncoding(string input)
{
	char num[10];
	int size;

	string output;

	int startIndex = 0;

	for( int i = 0; i < input.size(); i++ )
	{
		if( input[startIndex] != input[i] )
		{
			if( i - startIndex > 1 )
			{
				size = sprintf_s(num, 10, "%d", i - startIndex );
				output.append( num, &num[size] );
			}

			
			output.push_back( input[startIndex] );

			startIndex = i;
		}
	}

	//get last char
	int lastIndex = input.length() - 1;

	if( lastIndex - startIndex > 1 )
	{
		size = sprintf_s(num, 10, "%d", lastIndex - startIndex + 1 );
		output.append( num, &num[size] );
	}

	output.push_back( input[startIndex] );

	return output;
}

/*
To find the long common substring using dynamic programming, setup a table MxN to show the longest string.
If
*/

#define GET_INDEX_2D( cols, rowIndex, colIndex ) ( (colIndex) + ( (rowIndex) * (cols) ) )

std::string StringAlgorithms::GetLongestCommonSubstringDynamic(const string & input, const string & pattern )
{
	string out;
	
	int maxMatch = 0;
	int startIndex;
	int rows = pattern.size() + 1;
	int cols = input.size() + 1;

	int *matchArray = new int[ (rows) * ( cols ) ];

	for( int i = 0; i < input.size() + 1; i++ )
	{
		for( int j=0; j < pattern.size() + 1; j++ )
		{
			//printf( "[%d][%d] = %d\n", i, j, GET_INDEX_2D( cols, j, i  ) );
			if( i == 0 || j == 0 )
			{
				matchArray[ GET_INDEX_2D( cols, j, i ) ] = 0;
			}
			else if( input[i - 1] == pattern[j - 1] )
			{
				int matchSize = 1 + matchArray[ GET_INDEX_2D( cols, j - 1, i - 1  ) ];
				matchArray[ GET_INDEX_2D( cols, j, i ) ] = matchSize; 
				//TODO set start end if maxMAtch is the new max size 
				if( maxMatch < matchSize )
				{
					maxMatch = matchSize;
					startIndex = j - matchSize;
				}
			} 
			else
			{
				matchArray[ GET_INDEX_2D( cols, j, i ) ] = 0;
			}
		}
	}

	delete matchArray;

	return string( pattern.begin() + startIndex, pattern.begin() + startIndex + maxMatch );
}

void StringAlgorithms::TestGetLongestCommonSubstringDynamic(void)
{
	vector<pair<pair<string,string>,string>> tests;

	tests.push_back( make_pair( make_pair( "ababccd", "abcd" ), "abc" ) );
	tests.push_back( make_pair( make_pair( "abcdefghijklmnopqrstuvwxyz", "abaabchlmnopqrlztuvq" ), "lmnopqr" ) );

	cout << "**************LONG COMMON SUBSTRING ******************" << endl;

	for( auto itr = tests.begin(); itr != tests.end(); itr++ )
	{
		auto result = GetLongestCommonSubstringDynamic( itr->first.first, itr->first.second );

		printf( "in: s=%s, p=%s, out=%s, exp=%s, pass=%d\n",itr->first.first.c_str(), itr->first.second.c_str(), result.c_str(), itr->second.c_str(),result.compare( itr->second ) == 0  );
	}
}

void StringAlgorithms::TestGetLongestCommonSubsequenceDynamic(void)
{
	vector<pair<pair<string,string>,string>> tests;

	tests.push_back( make_pair( make_pair( "ababccd", "abcd" ), "abcd" ) );
	tests.push_back( make_pair( make_pair( "abcdefghij", "jedfiabbj" ), "efij" ) );

	cout << "**************LONG COMMON SUBSEQUENCE ******************" << endl;
	for( auto itr = tests.begin(); itr != tests.end(); itr++ )
	{
		auto result = GetLongestCommonSubsequenceDynamic( itr->first.first, itr->first.second );

		printf( "in: s=%s, p=%s, out=%s, exp=%s, pass=%d\n",itr->first.first.c_str(), itr->first.second.c_str(), result.c_str(), itr->second.c_str(),result.compare( itr->second ) == 0  );
	}
}
/*
To find the long common subsequence using dynamic programming, subsquence can be non continious. 
Similar to substring setup a table MxN to show the longest string.
pull down largest from top or left to new cell
*/
std::string StringAlgorithms::GetLongestCommonSubsequenceDynamic(const string & input, const string & pattern )
{
	string out;

	int maxMatch = 0;
	int startIndex;
	int rows = pattern.size() + 1;
	int cols = input.size() + 1;

	int *matchArray = new int[ (rows) * ( cols ) ];

	for( int iCol = 0; iCol < input.size() + 1; iCol++ )
	{
		for( int jRow=0; jRow < pattern.size() + 1; jRow++ )
		{
			//If found add to the previous match( i-1, j-1)
			//if not found carry down the current value( i-1, j)
			//printf( "[%d][%d] = %d\n", i, j, GET_INDEX_2D( cols, j, i  ) );
			if( iCol == 0 || jRow == 0 )
			{
				matchArray[ GET_INDEX_2D( cols, jRow, iCol ) ] = 0;
			}
			else if( input[iCol - 1] == pattern[jRow - 1] )
			{
				int matchSize = 1 + matchArray[ GET_INDEX_2D( cols, jRow - 1, iCol - 1  ) ];
				matchArray[ GET_INDEX_2D( cols, jRow, iCol ) ] = matchSize; 
				//TODO set start end if maxMAtch is the new max size 
				if( maxMatch < matchSize )
				{
					maxMatch = matchSize;
					startIndex = jRow - matchSize;
				}
			} 
			else
			{
				//keep the largest from top or left
				matchArray[ GET_INDEX_2D( cols, jRow, iCol ) ] = max( matchArray[ GET_INDEX_2D( cols, jRow - 1, iCol ) ], matchArray[ GET_INDEX_2D( cols, jRow, iCol - 1 ) ] );
			}
		}
	}

	//Now find the lartgest match search the bottom row and get the highest value, then to find the string
	//follow the if([i-1][j-1] == [i][j] - 1) then it is match so that the currenbt letter at [i][j]

	//get max col
	int maxCol = 0;
	for( int col = 1; col < cols; col++ )
	{
		if( matchArray[ GET_INDEX_2D( cols, rows - 1, col ) ] > matchArray[ GET_INDEX_2D( cols, rows - 1, maxCol ) ] )
		{
			maxCol = col;
		}
	}

	string subsequence = string( matchArray[ GET_INDEX_2D( cols, rows - 1, maxCol ) ], ' ' );
	
	//now follow the path back
	int subsequenceIndex = subsequence.length() - 1;
	int rowIndex = rows - 1;
	int colIndex = maxCol;

	while( matchArray[ GET_INDEX_2D( cols, rowIndex, colIndex ) ] > 0 )
	{
		if( matchArray[ GET_INDEX_2D( cols, rowIndex, colIndex ) ] == matchArray[ GET_INDEX_2D( cols, rowIndex, colIndex - 1 ) ] )
		{
			colIndex--;
		}
		else if( matchArray[ GET_INDEX_2D( cols, rowIndex, colIndex ) ] == matchArray[ GET_INDEX_2D( cols, rowIndex - 1, colIndex ) ] )
		{
			rowIndex--;
		}
		else
		{
			subsequence[ subsequenceIndex-- ] = pattern[ rowIndex - 1 ];
			rowIndex--;
			colIndex--;
		}
	}

	delete matchArray;

	return subsequence;
}


void StringAlgorithms::TestIsPatternInString( void )
{

}

//Using Boyer-Mayer??? you can get it down to a runtime of O(n)
//This algorithm allows you to skip to the next possible match
//First preprocess string to get a skip count for all characters
//Initial skip count is the length of the pattern
bool StringAlgorithms::IsPatternInString(const string & input, const string & pattern)
{
	//number of indicies to skip on invalid match
	int skipTable[256];

	//Create Skip Table
	//for( int i = 0; i <

    return false;
}

#endif // !STRING_ALGORITHMS_H__
