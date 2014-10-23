#include "array_stack.h"

using namespace std;

bool balanced_brackets(const string&s){
	
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
				cout << test << " has balanced brackets" << endl;
			else
				cout << test << " has unbalanced brackets" << endl;
		}
	}
}

