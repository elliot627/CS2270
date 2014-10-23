#include "dynamic_size_array_unsorted.h"

using namespace std;


void init(char_array& arr)
{
	arr.count = 0;
	arr.capacity = arr.DEFAULT_CAPACITY;
	arr.data = new char[arr.capacity];
}

void clear(char_array& arr)
{
	destr(arr);
	init(arr);
}

void destr(char_array& arr)
{
	delete [] arr.data;
	arr.count = 0;
}

void print(const char_array& arr)
{
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
	cout << endl;
}

bool contains(const char_array& arr, const char& target)
{
	bool found = false;
	for (unsigned int i = 0; !found && i < arr.count; ++i)
		if (arr.data[i] == target) found = true;
	return found;
}

void resize(char_array& arr)
{
	arr.capacity *= 2;
	char* new_data = new char[arr.capacity];
	for (unsigned int i = 0; i < arr.count; ++i)
	{
		new_data[i] = arr.data[i];
	}
	delete [] arr.data;
	arr.data = new_data;
}

void add(char_array& arr, const char& payload)
{
	if (arr.count == arr.capacity)
		resize(arr);
	
	arr.data[arr.count++] = payload;
}

bool remove(char_array& arr, const char& target)
{
	unsigned int i = 0; 
	while (i < arr.count && arr.data[i] != target)  i++;
	
	if (i == arr.count) return false;
	if (i < arr.count - 1)
	{
		arr.data[i] = arr.data[arr.count - 1];
	}
	
	arr.count--;
	return true;
}

