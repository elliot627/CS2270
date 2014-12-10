#include <cstdlib>
#include <iostream>
#include <string>
#include "hash1.h"
using namespace std;

open_address_hashtable::open_address_hashtable()
{
	entries = new pair<int, string>*[size];
	for (unsigned int i = 0; i < size; ++i)
		entries[i] = nullptr;
	count = 0;
}	

open_address_hashtable::~open_address_hashtable()
{
	for (unsigned int k = 0; k < size; ++k)
		delete entries[k];
	delete [] entries;
}	

bool open_address_hashtable::insert(unsigned int key, string value) 
{
	pair<int, string>* entry = new pair<int, string>(key, value);
	if (count == size) return false;
	unsigned int index = entry->first % size;
	while (entries[index] != nullptr)
	{
		index = (index + 1) / size;
	}
	entries[index] = entry;
	++count;
	return true;
}

bool open_address_hashtable::find(unsigned int key, string value)
{	
	unsigned int index = key % size;
	unsigned int wrap = index;
	while (entries[index] != nullptr && entries[index]->second != value)
	{
		index = (index + 1) % size;
		if (index == wrap) return false;
	}
	if (entries[index] != nullptr && entries[index]->second == value)
		return true;
	return false;
}


bool open_address_hashtable::remove(unsigned int key, string value)
{	
	unsigned int index = key % size;
	unsigned int wrap = index;
	while (entries[index] != nullptr && entries[index]->second != value)
	{
		index = (index + 1) % size;
		if (index == wrap) return false;
	}
	if (entries[index]->second == value)
	{
		entries[index] = nullptr;
		--count;
		return true;
	}
	return false;
}




