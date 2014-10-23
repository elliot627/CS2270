#include "array_stack.h"
#include <string>																			//include string for use of member functions, if needed

using namespace std;

bool balanced_brackets(const string&s){
	array_stack arr_stack;																	//declare,
	init(arr_stack);																		//and initialize stack for brackets
	
	for(unsigned int i = 0; i < s.size(); i++){												//loop through given string, and 
		if(s[i] == '{' || s[i] == '(' || s[i] == '['){										//push opening  brackets onto the stack.
			push(arr_stack, s[i]);
		}
		
		if(s[i] == '}'){																	//if a closing bracket is found,
			if(top(arr_stack) == '{'){														//check if it matches the bracket at the top of the stack
				pop(arr_stack);																//if so, pop it's match from the stack
			}
			else{
				return false;																//if they don't match, return false, as this means that the brackets are out of order
			}
		}
		
		if(s[i] == ')'){																	//if a closing bracket is found,
			if(top(arr_stack) == '('){														//check if it matches the bracket at the top of the stack
				pop(arr_stack);																//if so, pop it's match from the stack
			}
			else{
				return false;																//if they don't match, return false, as this means that the brackets are out of order
			}
		}
		
		if(s[i] == ']'){																	//if a closing bracket is found,
			if(top(arr_stack) == '['){														//check if it matches the bracket at the top of the stack
				pop(arr_stack);																//if so, pop it's match from the stack
			}
			else{
				return false;																//if they don't match, return false, as this means that the brackets are out of order
			}
		}
	}
	return (empty(arr_stack));																//return whether all three stacks are empty - If all are empty, the string of brackets is balanced!
}

int main()
{
	string test;
	
	// test "{}", "{()}", "{(})", "{[]{()}}", "}","{[]{({[])}",
	// "{[(]){()}()}", "((()()()))", "{[]{()}()(())}", "{[]{()}}";
	
	
	
	while (true)
	{
		for (unsigned int i = 0; i < 10; ++i)
		{
			cout << "Enter a string to test, or 'q' to quit: " << endl;
			cin >> test;
			if (test[0] == 'q' || test[0] == 'Q')
				exit(0);
			if (balanced_brackets(test))
				cout << test << " is BALANCED!" << endl;
			else
				cout << test << " is NOT balanced" << endl;
		}
	}
}

