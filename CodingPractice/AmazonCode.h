#ifndef __AMAZONCODE_H__
#define __AMAZONCODE_H__

class AmazonProductOfArray
{
publick
    AmazonProductOfArray( void );
    ~AmamzonProductOfArray( void );

public:
    /**************************/
    /* Assumptions:
    /* 1. Input array are signed integers
    /* 2. Output array are signed integers
    /* 3. Caller will handle freeing allocated memory
    /* 4. We are looking for the code optimize run time speed and memory usage
    /* 5. We will look for overflow considtions, returning a NULL pointer is a
    /*    adequete way to notifiy caller of issue
    /**************************/

    /************ DOXYGEN ****************/
    int * CalculateProductOfArray( const int& inputArray[] const, int size )
    {
        /* Considerations: 
        /* 1. Could calculate product of all integers in the array and then divide by inputArray[i]
        /* Pros: Less memory usage because there is no need for accumulator arrays
        /* Cons: we would have more overflow conditions using this method
        /*
        /* 2. Go through inputArray and accumlate the product 
        /*/

        int * productsOfArray = new int[size];
        int accumulatorHead;
        int accumulatorTail;

        for( int i = 0, accumulator = 1; i < size; i++ )
        {
            productsOfArray[i] *= accumulatorHead;
            productsOfArray[size - i - 1] = accumulatorTail;

            accumulatorHead *= inputArray[i];
            accumulatorTail *= inputArray[size - i - 1]
        }

        return productsOfArray;
    }
}

#endif