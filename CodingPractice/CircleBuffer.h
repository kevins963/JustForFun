#ifndef CircleBuffer_h__
#define CircleBuffer_h__

typedef struct circle_buffer

struct circle_buffer
{
	char* data;
	int dataSize;

	int readIndex;
	int writeIndex;	
	char isEmpty;
};

void CircleBuffer_Init( circle_buffer * circleBuffer, int size )
{
	circleBuffer->data = (char*)malloc( sizeof( char ) * size );
	circleBuffer->dataSize = size;
	circleBuffer->readIndex = 0;
	circleBuffer->writeIndex = 0;
	circleBuffer->isEmpty = 1;
}

//Dispose data
void CircleBuffer_Destroy( circle_buffer * circleBuffer )
{
	free( circleBuffer->data );
}

//Get Count
CircleBuffer_GetCount( circle_buffer * circleBuffer )
{
	if( circleBuffer->isEmpty )
	{
		return 0
	}

	if( circleBuffer->write)
}

//Write Data

//Read Data



#endif // CircleBuffer_h__
