#include <iostream>

using namespace std;

bool binary_contains1(const int* arr, unsigned int first, unsigned int last, int target){

	// base cases come first...
	if(first == last){
		return (arr[first] == target);					//once array has been chopped down to one remaining element, check it that is the element!
	}

	//base case, not found
	if(first > last){
		return false;
	}
	unsigned int mid = first + (first - last) / 2;						//calculate (first - last) first to retrieve difference while avoiding integer overflow.

	//base case, found
	if(arr[mid] == target){
		return true;
	}
	if(arr[mid] > target){
		return binary_contains1(arr, first, mid - 1, target);
	}
	return binary_contains1(arr, mid + 1, last, target);



}

bool binary_contains2(const int* arr, unsigned int size, int target){
	//base case - checked entire list, or list is empty
	if(size == 0)	return false;

	int middle_element = *(arr + (size / 2));								//finds middle element by adding half of size to arr address, then *(dereferencing).
 	if(middle_element == target) return true;
	if(middle_element > target){
		binary_contains2(){
			
		}
	}
}

int main(){
	int target;
	int array[10] = {1, 6, 17, 22, 24, 26, 27, 35, 51, 98};
	for (unsigned int k = 0; k < 10; ++k)
		cout << array[k] << " ";
	cout << endl;
	cout << "Enter a number to search for: ";
	cin >> target;
	if (binary_contains1(array, 0, 9, target))
		cout << "target " << target << " found" << endl;
	else
		cout << "target " << target << " not found" << endl;
//	if (binary_contains2(array, 10, target))
//		cout << "target " << target << " found" << endl;
//	else
//		cout << "target " << target << " not found" << endl;

}
