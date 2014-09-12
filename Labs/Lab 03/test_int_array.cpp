#include "dynamic_size_array_unsorted.h"

using namespace std;


int main()
{
	int_array arr;
	int num;
	
	init(arr);
	
	//~ add(arr,99);
	//~ add(arr,1);
	//~ add(arr,2);
	//~ add(arr,3);
	//~ add(arr,4);
	//~ add(arr,5);
	//~ add(arr,6);
	//~ add(arr,7);
	//~ add(arr,8);
	//~ add(arr,9);
	//~ add(arr,10);
	//~ add(arr,11);
	//~ add(arr,12);
	//~ add(arr,13);
	//~ add(arr,14);
	//~ add(arr,15);
	//~ add(arr,16);
	//~ add(arr,17);
	//~ add(arr,18);
	//~ add(arr,19);
	//~ add(arr,20);
	//~ //add(arr,21);
	//~ 
		//~ 
	//~ print(arr);
	//~ 
	//~ cout << contains(arr, 2) << endl;
	//~ cout << contains(arr, 23) << endl;
	//~ cout << contains(arr, 0) << endl;
	//~ cout << contains(arr, 12) << endl;
	//~ cout << contains(arr, 20) << endl;
	//~ cout << contains(arr, 0) << "\n" <<endl;
	//~ 
	//~ 
	//~ remove(arr, 1);
	//~ print(arr);
	//~ 
	//~ remove(arr, 3);
	//~ print(arr);
	//~ 
	//~ remove(arr, 3);
	//~ print(arr);
	//~ 
	//~ remove(arr, 4);
	//~ print(arr);
	//~ 
	//~ remove(arr, 6);
	//~ print(arr);

	
	
	for (unsigned int i = 0; i < 25; ++i)
	{
		cout << "Enter a number to add: ";
		cin >> num;
		add(arr, num);
		print(arr);
	}
	
	for (unsigned int i = 0; i < 25; ++i)
	{
		cout << "Enter a number to remove: ";
		cin >> num;
		remove(arr, num);
		print(arr);
	}
	
	clear(arr);
	add(arr, 7);
	print(arr);
	
	destr(arr);
}
