#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;


struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
public:
	LRUCache();
	LRUCache(int capacity);
	void set(int key, int value);
	int get(int key);

	void Test();
private:
	int mCount;
};

LRUCache::LRUCache(int capacity)
{
	cp = capacity;
	mCount = 0;
}

LRUCache::LRUCache()
{

}

void LRUCache::set(int key, int value)
{
	int ret;
	//Three cases
	//1 found
	//  - Insert and update list
	//2 not found
	// - Less than capcity, insert head
	// - at capcity, insert to head, pop tail

	if (mp.find(key) == mp.end())
	{
		//not found

		Node * newNode = new Node(key, value);

		if (mCount == cp)
		{
			//full
			Node * rmNode = tail;
			tail = rmNode->prev;
			mp.erase(rmNode->key);
			delete rmNode;
		}

		//pop
		if (mCount == 0)
		{
			head = newNode;
			tail = head;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}

		mp[key] = newNode;

		if (mCount < cp)
		{
			mCount++;
		}

	}
	else
	{
		//found
		if (cp == 1 || mp[key] == head )
		{
			//do nothing
		}
		else
		{
			if (mp[key] == tail)
			{
				tail = mp[key]->prev;
				tail->next = NULL;
			}
			else
			{
				mp[key]->prev->next = mp[key]->next;
				mp[key]->next->prev = mp[key]->prev;
			}

			mp[key]->prev = NULL;
			mp[key]->next = head;
			head->prev = mp[key];
			head = mp[key];
		}
	}

	mp[key]->value = value;
}

int LRUCache::get(int key)
{
	int retVal = -1;

	if (mp.find(key) != mp.end())
	{
		retVal = mp[key]->value;
	}

	return retVal;
}

void LRUCache::Test()
{
	LRUCache cache(3);

	cache.set(1, 11);
	cache.set(2, 12);
	cache.set(3, 13);
	int ret;

	//test new
	cache.set(4, 14);
	ret = cache.get(1);
	cout << "-1 == " << ret << endl;
	
	//test middle
	cache.set(3, 13);
	ret = cache.get(3);
	cout << "13 == " << ret << endl;

	//test end
	cache.set(2, 12);
	ret = cache.get(2);
	cout << "2 == 12" << ret << endl;
}
