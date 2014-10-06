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

}

bool pop(array_stack& stk){

}

int top(const array_stack& stk){

}

bool empty(const array_stack& stk){

}
