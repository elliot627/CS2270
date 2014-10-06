#include "array_stack.h"

using namespace std;


void init(array_stack& stk){
	init(stk.arr);
}

void destr(array_stack& stk){
	destr(stk.arr);
}

void print(const array_stack& stk){
	cout << "stack" << endl;
	for (unsigned int i = 0; i < stk.arr.count; ++i)
		cout << "\t" << stk.arr.data[stk.arr.count - i - 1] << endl;
}

void push(array_stack& stk, const int& payload){
	add(stk.arr, payload);
}

bool pop(array_stack& stk){
	if(stk.arr.count == 0){
		return false;
	}
	stk.arr.count--;
	return true;
}

int top(const array_stack& stk){
	if(stk.arr.count != 0){
		return stk.arr[stk.arr.count - 1];
	}
}

bool empty(const array_stack& stk){
	return stk.arr.count == 0;
}
