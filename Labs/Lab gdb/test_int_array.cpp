#include "terrible_dynamic_size_array_unsorted.h"

using namespace std;


int main()
{
	int_array arr;
	int num;
	
	init(arr);
	
	for (unsigned int i = 0; i < 10; ++i)
	{
		cout << "Enter a number to add: ";
		cin >> num;
		add(arr, num);
		print(arr);
	}
	
	cout << "The list is now: " << endl;
	for(unsigned int i = 0; i < arr.count; i++){
		cout << arr.data[i] << " ";
	}
	
	for(unsigned int i = 0; i < 10; i++){
		int targ;
		cout << "\nSearch for a number: ";
		cin >> targ;
		if(contains(arr,targ)){
			cout << targ << " was found!" << endl;
		}
		else{
			cout << targ << " was NOT found." << endl;
		}
	}
	
	cout << "The list is now: " << endl;
	for(unsigned int i = 0; i < arr.count; i++){
		cout << arr.data[i] << " ";
	}
	
	for (unsigned int i = 0; i < 10; ++i)
	{
		cout << "\nEnter a number to remove: ";
		cin >> num;
		remove(arr, num);
		print(arr);
	}
	
	destr(arr);
}
