  #include "big_number.h"

  /* Private big_num variables

   *  node* head_ptr
   *  node* tail_ptr
   *  unsigned int digits
   *  bool positive
   *  unsigned int base
  */


  /*
   *int constuctor code from class on Monday:
   *
   *  while(i < 0){
   *    if(head_ptr != nullptr){
   *      head_ptr->prev = new node();
   *      head_ptr->prev->data = (i % 10) + '0';
   *      head_ptr->prev->next = head_ptr;
   *      head_ptr = head_ptr->prev;
   *    }
   *    else{
   *      head_ptr = new node();
   *      head_ptr->data = (i % 10) + '0';
   *      tail_ptr = head_ptr;
   *      .....?
   *    }
   *  }
   *
   *
  */

  using namespace std;

  //////////////Accessor methods//////////////
  //Getter method for use with doubly_linked_list's print_list method
  node* big_number::getHead(){
    return (*this).head_ptr;
  }

  node* big_number::getTail(){
	  return (*this).tail_ptr;
  }

  char big_number::getHeadData(){
    return (*this).head_ptr->data;
  }

  char big_number::getTailData(){
    return (*this).tail_ptr->data;
  }

  bool big_number::getPositive(){
    return (*this).positive;
  }

  int big_number::getDigits(){
    return (*this).digits;
  }

  //trims preceeding zeros from (*this)
  void big_number::killWorthlessZeros(){
    while((*this).head_ptr != (*this).tail_ptr && (*this).head_ptr->data == '0'){
      (*this).head_ptr = (*this).head_ptr->next;
      delete (*this).head_ptr->prev;
      (*this).head_ptr->prev = nullptr;
      (*this).digits--;
    }
  }

  //prepends an item to the head_ptr of this
  //HUMANS - DO NOT USE THIS METHOD - only to be used as a helper for constructors
  void big_number::prepend(const char in){
    node* incoming = new node();
    incoming->data = in;
    incoming->prev = nullptr;
    incoming->next = (*this).head_ptr;
    (*this).head_ptr->prev = incoming;
    (*this).head_ptr = incoming;
    (*this).digits++;
  }
  
  //helper function for adding - assumes that |*this| >= |m|
  big_number&  big_number::sum(const big_number& m){
    node* cursor = tail_ptr;
    const node* mcursor = m.tail_ptr;
    digits = 0; // a little scary, but let's roll with it anyway
    unsigned int dig1, dig2, result;
    unsigned int carry = 0;

    while(cursor != nullptr && mcursor != nullptr){
      dig1 = alpha.find(cursor->data);
      dig2 = alpha.find(mcursor->data);
      result = carry + dig1 + dig2;
      if(result >= base){
        if(base <= 10){
          cursor->data = ((carry + dig1 + dig2) % base) + '0';
        }
        else{
          cursor->data = result + 'a' - 10;
        }
        carry = 1;
      }
      else{
        if(base <= 10){
          cursor->data = result + '0';
        }
        else{
          cursor->data = result + 'a' - 10;
        }
        carry = 0;
      }
      cursor = cursor->prev;
      mcursor = mcursor->prev;
      ++digits;
    }

    while(cursor != nullptr){
      dig1 = alpha.find(cursor->data);
      result = carry + dig1 + dig2;
      if(result >= base){
        if(base <= 10){
          cursor->data = ((carry + dig1 + dig2) % base) + '0';
        }
        else{
          cursor->data = result + 'a' - 10;
        }
        carry = 1;
      }
      else{
        if(base <= 10){
          cursor->data = result + '0';
        }
        else{
          cursor->data = result + 'a' - 10;
        }
        carry = 0;
      }
      cursor = cursor->prev;
      ++digits;
    }

    if(carry > 0){
    head_ptr->prev = new node;
    head_ptr->prev = nullptr;
    head_ptr->prev->next = head_ptr;
    head_ptr->prev->data = '1';
    head_ptr = head_ptr->prev;
    ++digits;
    }

    return *this;
  }
  
  
  
  
  

  // default constructor, creates a 0
  big_number::big_number(){
    (*this).head_ptr = (*this).tail_ptr = new node();
    (*this).head_ptr->data = '0';
    (*this).head_ptr->next = (*this).head_ptr->prev = nullptr;
    (*this).digits = 1;
    (*this).positive = true;
    (*this).base = 10;
  }

  // int constructor; create big_number from base 10 integer
  big_number::big_number(int i){

    //assign instance variables
    (*this).digits = 0;
    (*this).base = 10;
    (*this).head_ptr = (*this).tail_ptr = new node();
    (*this).head_ptr->next = (*this).head_ptr->prev = nullptr;

    //assign this.positive
    if(i < 0){
      positive = false;
      i *= -1;
    }
    else{
      positive = true;
    }

    //assign the first digit
	(*this).tail_ptr->data = ((i % 10) + '0');
	i /= 10;
	(*this).digits = 1;


	//disect i's digits, from right to left and prepend to big_num
	while((unsigned int)i >= (*this).base){
	(*this).prepend((i % 10) + '0');                     //adding '0' to the int results in the char version of the same number
	i /= 10;
	}
	//add final digit if it is not == 0
	if(i != 0){
	(*this).prepend(i + '0');
	}

	(*this).killWorthlessZeros();
  }

  // copy constructor, creates a deep copy of m
  big_number::big_number(const big_number& m){
    (*this).head_ptr = (*this).tail_ptr = new node();
    (*this).positive = m.positive;
    (*this).base = m.base;
    (*this).digits = m.digits;
    copy_list(m.head_ptr, (*this).head_ptr, (*this).tail_ptr);
  }

  //constructor to create number from a string
  big_number::big_number(const string& s, unsigned int b){
    (*this).digits = 0;
    (*this).base = b;
    (*this).positive = true;
    unsigned int index = 0;

    if(s[0] == '-'){
      positive = false;
      index++;
    }
    if(s[0] == '+'){
      index++;
    }

    //assign the first digit, then proceed more intelligently
    (*this).head_ptr = (*this).tail_ptr = new node();
    (*this).head_ptr->next = (*this).head_ptr->prev = nullptr;
    (*this).head_ptr->data = s[index++];
    (*this).digits++;

    while(index < s.length()){
      (*this).tail_ptr->next = new node();
      (*this).tail_ptr->next->data = s[index++];
      (*this).tail_ptr->next->next = nullptr;
      (*this).tail_ptr->next->prev = tail_ptr;
      (*this).tail_ptr = tail_ptr->next;
      (*this).digits++;
    }

    (*this).killWorthlessZeros();
  }

  // destructor
  big_number::~big_number(){
	clear_list((*this).head_ptr, (*this).tail_ptr);
  }

  // assignment operator
  big_number& big_number::operator=(const big_number& m){
    if(this == &m){return (*this);}										//avoid clearing self in accidental self-assignment
    clear_list((*this).head_ptr,(*this).tail_ptr);
    copy_list(m.head_ptr, (*this).head_ptr, (*this).tail_ptr);
    (*this).digits = m.digits;
    (*this).base = m.base;
    (*this).positive = m.positive;
    return (*this);
  }

  // set value to original value + b; return answer in original number's base
  big_number& big_number::operator+= (const big_number& b){
    return *this;
  }

  // set value to original value * b; return answer in original number's base
  big_number& big_number::operator*= (const big_number& b){
    return *this;
  }

  // set value to original value - b; return answer in original number's base
  big_number& big_number::operator-= (const big_number& b){
    return *this;
  }

  // set value to original value / b; return answer in original number's base
  big_number& big_number::operator/= (const big_number& b){
    return *this;
  }

  // set value to original value * b; return answer in original number's base
  big_number& big_number::operator%= (const big_number& b){
    return *this;
  }

  // prefix increment
  big_number& big_number::operator++(){
    return *this;
  }

  // prefix decrement
  big_number& big_number::operator--(){
    return *this;
  }

  bool operator >(const big_number& a, const big_number& b){
    if(a.base == b.base){
      if(a.positive && !b.positive){
        return true;
      }
      if(!a.positive && b.positive){
        return false;
      }
      if(a.digits > b.digits){
        return true;												//if a is the same base and has more digits, it must be bigger.
      }
      if(a.digits < b.digits){
        return false;												//if a is the same base and has fewer digits, it must be smaller
      }
      else{															//if they have the same number of digits, start comparing them, starting from the left (most important)
        node* acursor = a.head_ptr;
        node* bcursor = b.head_ptr;
        while(acursor != nullptr){
          if(acursor->data > bcursor->data){
            return true;
          }
          if(acursor->data < bcursor->data){
            return false;
          }
          acursor = acursor->next;
          bcursor = bcursor->next;
        }
        return false;												//if the above loop finishes without returning, the two numbers are therefore equal.
      }
    }
    else{
      cout << "\nSorry this comparison only works on numbers of the same base right now.\n" << endl;
      return false;
    }
  }

  bool operator >=(const big_number& a, const big_number& b){
    return((a > b) || (a == b));
  }

  bool operator <(const big_number& a, const big_number& b){
    return(!(a >= b));
  }

  bool operator <=(const big_number& a, const big_number& b){
    return((a < b) || (a == b));
  }

  bool operator==(const big_number& a, const big_number& b){			//method currently only considers EXACT matches to be equal
	bool exactDigits = true;
	if(a.digits == b.digits){
		node* cursor_a = a.head_ptr;
		node* cursor_b = b.head_ptr;
		while(cursor_a != nullptr){										//loop through both big_nums, comparing each digit for any discrepencies
			if(cursor_a->data != cursor_b->data){
				exactDigits = false;
			}
			cursor_a = cursor_a->next;
			cursor_b = cursor_b->next;
		}
	}
	return ((a.digits == b.digits) && (a.base == b.base) && (a.positive == b.positive) && exactDigits);
  }

  bool operator!=(const big_number& a, const big_number& b){
    return !(a == b);
  }

  ostream& operator <<(ostream& out, const big_number& n){
    out << "\nbig_number: ";
	if(!n.positive){
		out << '-';
	}
    node* cursor = n.head_ptr;
    while(cursor != nullptr){
      out << cursor->data;
      cursor = cursor->next;
    }
    out << "\nbase: " << n.base << "\ndigits: " << n.digits << "\nhead_ptr: " << n.head_ptr->data << "\ntail_ptr: " << n.tail_ptr->data << "\npositive: ";
    if(n.positive){
      out << "yes\n" << endl;
    }
    else{
      out << "no\n" << endl;
    }
    return out;
  }

  istream& operator >>(istream& in, big_number& n){
	string incoming;
	in >> incoming;
	big_number temp(incoming, 10);
	n = temp;
	return in;
  }

  big_number operator+(const big_number& a, const big_number& b){
    big_number answer;
    return answer;
  }

  big_number operator-(const big_number& a, const big_number& b){
    big_number answer;
    return answer;
  }

  big_number operator*(const big_number& a, const big_number& b){
    big_number answer;
    return answer;
  }

  big_number operator/(const big_number& a, const big_number& b){
    big_number answer;
    return answer;
  }

  big_number operator%(const big_number& a, const big_number& b){
    big_number answer;
    return answer;
  }

  big_number factorial(const big_number& a){
    big_number answer;
    return answer;
  }


