#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

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

	low = 0;
	high = value;

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
	}
	
	return mid;
}

void TestSqrt()
{
	vector<pair<double, double>> tests;

	tests.push_back(make_pair<double, double>(4, 2));
	tests.push_back(make_pair<double, double>(16, 4));
	tests.push_back(make_pair<double, double>(100, 10));
	tests.push_back(make_pair<double, double>(1000000, 1000));

	for (auto itr = tests.begin(); itr != tests.end(); ++itr)
	{
		double input = itr->first;
		double expected = itr->second;
		double result = FindSqrt(input);

		cout << "input " << input << ": " << expected << " == " << result << endl;
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
int main()
{
	TestMinCoins();
	TestSqrt();
	TestRotatedArray();


	while (1);
}