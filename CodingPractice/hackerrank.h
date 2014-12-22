#ifndef hackerrank_h__
#define hackerrank_h__
 

class Hackerrank
{
public:
    void TestAll();

    /* Dynamic */
    void TestDortmundsDilemma( void );
    //int DortmundsDilemma( int nameLength, int numUniqueLetters );
    //int DortmundsDilemmaCombine( char* str, int nameLength, int numUniqueLetters, int currentLength, int currentUniqueLetters, int letterPos );
	//int DortmundsDilemmaCombine( char* str, const int nameLength, const int uniqueLetterTarget, int strPos, int strCount, int totalUniqueLetters );

	void TestPlayGame( void );
	int PlayGame( vector<int> blocks );
	int CalculateMaxScore( vector<int> & rBlocks, vector<int> &rMaxScores, int currentPosition, int totalSum );

	void TestEqual( void );
	int Equal( vector<int> values );
	int EqualGetMinIterations(vector<int>& rValues, int* countGiven, int minIterations, int currentIterations );

	/*
	Rank: 28575 Score: 102.00 
	Palindrome Index 
	• Problem
	• Submissions
	• Leaderboard
	• Discussions
	• Editorial 
	Problem Statement
	Russian
	You are given a string of lowercase letters. Your task is to figure out the index of the character on whose removal will make the string a palindrome. There will always be a valid solution. 

	In case string is already palindrome, then -1 is also a valid answer along with possible indices.
	Input Format 
	The first line contains T i.e. number of test cases.
	T lines follow, each line containing a string. 
	Output Format 
	Print the position ( 0 index ) of the letter by removing which the string turns into a palindrome. For string, such as 
	bcbc
	we can remove b at index 0 or c at index 3. Both the answers are accepted. 
	Constraints 
	1 ≤ T ≤ 20 
	1 ≤ length of string ≤ 100005 
	All characters are latin lower case indexed. 
	Sample Input #00 
	3	aaab	baa	aaa
	Sample Output #00 
	3	0	0
	Explanation 
	In the given input, T = 3, 
	• For input aaab, we can see that removing b from the string makes the string a palindrome, hence the position 3. 
	• For input baa, removing b from the string makes the string palindrome, hence the position 0. 

	As the string aaa is already a palindrome, you can output 0, 1 or 2 as removal of any of the characters still maintains the palindrome property. Or you can print -1 as this is already a palindrome. 
	*/
	void TestPalindroneIndex( void );
	int PalindroneIndex( string inputString );
};


/*
1 Create a list of all possible name combonations using only lower alpha charactors
2 Name must be N (nameLength) long
3 Name must have K (numUniqueLetters) 
4 Prefix and Suffix must be same

example:
N = 3, K = 2
aba, bcb, cdc, ...

*/
static char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
static const int LETTER_SIZE = 26;
/*int Hackerrank::DortmundsDilemma( int nameLength, int numUniqueLetters )
{
    
    char* str = new char[nameLength + 1];
    // Check that name length is greater than unique letters
    // Create empty string of length nameLength
    // Recursively add current letter and start from beginning then add next letter
    int total = DortmundsDilemmaCombine( str, nameLength, numUniqueLetters, 0, 0, 0 );

    delete str;

    return total;
}
*/
/*
check if invalid
 return 0
check if ready to evaluate
 return 1 or 0

 for each letter index 0 -> Length / 2 make suffix/prefix out of current index
 ex length = 4 , currentLength = 1, s[0], p[3]
 Find all combos in between

*/
/*int Hackerrank::DortmundsDilemmaCombine( char* str, const int nameLength, const int uniqueLetterTarget, int strPos, int strCount, int totalUniqueLetters )
{
	int total = 0;

	if( strCount > nameLength )
	{
		return 0;
	}

	if( strCount == nameLength )
	{
		if( uniqueLetterTarget == totalUniqueLetters )
		{
			return 1;
		}

		return 0;
	}

	for( int i = 0; i < LETTER_SIZE; i++)
	{
		char isUnique = 1;
		for( int index = 0; index <= strPos && isUnique; index++ )
		{
			if( letters[i] == str[index] )
			{
				isUnique = 0;
			}
		}	

		str[strPos] = letters[i];

		//Try next position in the string
		total += DortmundsDilemmaCombine( str, nameLength, uniqueLetterTarget, strPos + 1, (strPos + 1) * 2, totalUniqueLetters + isUnique );
	}

	return total;
	
}
*/

/*int Hackerrank::DortmundsDilemmaCombine( char* str, int nameLength, int numUniqueLetters, int currentLength, int currentUniqueLetters, int letterPos )
{
	int total = 0;
    //if ready to evaluate check 
    if( currentLength > nameLength )
    {
        return 0;
    }

    //Now recursively try next letter if you can

	for( int i = 0; i < LETTER_SIZE; i++)
	{
		char isUnique = 1;
		for( int index = 0; index < currentLength && isUnique; index++ )
		{
			if( letters[letterPos] == str[index] )
			{
				isUnique = 0;
			}
		}	

		str[currentLength] = letters[letterPos];

		//Try next position in the string
		total += DortmundsDilemmaCombine( str, nameLength, numUniqueLetters, currentLength + 1, currentUniqueLetters + isUnique, 0 );
	}

	if( currentLength == nameLength )
	{
		if( currentUniqueLetters == numUniqueLetters )
		{
			str[nameLength] = '\0';
			cout << str << endl;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	return total;
}
*/
struct Dortmunds
{
    Dortmunds( int k, int n, int r )
    {
        this->k = k;
        this->n = n;
        this->r = r;
    }
    int k;
    int n;
    int r;
};

void Hackerrank::TestDortmundsDilemma( void )
{
    cout << "**************TestDortmundsDilemma" << endl;

    vector<Dortmunds> tests;
    //tests.push_back( Dortmunds( 1, 1, 0 ) );
    //tests.push_back( Dortmunds( 2, 1, 26 ) );
	//tests.push_back( Dortmunds( 4, 2, 2600 ) );
	tests.push_back( Dortmunds( 3, 2, 650 ) );

    for ( auto itr = tests.begin(); itr != tests.end(); ++itr )
    {
        int result = 0;//= DortmundsDilemma( itr->k, itr->n );

        cout << "k = " << itr->k << " n = " << itr->n << " expected = " << itr->r << " actual = " << result << endl;
    }
}

void Hackerrank::TestAll()
{
    TestDortmundsDilemma();
	TestPlayGame();
	TestEqual();
	TestPalindroneIndex();
}


void Hackerrank::TestPlayGame(void)
{
	cout << "-----------TestPlayGame----------" << endl;
	int t1[] = {999, 1, 1, 1, 0};
	int t2[5] = {0,1,1,1,999};

	vector<pair<int, vector<int>>> tests;

	tests.push_back( make_pair( 1001, vector<int>( t1, t1 + 5 )));
	tests.push_back( make_pair( 999, vector<int>( t2, t2 + 5 )));

	for( auto itr = tests.begin(); itr != tests.end(); itr++)
	{
		int result = PlayGame( itr->second );
		cout << "expected " << itr->first << " result " << result << endl;
	}
}

/*
Giving a set a blocks you can remove 1, 2, or 3 blocks, your score is indicated by 
the number on the block.  You want to maximize your score.  The other player will also try
optimize their score.

Develop an algorithm to get max score in the game, assuming you will always go first

1, 1, 1, 10, 1

use recursion to choose each block and then keep the max score of each choice
position will always have a maximimum score, so using recursion would repeat
a lot of the same score.  Use an index and work backwords and save the max score in each 
position
it is the sum of all blocks removed added to score

GetMaxScore
player1_currentIndex = currentPosition
player2_moveIndex = get index of max score from next 1-3 position
player1_nextMove = get index of max score from player2_moveIndex + 1-3
*/

int Hackerrank::PlayGame(vector<int> blocks )
{
	vector<int> maxScores( blocks.size(), -1 );

	//from last to first index get max score for current index

	int totalSum = 0;
	for( int maxScoreIndex = blocks.size(); maxScoreIndex > 0; --maxScoreIndex )
	{
		totalSum += blocks[maxScoreIndex-1];
		maxScores[maxScoreIndex-1] = CalculateMaxScore( blocks, maxScores, maxScoreIndex - 1, totalSum );
	}

	return maxScores[0];
}

// 1    1    0    1   1    1    999  1   1
// 1003 1002 1001 3   1001 1001 1001 2   1 
int Hackerrank::CalculateMaxScore( vector<int> & rBlocks, vector<int> &rMaxScores, int currentPosition, int totalSum )
{
	int maxScore;

	int maxIndex = rBlocks.size();

	int player2Index = -1;
	
	int player1Index = -1;

	//try index 0, minus sum of next maxget

	//Test each of the block combo sum[0, 1, 2]
	int getMaxScore = 0;

	for( int i = currentPosition; i < currentPosition + 3 && i < rBlocks.size(); ++i )
	{
		//Find max of next players move and then you can get the total remaining
		int maxForCurrentIndex = 0;

		if( ( i + 1 ) < rBlocks.size() )
		{
			maxForCurrentIndex = rMaxScores[i+1];
		}

		if( totalSum - maxForCurrentIndex > getMaxScore )
		{
			getMaxScore = totalSum - maxForCurrentIndex;
		}
	}

	return getMaxScore;
}

/*
Goal: make the array so that all values are equal
1. each person starts off with a certain value
2. you can give everyone except one person either 1, 2 or 5

Solving:
1. arrange data so that initial value arrange with smallest difference first
2. start off by adding one, you can always solve the solution by that way which
 will be the slowest if other solutions are available
3. once solved get the current max value
4. iteratively try adding the next smallest value, cancel if number of moves
 is greater than the current min
5. return the min number of moves
6. Similar to the coin
*/

#define ONES 0
#define TWOS 1
#define FIVES 2

void Hackerrank::TestEqual( void )
{
	//arrray is setup as expected, size and array
	int t1[] = {1,2,3};
	int t2[] = {5};
	int t3[] = {0,5};
	int t4[] = {0, 12, 6};//5, 12, 11(1)|10,17,11(1)|11,18,11(1) | 16,18,16(1) | 18,,18,18(2)

	vector<pair<int,vector<int>>> tests;
	tests.push_back( make_pair<int,vector<int>>( 2, vector<int>( t1, t1+3) ) );
	tests.push_back( make_pair<int,vector<int>>( 0, vector<int>( t2, t2+1) ) );
	tests.push_back( make_pair<int,vector<int>>( 1, vector<int>( t3, t3+2) ) );
	tests.push_back( make_pair<int,vector<int>>( 5, vector<int>( t4, t4+3) ) );

	for( auto itr = tests.begin(); itr != tests.end(); itr++ )
	{
		int expected = itr->first;
		int result = Equal( itr->second );
		cout << "expected = " << expected << " result = " << result << endl;
	}
}

int Hackerrank::Equal(vector<int> values)
{
	int countGiven[3];
	
	//sort as 
	
	//get the 
	int currentIterations = 0;
	int minIteration = EqualGetMinIterations( values, countGiven, -1, 0 );


	int testMinIterationIndex = -1;

	do 
	{
		int testMinIteration;
		testMinIterationIndex = -1;

		for( int i = 0; i < values.size(); i++ )
		{
			values[i] -= 5;

			testMinIteration = EqualGetMinIterations( values, countGiven, -1, 0 ) + currentIterations + 1;

			if( testMinIteration < minIteration )
			{
				minIteration = testMinIteration;
				testMinIterationIndex = i;
			}

			values[i] += 5;

		}

		if(testMinIterationIndex != -1)
		{
			currentIterations++;
			values[testMinIterationIndex] -= 5;
		}

	} while (testMinIterationIndex != -1);

	do 
	{
		int testMinIteration;
		testMinIterationIndex = -1;

		for( int i = 0; i < values.size(); i++ )
		{
			values[i] -= 2;

			testMinIteration = EqualGetMinIterations( values, countGiven, -1, 0 ) + currentIterations + 1;

			if( testMinIteration < minIteration )
			{
				minIteration = testMinIteration;
				testMinIterationIndex = i;
			}

			values[i] += 2;

		}

		if(testMinIterationIndex != -1)
		{
			currentIterations++;
			values[testMinIterationIndex] -= 5;
		}

	} while (testMinIterationIndex != -1);

	return minIteration;
}

int Hackerrank::EqualGetMinIterations(vector<int>& rValues, int* countGiven, int minIterations, int currentIterations)
{

	//Get fastest using only ones, which would be the sum of difference between current value and min value
	vector<int> diff( rValues.size(), 0 );

	//1. find min value
	int minValue = rValues[0];
	
	for( int minIndex = 1; minIndex < rValues.size(); minIndex++ )
	{
		if( rValues[minIndex] < minValue )
		{
			minValue = rValues[minIndex];
		}
	}

	int totalSum = 0;
	//using min value find total sum
	for( int i = 0; i < rValues.size(); i++ )
	{
		totalSum += ( rValues[i] - minValue );
	}

	return totalSum;
}

void Hackerrank::TestPalindroneIndex(void)
{
	cout << "**************** TestPalindroneIndex ********************" << endl;
	vector<pair<int,string>> test;

	test.push_back( make_pair<int,string>( -1, std::string("aa") ) );
	test.push_back( make_pair<int,string>( -1, string("aaa") ) );
	test.push_back( make_pair<int,string>( -1, string("aba") ) );
	test.push_back( make_pair<int,string>( -1, string("abba") ) );
	test.push_back( make_pair<int,string>( 0, string("cabba") ) );
	test.push_back( make_pair<int,string>( 1, string("acbba") ) );
	test.push_back( make_pair<int,string>( -1, string("abcba") ) );
	test.push_back( make_pair<int,string>( 3, string("abbca") ) );
	test.push_back( make_pair<int,string>( 4, string("abbac") ) );
	test.push_back( make_pair<int,string>( 0, string("caba") ) );
	test.push_back( make_pair<int,string>( 1, string("acba") ) );
	test.push_back( make_pair<int,string>( 1, string("abca") ) );
	test.push_back( make_pair<int,string>( 3, string("abac") ) );

	for ( auto itr = test.begin(); itr != test.end(); itr++ )
	{
		string input = itr->second;
		int result = PalindroneIndex( input );
		int expected = itr->first;

		string pass = ( expected == result ) ? " PASS " : " FAIL ";

		cout << " intput " << input << " expected = " << expected << " result = " << result << pass << endl;
	}
}

/*
Create a palidrone out of the string, if already a palindrone return -1 else return the
index of a single letter that needs to be returned to make it a palindrone

Solution:
1) start at ends go towards center until error
2) on error test next on both to see which one is errored

aa, L, H 0,1 same ret -1
aaa L, H (0,2)same, 1,1 same ret -1
abbac = (0,4) a,c, error 1,4 = b,c error, 0,3 = aa, good 4 is index

2)
aab
midL,midH = 1, (1,1) same, (0,2) error, check which one should be removed
if(midH-1 == midL) return midH
if( midL+1 == midH )return midL
*/
int Hackerrank::PalindroneIndex(string inputString)
{
	
	int errorIndex = -1;
	int lower = 0;
	int upper = inputString.length() - 1;

	while( (errorIndex == -1) && (lower < upper) )
	{
		if( inputString[ lower ] != inputString[ upper ] )
		{
			if( inputString[ lower + 1 ] == inputString[ upper ] )
			{
				errorIndex = lower;
			}
			else if( inputString[ lower ] == inputString[ upper - 1 ] )
			{
				errorIndex = upper;
			}
		}
		lower++;
		upper--;
	}
	
	return errorIndex;
}


#endif /* hackerrank_h__ */