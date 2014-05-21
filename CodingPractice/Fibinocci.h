#pragma once

class Fibinocci
{
public:
    Fibinocci() {};
    ~Fibinocci() {};
public:
    int CalcFibRecursive( int seqNum );
    int CalcFibInterative( int seqNum );
};

// seq 0, 1, 1, 2, 3, 5, 8
// fib = sum of prev two numbers
//n = 0, fib = 0
//n = 1, fib = 1
//n = 2, fib = 1 + 0
//n = 3, fib = 1 + 1

int Fibinocci::CalcFibRecursive( int seqNum )
{

    if( seqNum == 0 )
    {
        return 0;
    }
    else if( seqNum == 1 )
    {
        return 1;
    }
    else if( seqNum > 1 )
    {
        return CalcFibRecursive( seqNum - 1 ) + CalcFibRecursive( seqNum - 2 );
    }
    else
    {
        return -1;
    }
}


int Fibinocci::CalcFibInterative( int seqNum )
{
    int fib1 = 1;
    int fib2 = 0;

    if( seqNum == 0 )
    {
        return 0;
    }
    else if( seqNum == 1 )
    {
        return 1;
    }

    while( --seqNum  > 1)
    {
        int fibCombine = fib1 + fib2;

        fib2 = fib1;
        fib1 = fibCombine;
    }

    return fib1 + fib2;
}
