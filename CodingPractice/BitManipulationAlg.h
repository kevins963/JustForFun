#ifndef __BIT_MANIPULATION_ALG_H
#define __BIT_MANIPULATION_ALG_H

#include <stdint.h>
#include <iomanip>

using namespace std;

class BitManipulationAlg
{
public:
    void TestAll( void );
    
    void TestCombineBitRange( void );
    uint32_t CombineBitRange( uint32_t N, uint32_t M, uint32_t upperRangeBit, uint32_t lowerRangeBit );

    void TestBasicBitManipulation( void );
    void BasicBitManipulation( void );

    void TestCountBits( void );
    int CountBits( uint32_t value );
private:
};

void BitManipulationAlg::TestAll( void )
{
    TestCombineBitRange();
    TestBasicBitManipulation();
    TestCountBits();
}


void BitManipulationAlg::TestCombineBitRange( void )
{
    uint32_t t1[4] = { 0xA000, 0x000A, 8, 4 };

    uint32_t e1 = 0xA0A0;

    cout << "<<<<<< TestCombineBitRange " << endl;

    
    cout << "expected = " << hex << e1 << endl;
    cout << "result   = " << hex << CombineBitRange( t1[0], t1[1], t1[2], t1[3] ) << endl;

}

uint32_t BitManipulationAlg::CombineBitRange( uint32_t N, uint32_t M, uint32_t upperRangeBit, uint32_t lowerRangeBit )
{

    uint32_t k = upperRangeBit - lowerRangeBit;
    uint32_t mask=0;

    while( k-- )
    {
        mask = ( ( mask << 1 ) | 1 );
    }

    N = ( N | ( ( M & mask ) << lowerRangeBit ) );

    return N;
}

void BitManipulationAlg::BasicBitManipulation(void)
{
    uint16_t value;

    //Clear bit
    value = 0xFFFF & ~0x0001;
    printf( "0xFFFF & ~0x0001 = %04x\n", value );

    //Set
    value = 0x0000 | 0x0001;
    printf( "0x0000 | 0x0001 = %04x\n", value );

    //Test bit
    value = 0x0F00 & 0x0101;
    printf( "0x0F00 & 0x0101 = %04x\n", value );
}

void BitManipulationAlg::TestBasicBitManipulation(void)
{
    BasicBitManipulation();
}

void BitManipulationAlg::TestCountBits(void)
{
    cout << "********* testing count bits ********";
    vector<pair<uint32_t,int>> tests;
    tests.push_back( make_pair(0,0) );
    tests.push_back( make_pair(0x0001,1) );
    tests.push_back( make_pair(0x0010,1) );
    tests.push_back( make_pair(0x0010,1) );
    tests.push_back( make_pair(0x0100,1) );
    tests.push_back( make_pair(0x1000,1) );
    tests.push_back( make_pair(0xAAAA,8) );

    for( auto itr = tests.begin(); itr != tests.end(); itr++)
    {
        int result = CountBits( itr->first );
        printf("in=0x%04x, exp=%d, act=%d\n", itr->first, itr->second, result );
    }
}

int BitManipulationAlg::CountBits(uint32_t value)
{
    int count = 0;

    while( value )
    {
        count += ( value & 0x0001U );
        value >>= 1;
    }
    return count;
}

#endif