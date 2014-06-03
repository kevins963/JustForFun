#ifndef __RECURSION_ALGORITHMS_H
#define __RECURSION_ALGORITHMS_H

#include <vector>

#include "Utilities.h"
#include <string>
using namespace std;

typedef struct bitmap
{
	int* image;
	int width;
	int height;
} sBitmap;

typedef struct changeDenom
{
	int quarters;
	int dimes;
	int nickels;
	int pennies;

	changeDenom()
	{
		quarters = 0;
		dimes = 0;
		nickels = 0;
		pennies = 0;
	}
} sChangeDenom;

class RecursionAlgorithms
{

public:
	void TestAll( void );

	void TestGetAllSubsets( void );

	void TestGetAllParenthsesVariations( void );

	void TestFillPaint( void );

	vector<vector<int>> GetAllSubsets( vector<int> &set ); 

	string GetAllParenthsesVariations( int totalCount );
	
	void FillPaint( sBitmap& bitmap, int widthPos, int heightPos, int curColor, int newColor );

	void GetAllChangeCombinations( int currentAmount, int changeRequired, sChangeDenom currentCombo, vector<sChangeDenom>& combos );
	void TestGetAllChangeCombinations( void );
private:
	vector<vector<int>> BreakSubset( vector<int> &set );

	void InsertParenthese( int leftCount, int rightCount, int totalCount, string& outString, string& totalString );
};

/* 
Get all possible combonations for a given value

Ex: 6
P=6, P=1 N=1

Logic: recursively add smallest possible value and then next biggest
*/
void RecursionAlgorithms::GetAllChangeCombinations( int currentAmount, int changeRequired, sChangeDenom currentCombo, vector<sChangeDenom>& combos )
{
	if( currentAmount > changeRequired )
	{
		return;
	}
	else if( currentAmount == changeRequired )
	{
		combos.push_back( currentCombo );
	}

	/*
	1 2 3 4 5 6
	- 6
    6
	*/
	
	currentCombo.pennies++;
	GetAllChangeCombinations( currentAmount + 1, changeRequired, currentCombo, combos );
	currentCombo.pennies--;

	currentCombo.nickels++;
	GetAllChangeCombinations( currentAmount + 5, changeRequired, currentCombo, combos );
	currentCombo.nickels--;

	currentCombo.dimes++;
	GetAllChangeCombinations( currentAmount + 10, changeRequired, currentCombo, combos );
	currentCombo.dimes--;

	currentCombo.quarters++;
	GetAllChangeCombinations( currentAmount + 25, changeRequired, currentCombo, combos );
	currentCombo.quarters--;
}


void RecursionAlgorithms::TestGetAllChangeCombinations( void )
{
	vector<sChangeDenom> combos;
	GetAllChangeCombinations( 0, 6, sChangeDenom(), combos );

	cout << "<<<<<< TestGetAllChangeCombinations" << endl;
	for( vector<sChangeDenom>::iterator itr = combos.begin(); itr != combos.end(); itr++ )
	{
		cout << "P=" << itr->pennies << " N=" << itr->nickels << " D=" << itr->dimes << " Q=" << itr->quarters << endl; 
	}
}

void RecursionAlgorithms::TestFillPaint( void )
{
	int image[10][10];
	int size = sizeof(image) ;
	memset( image, 0, sizeof(image) );
	image[3][0] = 1;
	image[3][1] = 1;
	image[3][2] = 1;
	image[3][3] = 1;
	image[3][4] = 1;
	image[5][0] = 1;
	image[5][1] = 1;
	image[5][2] = 1;
	image[5][3] = 1;
	image[5][4] = 1;
	image[8][0] = 1;
	image[8][1] = 1;
	image[8][2] = 1;
	image[8][3] = 1;
	image[8][4] = 1;
	image[8][5] = 1;
	image[8][6] = 1;
	image[8][7] = 1;
	image[8][8] = 1;
	image[8][9] = 1;
	image[1][1] = 1;
	image[2][2] = 1;
	image[6][4] = 1;
	image[7][0] = 1;
	image[7][7] = 1;

	sBitmap bitmap;
	bitmap.image = (int*)image;
	bitmap.width = 10;
	bitmap.height = 10;
	cout << "<<<<<<Test FillPaint " << endl;

	cout << "input matrix" <<endl;
	PrintMatrix( bitmap.image, bitmap.width, bitmap.height );

	FillPaint( bitmap, 4, 5, bitmap.image[GetMatrixIndex(4, 5, bitmap.width)], 3 );
	PrintMatrix( bitmap.image, bitmap.width, bitmap.height );

	FillPaint( bitmap, 4, 4, bitmap.image[GetMatrixIndex(4, 4, bitmap.width)], 4 );
	PrintMatrix( bitmap.image, bitmap.width, bitmap.height );

	FillPaint( bitmap, 9, 9, bitmap.image[GetMatrixIndex(9, 9, bitmap.width)], 5 );
	PrintMatrix( bitmap.image, bitmap.width, bitmap.height );

}

void RecursionAlgorithms::FillPaint( sBitmap& bitmap, int widthPos, int heightPos, int curColor, int newColor )
{
	if( bitmap.image[GetMatrixIndex( widthPos, heightPos, bitmap.width)] != curColor )
	{
		return;
	}

	bitmap.image[GetMatrixIndex( widthPos, heightPos, bitmap.width)] = newColor;

	if( widthPos > 0 )
	{
		FillPaint( bitmap, widthPos - 1, heightPos, curColor, newColor );
	}

	if( widthPos < bitmap.width - 1 )
	{
		FillPaint( bitmap, widthPos + 1, heightPos, curColor, newColor );
	}
	
	if( heightPos > 0 )
	{
		FillPaint( bitmap, widthPos, heightPos - 1, curColor, newColor );
	}

	if( heightPos < bitmap.height - 1 )
	{
		FillPaint( bitmap, widthPos, heightPos + 1, curColor, newColor );
	}
}
/*
Create a string that gives out all possible parenthese combinations
input # of paranteses
ex
3 -> ((())) ()()() (())() ()(()) (()())
1 end results all seperate
2 all within each other

*/
string RecursionAlgorithms::GetAllParenthsesVariations( int totalCount )
{
	string parentesesString;
	string totalString;

	InsertParenthese( 0, 0, totalCount, parentesesString, totalString );

	return totalString;
}

void RecursionAlgorithms::InsertParenthese( int leftCount, int rightCount, int totalCount, string& outString, string& totalString )
{
	if( leftCount < totalCount )
	{
		outString.push_back( '{' );
		InsertParenthese( leftCount + 1, rightCount, totalCount, outString, totalString );
		outString.pop_back();

	}
	
	if( rightCount < leftCount )
	{
		outString.push_back( '}' );
		InsertParenthese( leftCount, rightCount + 1, totalCount, outString, totalString );
		outString.pop_back();
	}
	
	if( rightCount == totalCount )
	{
		totalString.append( outString.begin(), outString.end() );
		totalString.push_back( ' ' );
	}
}


void RecursionAlgorithms::TestAll( void )
{
	TestGetAllSubsets();
	TestGetAllParenthsesVariations();
	TestFillPaint();
	TestGetAllChangeCombinations();
}

void RecursionAlgorithms::TestGetAllParenthsesVariations( void )
{
	int t1 = 4;
	cout << "<<<<< Test GetAllParenthesesVariations " << endl;

	string outString = GetAllParenthsesVariations( t1 );
	
	cout << "Input = " << t1 << endl;
	cout << outString << endl;
	cout << "Total Possibilities = " << outString.size() / ( t1 * 2 + 1 ) << endl; 

}

void RecursionAlgorithms::TestGetAllSubsets( )
{
	int t1[] = {1,2,3,4};

	cout << "<<<< Testing Subsets " << endl;
	vector<int> v1( t1, t1 + sizeof( t1 ) / sizeof( t1[0] ) );

	vector<vector<int>> subsets = GetAllSubsets( v1 );

	for( vector<vector<int>>::iterator itr = subsets.begin(); itr != subsets.end(); itr++ )
	{
		PrintArray( *itr, true );
	}
}


/*
Get all subsets of a array
{1,2,3}
{
{1}, {2}, {3}
{1,2} {1,3} {2,3}
{2,3}

foreach item in array break apart in to all sub componetents
1, 2, 3
}
Use Recursion
*/
vector<vector<int>> RecursionAlgorithms::GetAllSubsets( vector<int> &set )
{
	vector<vector<int>> combinedSets;
	
	if( set.size() == 1 )
	{
		combinedSets.push_back( set ); 
	}
	else
	{
		/* Combine all subsets with current value */
		vector<int> subSet;
		subSet.insert( subSet.begin(), set.begin() + 1, set.end() );
		vector<vector<int>> allSubSets = GetAllSubsets( subSet );
		
		int currentValue = set[0];
		combinedSets.push_back( vector<int>( 1, currentValue ) );
		combinedSets.insert( combinedSets.end(), allSubSets.begin(), allSubSets.end() );
		for( vector<vector<int>>::iterator itr = allSubSets.begin(); itr != allSubSets.end(); itr++ )
		{
			vector<int> combined;
			combined.push_back( currentValue );
			combined.insert( combined.end(), itr->begin(), itr->end() );
			combinedSets.push_back( combined );
		}
	}

	/*
	vector<vector<int>> combinedSets;

	for( int i = 0; i < set.size() - 1; i++ )
	{
		vector<int> v1 = vector<int>( set.begin() + i + 1, set.end() );
		
		vector<vector<int>> sets = BreakSubset( v1 );

		for( vector<vector<int>>::iterator itr = sets.begin(); itr != sets.end(); itr++ )
		{
			vector<int> combine;
			combine.push_back( set[i] );
			combine.insert( combine.end(), itr->begin(), itr->end() );
			combinedSets.push_back( combine );
		}
	}

	*/
	return combinedSets;
}

vector<vector<int>> RecursionAlgorithms::BreakSubset(vector<int> &set )
{
	vector<vector<int>> allSets;
	allSets.push_back( set );
	vector<int> vectorPopItem = vector<int>( set.begin(), set.begin() + 1 );
	vector<int> vectorHeadSet = vector<int>( set.begin() + 1, set.end() );
	
	allSets.push_back( vectorPopItem );
	//allSets.push_back( vectorHeadSet );

	if( set.size() > 2 )
	{
		vector<vector<int>> breakSets = BreakSubset( vectorHeadSet );

		allSets.insert( allSets.end(), breakSets.begin(), breakSets.end() );
	}
	else
	{
		allSets.push_back( vectorHeadSet );
	}

	return allSets;
}

#endif