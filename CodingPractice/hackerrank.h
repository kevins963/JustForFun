#ifndef hackerrank_h__
#define hackerrank_h__
 

class Hackerrank
{
public:
    void TestAll();

    /* Dynamic */
    void TestDortmundsDilemma( void );
    int DortmundsDilemma( int nameLength, int numUniqueLetters );
    int DortmundsDilemmaCombine( char* str, int nameLength, int numUniqueLetters, int currentLength, int currentUniqueLetters, int letterPos );
	int DortmundsDilemmaCombine( char* str, const int nameLength, const int uniqueLetterTarget, int strPos, int strCount, int totalUniqueLetters );
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
int Hackerrank::DortmundsDilemma( int nameLength, int numUniqueLetters )
{
    
    char* str = new char[nameLength + 1];
    // Check that name length is greater than unique letters
    // Create empty string of length nameLength
    // Recursively add current letter and start from beginning then add next letter
    int total = DortmundsDilemmaCombine( str, nameLength, numUniqueLetters, 0, 0, 0 );

    delete str;

    return total;
}

/*
check if invalid
 return 0
check if ready to evaluate
 return 1 or 0

 for each letter index 0 -> Length / 2 make suffix/prefix out of current index
 ex length = 4 , currentLength = 1, s[0], p[3]
 Find all combos in between

*/
int Hackerrank::DortmundsDilemmaCombine( char* str, const int nameLength, const int uniqueLetterTarget, int strPos, int strCount, int totalUniqueLetters )
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
int Hackerrank::DortmundsDilemmaCombine( char* str, int nameLength, int numUniqueLetters, int currentLength, int currentUniqueLetters, int letterPos )
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
        int result = DortmundsDilemma( itr->k, itr->n );

        cout << "k = " << itr->k << " n = " << itr->n << " expected = " << itr->r << " actual = " << result << endl;
    }
}

void Hackerrank::TestAll()
{
    TestDortmundsDilemma();
}



#endif /* hackerrank_h__ */