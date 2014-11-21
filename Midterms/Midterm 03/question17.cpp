//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 11-4.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void quicksort(string* arr, unsigned int size);

void partition(string* arr, unsigned int size, unsigned int& pivot_index)
{
   
	cout << "partitioning " << endl;
	for (unsigned int i = 0; i < size; ++i)
		cout << *(arr + i) << " ";
	cout << endl;
   
	string pivot = arr[0];
  unsigned int lt = 0;
  unsigned int gt = size - 1;
  unsigned int i = 0;
  
  cout << "\t\t\tHello #1" << endl;
  
  while(i < gt){
    if(arr[i] < pivot){                       //if the value at arr[i] is less than the pivot
      string temp;                            //swap this value with the value at arr[lt]
      temp = arr[i];
      arr[i] = arr[lt];
      arr[lt] = temp;
      ++lt;                                   //advance lt counter
      ++i;                                    //advance i counter
    }
    else if(arr[i] > pivot){                  //otherwise, if the value at arr[i] is greater than the pivot
      string temp;                            //swap this value with the value at arr[gt]
      temp = arr[i];
      arr[i] = arr[gt];
      arr[gt] = temp;
      --gt;
    }
    else if(arr[i] == pivot){                 //if the value at arr[i] is equal to the pivot
      i++;                                    //move along, nothing to swap here
    }
  }
  
  
	
	cout << "post partitioning pivot " << pivot_index << endl;
	for (unsigned int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
   string* a = new string[12];
   a[0] = "Q";
   a[1] = "X";
   a[2] = "R";
   a[3] = "K";
   a[4] = "Q";
   a[5] = "X";
   a[6] = "R";
   a[7] = "K";
   a[8] = "Q";
   a[9] = "X";
   a[10] = "R";
   a[11] = "K";
		
   quicksort(a, 12);
   cout << "\n\nArray after quicksort:" << endl;
   for (int i = 0; i < 12; i++)
      cout << a[i] << " ";
   cout << endl;
   
   
}  // end main

