#include "big_number.h"

using namespace std;

int main(){

  big_number intTest(123456789);

  print_list(intTest.getHead());

  cout << "head_ptr points to: " << intTest.getHeadData() << endl;

  cout << "tail_ptr points to: " << intTest.getTailData() << "\n" << endl;



  big_number intTest2(987654321);

  print_list(intTest2.getHead());

  cout << "head_ptr points to: " << intTest2.getHeadData() << endl;

  cout << "tail_ptr points to: " << intTest2.getTailData() << "\n"  << endl;


  cout << "Testing int construction with: 3";
  big_number intTest3(3);

  print_list(intTest3.getHead());

  cout << "head_ptr points to: " << intTest3.getHeadData() << endl;

  cout << "tail_ptr points to: " << intTest3.getTailData() << "\n" << endl;



  big_number defaultTest;

  defaultTest.prepend('4');

  print_list(defaultTest.getHead());

  defaultTest.prepend('3');
  defaultTest.prepend('2');
  defaultTest.prepend('1');

  print_list(defaultTest.getHead());

  cout << "head_ptr points to: " << defaultTest.getHeadData() << endl;

  cout << "tail_ptr points to: " << defaultTest.getTailData() << "\n"  << endl;


  big_number copyTest(intTest);

  print_list(copyTest.getHead());

  cout << "head_ptr points to: " << intTest.getHeadData() << endl;

  cout << "tail_ptr points to: " << intTest.getTailData() << "\n"  << endl;


  big_number strTest("123456789", 10);

  print_list(strTest.getHead());

  cout << "head_ptr points to: " << strTest.getHeadData() << endl;

  cout << "tail_ptr points to: " << strTest.getTailData() << "\n" << endl;



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
