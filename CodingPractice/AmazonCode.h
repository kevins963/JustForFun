/**
* Additional information request by Amazon
*
* Assumptions:
* 1. Input array are signed integers
* 2. Output array are signed integers
* 3. Caller will handle freeing allocated memory from the returned array
* 4. The code should optimize run time and space usage
* 5. Overflow conditions are not handled within this code
*
* Complexities Analysis:
* 1. Run time performance is
*  Average (n)
*  Worst (n)
* 2. Space performance
*  Average (n)
*  Worst (n)
*
*  The run time performance is always N for this solution.  The algorithm
*  loops the input array from 0 -> N and N -> 0 to calculate the accumulate
*  the product of all integers in the array.  So the run time will grow at a
*  constant rate according the the size of the input array.  Ex: the run time
*  will double when the array doubles in size.
*
*  The space performance is always N for this solution.  The only memory usage
*  that changes is output array which is the same size the input array
*  all other variables used to calculate the products of array do not change with
*  the size of the input array
*/

/**
* \class AmazonProductOfArray
*
* \brief This class is used for calculating the products of array
*
* This class contains the method used for calculating an array
* of integers that are the product of all integers in an input
* array except for the value at the current index
*
* \author Kevin Stichter
*
* \date 2014/05/18
*
*/

#ifndef AMAZON_PRODUCT_OF_ARRAY_H__
#define AMAZON_PRODUCT_OF_ARRAY_H__

/* Includes */
#include <iostream>
#include <stdint.h>

using namespace std;

class AmazonProductOfArray
{
public:
	/* Default constructor */
	AmazonProductOfArray(void) {};

	/* Default destructor */
	~AmazonProductOfArray(void) {};

public:

	/**
	* CalculateProductOfArray() - This method calculates an array of integers whose
	* values are the product of every other integer excluding the current index of
	* the input array.
	*
	* \param const int32_t * inputArray
	*   The parameter inputArray is an array of integers that will be used to calculate
	*   the products of array
	*
	* \param int32_t size
	*   The parameter size is the length of the inputArray
	*
	* \return int32_t *
	*   This method return a pointer to an array of integers which are the product of
	*   every other integer of the inputArray excluding the current index of the array.
	*   The output array is the same size as the input array.  The array's allocated
	*   memory will need to be freed by the caller.
	*/
	int32_t * CalculateProductOfArray(const int32_t* inputArray, int32_t size);
};

int32_t * AmazonProductOfArray::CalculateProductOfArray(const int32_t* inputArray, int32_t size)
{
	/* productOfArray this array is used to store to product of integers for the */
	/* input array                                                               */
	int32_t * productsOfArray = new int32_t[size];

	/* accumulator is a temp variable used to accumulate the product of integers */
	/* from the inputArray                                                       */
	int32_t accumulator;

	/* accumulator accumulates the product of all values in the inputArray less */
	/* than i                                                                   */
	accumulator = 1;

	for (int32_t i = 0; i < size; i++)
	{
		productsOfArray[i] = accumulator;
		accumulator *= inputArray[i];
	}

	/* accumulator accumulates the product of all values in the inputArray     */
	/* greater than i and combines it was the previous accumulation, resulting */
	/* the the total product all other values in the array except for          */
	/* inputArray[i]                                                           */
	accumulator = 1;
	for (int32_t i = size - 1; i >= 0; i--)
	{
		productsOfArray[i] *= accumulator;
		accumulator *= inputArray[i];
	}

	return productsOfArray;
}
}

#endif