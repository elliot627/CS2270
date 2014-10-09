#include "terrible_dynamic_size_array_unsorted.h"

using namespace std;


void init(int_array& arr){
	arr.count = 0;
	arr.capacity = arr.DEFAULT_CAPACITY;
	arr.data = new int [arr.capacity];						   //FIX: arr.data was never instantiated!!
	
}

void clear(int_array& arr){
	destr(arr);
	init(arr);
}

void destr(int_array& arr){
	delete [] arr.data;
	arr.count = 0;
}

void print(const int_array& arr){
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
	cout << endl;
}

bool contains(const int_array& arr, const int& target){
	unsigned int i;
	for (i = 0; i < arr.count; ++i);{
		if (arr.data[i] == target){
			return true;
		}
		//else return false;									ERROR:		This line will return false out of the method every time unless your target is the first item in the list
															  //FIX:		Removing this line is an ample fix I also added brackets.
	}
	return false;
}

void resize(int_array& arr){
	arr.capacity *= 2;
	int* new_data = new int[arr.capacity];
	for (unsigned int i = 0; i < arr.count; ++i){
		new_data[i] = arr.data[i];
	}
	//arr.data = new_data;										ERROR: 		Memory leak / defeating the purpose of this whole method - 	
	//delete [] arr.data;													arr.data is just assigned to point and the new resized dataset in the line before this.
	
	delete [] arr.data;										  //FIX:		delete what arr.data points to, clearing up memory,
	arr.data = new_data;									  //			then reassign arr.data to point at the correct dataset																	
}

void add(int_array& arr, const int& payload){
	//if ((arr.count = arr.capacity))							ERROR:		arr.count is being assigned to arr.capacity here, which also resizes the array everytime add() is called.
	
	if(arr.count == arr.capacity){							  //FIX:		Actually compare arr.count and arr.capacity. I also added brackets because I'm OCD like that.
		resize(arr);
	}
	//arr.data[++arr.count] = payload;  						ERROR: 		arr.count is being advanced before the payload is added to the appropriate index
	
	arr.data[arr.count++] = payload;						  //FIX:		Add payload to current count, then increment arr.count
}

bool remove(int_array& arr, const int& target){
	unsigned int i = 0; 
	
	if ((arr.count = 0)) 
		return false;
		
	while (i < arr.count && arr.data[i] != target)  i++;
	
	if (i == arr.count);
		return false;
	arr.data[i] = arr.data[arr.count];
	
	arr.count--;
	return true;
}

