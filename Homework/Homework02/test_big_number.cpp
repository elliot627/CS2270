#include "big_number.h"

using namespace std;

int main(){

  cout << "\t\t Testing int constructor..." << endl;
  big_number intTest(123456789);
  print_list(intTest.getHead());
  cout << "head_ptr points to: " << intTest.getHeadData() << endl;
  cout << "tail_ptr points to: " << intTest.getTailData() << endl;
  cout << "This has " << intTest.getDigits() << " digits" << endl;
  cout << "Positive: " << intTest.getPositive() << "\n" << endl;


  big_number intTest2(987654321);
  print_list(intTest2.getHead());
  cout << "head_ptr points to: " << intTest2.getHeadData() << endl;
  cout << "tail_ptr points to: " << intTest2.getTailData() << endl;
  cout << "This has " << intTest2.getDigits() << " digits" << endl;
  cout << "Positive: " << intTest2.getPositive() << "\n" << endl;

  cout << "\t\t Testing int constructor with single digit..." << endl;
  big_number intTest3(3);
  print_list(intTest3.getHead());
  cout << "head_ptr points to: " << intTest3.getHeadData() << endl;
  cout << "tail_ptr points to: " << intTest3.getTailData() << endl;
  cout << "This has " << intTest3.getDigits() << " digits" << endl;
  cout << "Positive: " << intTest3.getPositive() << "\n" << endl;


  cout << "\t\t Testing int constructor with single negative digit..." << endl;
  big_number intTest4(-3);
  print_list(intTest4.getHead());
  cout << "head_ptr points to: " << intTest4.getHeadData() << endl;
  cout << "tail_ptr points to: " << intTest4.getTailData() << endl;
  cout << "This has " << intTest4.getDigits() << " digits" << endl;
  cout << "Positive: " << intTest4.getPositive() << "\n" << endl;


  cout << "\t\t Testing int constructor with negative int..." << endl;
  big_number intTest5(-305);
  print_list(intTest5.getHead());
  cout << "head_ptr points to: " << intTest5.getHeadData() << endl;
  cout << "tail_ptr points to: " << intTest5.getTailData() << endl;
  cout << "This has " << intTest5.getDigits() << " digits" << endl;
  cout << "Positive: " << intTest5.getPositive() << "\n" << endl;


  cout << "\t\t Testing default constructor..." << endl;
  big_number defaultTest;
  print_list(defaultTest.getHead());
  cout << "head_ptr points to: " << defaultTest.getHeadData() << endl;
  cout << "tail_ptr points to: " << defaultTest.getTailData() << endl;
  cout << "This has " << defaultTest.getDigits() << " digits" << endl;
  cout << "Positive: " << defaultTest.getPositive() << "\n" << endl;

  cout << "\t\t Testing copy constructor..." << endl;
  big_number copyTest(intTest);
  print_list(copyTest.getHead());
  cout << "head_ptr points to: " << copyTest.getHeadData() << endl;
  cout << "tail_ptr points to: " << copyTest.getTailData() << endl;
  cout << "This has " << copyTest.getDigits() << " digits" << endl;
  cout << "Positive: " << copyTest.getPositive() << "\n" << endl;


  cout << "\t\t Testing string constructor..." << endl;
  big_number strTest("123456789", 10);
  print_list(strTest.getHead());
  cout << "head_ptr points to: " << strTest.getHeadData() << endl;
  cout << "tail_ptr points to: " << strTest.getTailData() << endl;
  cout << "This has " << strTest.getDigits() << " digits" << endl;
  cout << "Positive: " << strTest.getPositive() << "\n" <<  endl;


  cout << "\t\t Testing string constructor with single digit..." << endl;
  big_number strTest3("8", 10);
  print_list(strTest3.getHead());
  cout << "head_ptr points to: " << strTest3.getHeadData() << endl;
  cout << "tail_ptr points to: " << strTest3.getTailData() << endl;
  cout << "This has " << strTest3.getDigits() << " digits" << endl;
  cout << "Positive: " << strTest3.getPositive() << "\n" <<  endl;


  cout << "\t\t Testing string constructor with negative number..." << endl;
  big_number strTest2("-98765432101234567893", 10);
  print_list(strTest2.getHead());
  cout << "head_ptr points to: " << strTest2.getHeadData() << endl;
  cout << "tail_ptr points to: " << strTest2.getTailData() << endl;
  cout << "This has " << strTest2.getDigits() << " digits" << endl;
  cout << "Positive: " << strTest2.getPositive() << "\n" << endl;


  cout << "\t\t Testing string constructor with single negative digit.." << endl;
  big_number strTest4("-8", 10);
  print_list(strTest4.getHead());
  cout << "head_ptr points to: " << strTest4.getHeadData() << endl;
  cout << "tail_ptr points to: " << strTest4.getTailData() << endl;
  cout << "This has " << strTest4.getDigits() << " digits" << endl;
  cout << "Positive: " << strTest4.getPositive() << "\n" << endl;


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
