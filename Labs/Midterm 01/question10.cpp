#include "dynamic_size_array_unsorted.h"

using namespace std;

// given an unsorted int_array, set empty to true if the array has no
// integers, and false otherwise; if the array is not empty, find
// the largest number in the array and set max to this number
void find_maximum(const int_array& arr, int& max, bool& empty){
	if(arr.count == 0){															//check if array is empty
		empty = true;															//if so change empty to true
		return;
	}											
	max = arr.data[0];															//assign max to the first value in the list, providing a baseline to compare against.
											
	for(unsigned int i = 0; i < arr.count; i++){								//loop through arr.data[],
		if(arr.data[i] > max){													//if data[i] is greater than the current 'highest',
			max = arr.data[i];													//re-assign max to this value.
			cout << max << endl;
		}
	}
	empty = false;																//assign empty to appropriate value
}

// given an unsorted int_array, set empty to true if the array has no
// integers, and false otherwise; if the array is not empty, find
// the largest and smallest numbers in the array; set min to the smallest one 
// and max to the largest one.
void find_limits(const int_array& arr, int& min, int& max, bool& empty){
	if(arr.count == 0){															//check if array is empty
		empty = true;															//if so, change empty to true
		return;
	}
	min = arr.data[0];															//assign min to the first value in the list, providing a baseline to compare against.
	max = arr.data[0];															//assign max to the first value in the list, providing a baseline to compare against.
	
	for(unsigned int i = 0; i < arr.count; i++){								//loop through entire array,
		if(arr.data[i] > max){													//if the value at the current index is > max,
			max = arr.data[i];													//reassign max
		}
		if(arr.data[i] < min){													//if the value at the current index is < min,
			min = arr.data[i];													//reassign min
		}
	}
	empty = false;																//assign empty to appropriate value
}


int main()
{
	int_array arr;
	
	init(arr);
	
	bool array_is_empty = false;
	int biggest = -1000000;
	int smallest = 1000000;
	
	find_maximum(arr, biggest, array_is_empty);
	
	if (array_is_empty)
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in the above array is a silly question" << endl;
	}
	else
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in the above array is " << biggest << endl;
	}
	
	add(arr, 7);
	find_maximum(arr, biggest, array_is_empty);
	
	if (array_is_empty)
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in empty array is a silly question" << endl;
	}
	else
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in this array is " << biggest << endl;
 	}
 	
 	add(arr, 21);
 	find_maximum(arr, biggest, array_is_empty);
 	
 	if (array_is_empty)
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in empty array is a silly question" << endl;
	}
	else
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in this array is " << biggest << endl;
 	}
 	
 	remove(arr, 21);
 	find_maximum(arr, biggest, array_is_empty);
 	
 	if (array_is_empty)
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in empty array is a silly question" << endl;
	}
	else
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in this array is " << biggest << endl;
 	}
 	
 	
 	
 	
 	
 	cout << "--------------------------------------Now Testing find_limits-----------------" << endl;
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	find_limits(arr, smallest, biggest, array_is_empty);
	if (array_is_empty)
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in empty array is a silly question" << endl;
		cout << "Minimum number in empty array is a silly question" << endl;
	}
	else
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in this array is " << biggest << endl;
		cout << "Minimum number in this array is " << smallest << endl;
 	}
 	
 	clear(arr);
 	
 	for (unsigned int i = 0; i < 25; ++i)
	{
		add(arr, i);
	}
	
	find_limits(arr, smallest, biggest, array_is_empty);
	if (array_is_empty)
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in empty array is a silly question" << endl;
		cout << "Minimum number in empty array is a silly question" << endl;
	}
	else
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in this array is " << biggest << endl;
		cout << "Minimum number in this array is " << smallest << endl;
 	}

	clear(arr);
	
	for (unsigned int i = 0; i < 25; ++i)
	{
		add(arr, -i);
	}
	
	find_limits(arr, smallest, biggest, array_is_empty);
	if (array_is_empty)
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in empty array is a silly question" << endl;
		cout << "Minimum number in empty array is a silly question" << endl;
	}
	else
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in this array is " << biggest << endl;
		cout << "Minimum number in this array is " << smallest << endl;
 	}

	clear(arr);
	
	int num;
	for (unsigned int k = 0; k < 5; ++k)
	{
		cout << "Enter a number " << endl;
		cin >> num;
		add(arr, num);
	}

	find_limits(arr, smallest, biggest, array_is_empty);
	if (array_is_empty)
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in empty array is a silly question" << endl;
		cout << "Minimum number in empty array is a silly question" << endl;
	}
	else
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in this array is " << biggest << endl;
		cout << "Minimum number in this array is " << smallest << endl;
 	}

	clear(arr);
	
	find_limits(arr, smallest, biggest, array_is_empty);
	if (array_is_empty)
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in empty array is a silly question" << endl;
		cout << "Minimum number in empty array is a silly question" << endl;
	}
	else
	{
		cout << "This is your array" << endl;
		print(arr);
		cout << "Maximum number in this array is " << biggest << endl;
		cout << "Minimum number in this array is " << smallest << endl;
 	}

	destr(arr);
}
