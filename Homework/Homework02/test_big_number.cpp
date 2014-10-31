#include "big_number.h"

using namespace std;

int main(){

  cout << "\t\t Testing int constructor...\n" << endl;
  big_number intTest(123456789);
  cout << intTest;


  big_number intTest2(987654321);
  cout << intTest2;


  cout << "\t\t Testing int constructor with single digit...\n" << endl;
  big_number intTest3(3);
  cout << intTest3;


  cout << "\t\t Testing int constructor with single negative digit...\n" << endl;
  big_number intTest4(-3);
  cout << intTest4;


  cout << "\t\t Testing int constructor with negative int...\n" << endl;
  big_number intTest5(-305);
  cout << intTest5;


  cout << "\t\t Testing default constructor...\n" << endl;
  big_number defaultTest;
  cout << defaultTest;


  cout << "\t\t Testing copy constructor...\n" << endl;
  big_number copyTest(intTest);
  cout << copyTest;


  cout << "\t\t Testing string constructor...\n" << endl;
  big_number strTest("123456789", 10);
  cout << strTest;


  cout << "\t\t Testing string constructor with single digit...\n" << endl;
  big_number strTest2("8", 10);
  cout << strTest2;


  cout << "\t\t Testing string constructor with negative number...\n" << endl;
  big_number strTest3("-98765432101234567893", 10);
  cout << strTest3;


  cout << "\t\t Testing string constructor with single negative digit...\n" << endl;
  big_number strTest4("-8", 10);
  cout << strTest4;
  
  
  cout << "\t\t copying first testInt to previous number...\n" << endl;
  strTest4 = intTest;
  cout << strTest4;
  
  cout << "\t\t copying second testInt to first testItn...\n" << endl;
  intTest = intTest2;
  cout << intTest;
  
  
  //Temporarily abandoned due to dereferencing nightmares
  //~ cout << "\t\t Testing clear_list on first big_num...\n" << endl;
  //~ clear_list(&(intTest.getHead()), &(intTest.getTail()));
  //~ clear_list(
  //~ cout << intTest;


	//~ int n1, n2;
	//~ unsigned int base;
	//~ string s;
			//~
	//~ char choice;
	//~ do
	//~ {
		//~ cout << "Type 'd' to test default constructor" << endl;
		//~ cout << "Type 'i' to test int constructor" << endl;
		//~ cout << "Type 's' to test string constructor" << endl;
		//~ cout << "Type 'a' to test assignment" << endl;
		//~ cout << "Type '>' to test input operator" << endl;
		//~ cout << "Type '=' to test comparison operators" << endl;
		//~ cout << "Type 'q' to quit" << endl;
		//~ cin >> choice;
	//~
		//~ if (toupper(choice) == 'D')
		//~ {
			//~ big_number a;
			//~ cout << "Default constructor gives " << a << endl;
		//~ }
		//~
		//~ if (toupper(choice) == 'I')
		//~ {
			//~ cout << "Enter an integer: ";
			//~ cin >> n1;
			//~ big_number b(n1);
			//~ cout << "Int constructor with " << n1 << " gives " << b << endl;
		//~ }
		//~
		//~ if (toupper(choice) == 'S')
		//~ {
			//~ cout << "Enter a base: ";
			//~ cin >> base;
			//~ cout << "Enter a string: ";
			//~ cin >> s;
			//~ big_number e(s, base);
			//~ cout << "String constructor with " << s << " in base " <<
				//~ base << " gives " << e << endl;
		//~ }
		//~
		//~ if (toupper(choice) == 'A')
		//~ {
			//~ big_number e(9);
			//~ big_number d;
			//~ d = e;
			//~ cout << "Assignment of " << e << " to ";
			//~ ++e;
			//~ cout << d << " gives " << e << endl;
			//~ if (d == e) cout << "boo, shallow copy";
		//~ }
		//~
		//~ if (choice == '>')
		//~ {
			//~ big_number n1;
			//~ cout << "Enter a big number: ";
			//~ cin >> n1;
			//~ cout << "You entered " << n1 << endl;
		//~ }
		//~
		//~ if (choice == '=')
		//~ {
			//~ cout << "Enter a number: ";
			//~ cin >> n1;
			//~ cout << "Enter another number: ";
			//~ cin >> n2;
			//~ big_number f(n1);
			//~ big_number g(n2);
			//~ if (f == g)
				//~ cout << f << " == " << g << endl;
			//~ if (f != g)
				//~ cout << f << " != " << g << endl;
			//~ if (f < g)
				//~ cout << f << " < " << g << endl;
			//~ if (f <= g)
				//~ cout << f << " <= " << g << endl;
			//~ if (f > g)
				//~ cout << f << " > " << g << endl;
			//~ if (f >= g)
				//~ cout << f << " >= " << g << endl;
		//~ }
//~
	//~ } while (toupper(choice) != 'Q');
}
