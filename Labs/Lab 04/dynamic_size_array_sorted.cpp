#include "dynamic_size_array_sorted.h"

using namespace std;

void init(int_array& arr){
	arr.capacity = arr.DEFAULT_CAPACITY;
	arr.data = new int[arr.capacity];
	arr.count = 0;	
}

void clear(int_array& arr){
	arr.count = 0;
}

void destr(int_array& arr){
	delete [] arr.data;
	arr.count = 0;
}

void print(const int_array& arr){
	for (unsigned int i = 0; i < arr.count; ++i){
		cout << arr.data[i] << " ";
	}
	cout << endl;
}

bool contains(const int_array& arr, const int& target){
	for(unsigned int i = 0; i < arr.count; i++){
		if(arr.data[i] == target){
			return true;
		}
	}
	return false;
}

void resize(int_array& arr){
	arr.capacity *= 2;
	int* doubleArray = new int[arr.capacity];
	for(unsigned int i = 0; i < arr.count; i++){		//copy data to new double-sized array
		doubleArray[i] = arr.data[i];
	}
	delete [] arr.data;									//delete old dataset and point arr.data to new array
	arr.data = doubleArray;
}

void add(int_array& arr, const int& payload){
	if(arr.count == arr.capacity){						//resize array if full
		resize(arr);
	}
	unsigned int j = arr.count;
	while(j > 0 && (payload < arr.data[j - 1])){
		arr.data[j] = arr.data[j - 1];
		j--;
	}
	arr.data[j] = payload;
	arr.count++;
}

bool remove(int_array& arr, const int& target){
	if(!(contains(arr, target))){						//if target is not contained in arr.data[], return false	
		return false;
	}
	if(arr.data[arr.count - 1] == target){				//if target is the last item, simply decrement count
		arr.count--;
		return true;
	}
	for(unsigned int i = 0; i < arr.count; i++){
		if(arr.data[i] == target){						//first, find location of target
			while(i < arr.count){
				arr.data[i] = arr.data[i + 1];			//then overwrite it to the end of the array
				i++;
			}
			arr.count--;
			return true;
		}
	}
	return false;										//just a default case to make the compiler happy
}

