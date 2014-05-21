#pragma once
#include <map>
#include <deque>
/*
return address of that amount of memory
store what memory is used
data[0-1000]

Information needed:
Used Memory
- start address
- size

Free Memory
- start address
- size

GetMalloc
- Find next available memory
- Split memory if extra space, set used into used memory, resize free space

SetFree
- Find memory info on freed address
- Set Unused, and put back into free space

*/

using namespace std;

typedef struct memoryData
{
	struct memoryData( int addr, int sz )
	{
		address = addr;
		size = sz;
	}

	int address;
	int size;
} sMemoryData;

class Malloc
{
public:
	Malloc();
	~Malloc();

	void SetSystemMemory( int memorySize )
	{
		_memorySize = memorySize;
		_allocatedDataMap.clear();
		
		sMemoryData md = sMemoryData(0, 1000);

		_allocatedDataMap[md.size] = md;
	}

	/*
	Assumption, only continues data wanted
	*/
	int MyMalloc( int requestedSize )
	{
		if( _allocatedDataMap.count(requestedSize) > 0)
		{
			memoryData md = _allocatedDataMap[requestedSize].front();
			_allocatedDataMap[requestedSize].pop_front();
			_usedDataMap[md.address] = md;

			return md.address
		}
		else
		{
			//find next largest
			
			for( map<int, deque<sMemoryData>>::iterator itr = _allocatedDataMap.begin();
				 itr != _allocatedDataMap.end();
				 itr++ )
			{
				if( itr->first > requestedSize )
				{
					sMemoryData currentMem = itr->second.front();
					itr->second.pop_front();

					sMemoryData newMem( (currentMem.address + requestedSize), (currentMem.size - requestedSize) );
					
					currentMem.size = requestedSize;

					_allocatedDataMap[newMem.size].push_back(newMem);
					
					_usedDataMap[]
				}
			}
		}
	}

private:


	int _memorySize;
	map<int, deque<sMemoryData>> _allocatedDataMap;
	map<int, sMemoryData> _usedDataMap;
};

Malloc::Malloc()
{
}

Malloc::~Malloc()
{
}

