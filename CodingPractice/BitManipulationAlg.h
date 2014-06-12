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
private:
};

void BitManipulationAlg::TestAll( void )
{
	TestCombineBitRange();
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

#endif