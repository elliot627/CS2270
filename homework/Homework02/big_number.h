#include "doubly_linked_list.h"

using namespace std;

class big_number 
{
	public:
	
		// constructors (work like init() methods)
		big_number();
		big_number(int i);
		big_number(const big_number& m);
		big_number(const string& s, unsigned int base);
		
		// assignment operator
		// big_number a = 98; big_number b = 0; ... b = a;
		big_number& operator=(const big_number& m);
		
		// destructor (works like destr() method)
		~big_number();
	
		// self-assigning arithmetic operators
		big_number& operator+=(const big_number& addend);
		big_number& operator-=(const big_number& subtractand);
		big_number& operator*=(const big_number& multiplicand);
		big_number& operator/=(const big_number& divisor);
	
		// positive modulus
		big_number& operator%=(const big_number& divisor);
		
		// overload prefix increment
		big_number& operator++();  
		// overload prefix decrement
		big_number& operator--();  
		
		// input and output operators
		friend std::ostream& operator<<(std::ostream& os, const big_number& bignum);
		friend std::istream& operator>>(std::istream& is, big_number& bignum);
		
		// arithmetic operators
		friend big_number operator+(const big_number& a, const big_number& b);
		friend big_number operator-(const big_number& a, const big_number& b);
		friend big_number operator*(const big_number& a, const big_number& b);
		friend big_number operator/(const big_number& a, const big_number& b);
		friend big_number operator%(const big_number& a, const big_number& b);
		// hard to do without fast multiplication
		friend big_number factorial(const big_number& a);

		// comparison operators
		friend bool operator>(const big_number& a, const big_number& b);
		friend bool operator>=(const big_number& a, const big_number& b);
		friend bool operator<(const big_number& a, const big_number& b);
		friend bool operator<=(const big_number& a, const big_number& b);	
		friend bool operator==(const big_number& a, const big_number& b);
		friend bool operator!=(const big_number& a, const big_number& b);

	private:
	
		node* head_ptr;
		node* tail_ptr;
		unsigned int digits;
		bool positive;
		unsigned int base;
		
		// helper functions can go here
		
};
