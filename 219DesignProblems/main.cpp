#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <sstream>

using namespace std;

int MatchString( string inputString, string testString );

/*
    difficulty medium
    skills: knowing how to solve dynamic programming problems, ideally would want to use a lookback array in a bottom up approach
    Special test cases (1, 5, 10, 25) is not best input because they are all multiples of each other, so any value greater than 25
    would be optimal to use the largest value coins first.
    try using denomiations of (1, 4, 5) with the test case 8, its better to use 4,4 instead of 5,1,1,1 (largest value is not always the best answer)

*/
int MinCoins(const int * coins, int coinSize, int value)
{
    int retVal;
    int *minCoinsArray = new int[value + 1];

    minCoinsArray[0] = 0;

    //Use bottom up approach, start with simple and build to the complex
    for (int currentValue = 1; currentValue <= value; ++currentValue)
    {
        int minCoins = INT_MAX;

        //Test each coins value
        for (int coinIndex = 0; coinIndex < coinSize; ++coinIndex)
        {
            if (currentValue - coins[coinIndex] >= 0)
            {
                int lookbackIndex = currentValue - coins[coinIndex];
                minCoins = (minCoins > minCoinsArray[lookbackIndex] + 1) ? minCoinsArray[lookbackIndex] + 1 : minCoins;
            }
        }

        //Set min value
        minCoinsArray[currentValue] = minCoins;
    }

    retVal = minCoinsArray[value];
    delete[] minCoinsArray;

    return retVal;
}

void TestMinCoins()
{
    vector<pair<int, int>> tests;
    int coins[3] = { 1,3,4 };

    tests.push_back(make_pair<int, int>(1, 1));
    tests.push_back(make_pair<int, int>(2, 2));
    tests.push_back(make_pair<int, int>(3, 1));
    tests.push_back(make_pair<int, int>(4, 1));
    tests.push_back(make_pair<int, int>(5, 2));
    tests.push_back(make_pair<int, int>(6, 2));
    tests.push_back(make_pair<int, int>(7, 2));
    tests.push_back(make_pair<int, int>(8, 2));
    tests.push_back(make_pair<int, int>(9, 3));
    tests.push_back(make_pair<int, int>(10, 3));

    for (auto itr = tests.begin(); itr != tests.end(); ++itr)
    {
        int input = itr->first;
        int expected = itr->second;
        int result = MinCoins(coins, 3, input);

        cout << "input " << input << ": " << expected << " == " << result << endl;
    }
}

/*
    difficulty: medium-easy
    skills: binary search, problem solving using basic algorithm principles (binary search) on problems that are not obvious for implementation
*/
double FindSqrt(double value)
{
    int itrCount = 0;

#define ESP (0.00001f)

    double low;
    double mid;
    double high;
    double testSqrt;

    //Special case
    if (value < 0)
    {
        return -1;
    }
    //Start point for less than one
    else if( value < 1 )
    {
        low = value;
        high = 1;
    }
    //Start point for greater than one
    else
    {
        low = 0;
        high = value;
    }


    //Inital state
    mid = (low + high) / 2;
    testSqrt = mid * mid;

    while (low <= high && fabs(testSqrt - value) > ESP)
    {
        //min is too big
        if (testSqrt >= value)
        {
            high = mid;
        }
        //min is too small
        else if (testSqrt < value)
        {
            low = mid;
        }

        //Evaluate
        mid = (low + high) / 2;
        testSqrt = mid * mid;
        itrCount++;
    }
    cout << "Runtime = " << itrCount << endl;

    return mid;
}

double FindSqrt2( double value )
{
    int itrCount = 0;
    const double EPS = 0.000001;

    double root = value;
    double test = root * root;

    //while( fabs( test - value ) > EPS )
    //{
    //    if( test >= value )
    //    {
    //        root /= 2;
    //    }
    //    else
    //    {
    //        root *= 1.5;
    //    }
    //    test = root * root;
    //    itrCount++;
    //}

    cout << "Runtime = " << itrCount << endl;

    return root;
}

void TestSqrt()
{
    cout << "TEST Sqrt" << endl;

    vector<pair<double, double>> tests;

    tests.push_back( make_pair<double, double>( 0.01f, 0.1f ) );
    tests.push_back( make_pair<double, double>( 0.5f, 0.7071f ) );
    tests.push_back( make_pair<double, double>( 4, 2 ) );
    tests.push_back(make_pair<double, double>(16, 4));
    tests.push_back(make_pair<double, double>(100, 10));
    tests.push_back( make_pair<double, double>( 1000000, 1000 ) );
    //tests.push_back( make_pair<double, double>( 1234, 1111.111f ) );

    for (auto itr = tests.begin(); itr != tests.end(); ++itr)
    {
        double input = itr->first;
        double expected = itr->second;

        double result = FindSqrt( input );
        cout << "input1 " << input << ": " << expected << " == " << result << endl;

        double result2 = FindSqrt2( input );
        cout << "input2 " << input << ": " << expected << " == " << result << endl << endl;
    }
}

/* difficulty: medium
    key concepts: binary search, problem solving skills for implementing known algorithm on non-standard problem
*/
int FindIndexRotatedArray(const int * inputArray, int size, int findValue)
{
    //rotated array, same binary search but should know if mid is on upper or lower side of array of sorted array

    int low, mid, high;

    low = 0;
    high = size - 1;

    mid = (low + high) / 2;

    while (low <= high && 
           inputArray[mid] != findValue)
    {
        //Check if mid is on the sorted lower half
        if (inputArray[low] <= inputArray[mid])
        {
            if (inputArray[low] <= findValue && inputArray[mid] > findValue)
            {
                //normal search
                high = mid - 1;
            }
            else
            {
                //reversed because on rotated section
                low = mid + 1;
            }
        }
        //mid is in a sorted upper half
        else
        {
            if (inputArray[high] >= findValue && inputArray[mid] < findValue)
            {
                //normal search
                low = mid + 1;
            }
            else
            {
                //reversed because it is on rotated side
                high = mid - 1;
            }
        }
        //Recalculate mid
        mid = (low + high) / 2;
    }
    
    if (high >= low)
    {
        return mid;
    }

    return -1;
}

void TestRotatedArray()
{
    int inputArray[] = { 8, 9, 10, 11, 1, 2, 3, 4, 5, 6, 7 };
    int inputArray1[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    int size = 11;

    for (int i = 0; i < 11; i++)
    {
        int input = i + 1;
        int expected = (i + 4) % size;
        int result = FindIndexRotatedArray(inputArray, size, input);
        cout << "input " << input << ": " << expected << " == " << result << endl;
    }

    for (int i = 0; i < 11; i++)
    {
        int input = i;
        int expected = i;
        int result = FindIndexRotatedArray(inputArray1, size, input);
        cout << "input " << input << ": " << expected << " == " << result << endl;
    }
}

int QuickSelectPartition(int * items, int leftIndex, int rightIndex, int pivotIndex)
{
    /* this partition assumes right index is also the pivoting vlaue */

    //go through entire array and just swap so the all values less than pivot will be on left */

    swap(items[rightIndex], items[pivotIndex]);
    int numberOfLessValues = 0;
    for (int currentIndex = leftIndex; currentIndex < rightIndex; ++currentIndex)
    {
        if (items[currentIndex] < items[rightIndex])
        {
            //swap
            swap(items[leftIndex + numberOfLessValues], items[currentIndex]);
            numberOfLessValues++;
        }
    }

    swap(items[leftIndex + numberOfLessValues], items[rightIndex]);

    return leftIndex + numberOfLessValues;
}

int QuickSelect( int * items, int startIndex, int stopIndex, int selectValueKth )
{
    cout  << "[";
    for (int i = 0; i < 12; i++)
    {
        cout << " " << items[i];
        if (i == (startIndex + stopIndex) / 2)
        {
            cout << "*";
        }
    }
    cout << "]" << endl;

    /* qucik selec same at quick sort, fast average time */
    /* [5 1 4 2 3 ], kth = 2, keep pivoting until you pivot index is kth value */
    /* p=3 [1,2,]3[,5,4] -> decrease right */

    //get first pivot

    int pivotIndex = QuickSelectPartition( items, startIndex, stopIndex, (startIndex + stopIndex)/2 );

    //If partition is too large try decreasing right side
    if( pivotIndex > selectValueKth )
    {
        //all values on right is bigger than kth value so set right = pivot - 1
        return QuickSelect(items, startIndex, pivotIndex - 1, selectValueKth);
    }
    else if( pivotIndex < selectValueKth )
    {
        //too small so set start index = pivot + 1
        return QuickSelect(items, pivotIndex + 1, stopIndex, selectValueKth);
    }
    else if( pivotIndex == selectValueKth )
    {
        return items[pivotIndex];
    }
};


void TestQuickSelect()
{
    int testArray[] = {3,2,10,5,9,7,6,4,8,0,11,1};
    int copyArray[12];

    for( int i = 0; i <= 11; i++)
    {
        copy(testArray, testArray+12, copyArray);

        int input = i;
        int expected = i;
        int result = QuickSelect( copyArray, 0, 11, i );

        cout << "QS: " << expected << " == " << result << endl;
    }
}


void TestMatchString()
{
    cout << "TEST MATCH STRING" << endl;

    string inputString = "this is a string that can have a number of matches and potentially submatches as well";
    string matchString = "that";

    int index = MatchString( inputString, matchString );

    if( index == -1 )
    {
        cout << "No Match" << endl;
    }
    else
    {
        for( int i = 0; i < inputString.length(); i++ )
        {
            if( i == index )
            {
                cout << "^";
            }
            cout << inputString[i];
        }
        cout << endl;
    }
}

/*Match String should efficiently match a string in another string
precalculate jump distance and get close to a runtime N
jump condition should be the first occurrence of a letter in the string 
*/

int MatchString( string inputString, string testString )
{
    int totalCount = 0;
    int matchIndex = -1;

    int jumpTable[256] = {-1};

    for( int i = 0; i < 256; i++ )
    {
        jumpTable[i] = -1;
    }

    for( int jumpIndex = 0; jumpIndex < testString.size(); jumpIndex++ )
    {
        jumpTable[ testString[jumpIndex] ] = jumpIndex;
    }

    
    for( int i = 0; i < inputString.size() && matchIndex == -1; i++ )
    {
        int matchCount = 0;

        for( int j = testString.size() - 1; j >= 0; --j )
        {
            totalCount++;

            if( testString[j] == inputString[i + j] )
            {
                ++matchCount;
            }
            else
            {
                //incorrect match, use jump table
                //want to align input letter with letter in match index, if not in jump table can skip full string
                int jumpCount;

                if( jumpTable[inputString[i+j]] == -1 )
                {
                    //not possible match just move to first letter
                    jumpCount = j;
                }
                else if( jumpTable[inputString[i+j]] < j )
                {
                    jumpCount = j - jumpTable[inputString[i+j]];
                }
                else
                {
                    //we passed the jump table so unknown
                    jumpCount = 0;
                }

                i+=jumpCount;
                
                cout << "jumpcount" << jumpCount << endl;
            }
        }

        cout << "matchcount" << matchCount << endl;

        if( matchCount == testString.size() )
        {
            matchIndex = i;
        }
    }

    cout << "totoal count = " << totalCount << endl;

    return matchIndex;
}

int main()
{
    TestMinCoins();
    TestSqrt();
    TestRotatedArray();
    TestQuickSelect();
    TestMatchString();

    while (1);
}