  #include "big_number.h"

  /* Private big_num variables

   *  node* head_ptr
   *  node* tail_ptr
   *  unsigned int digits
   *  bool positive
   *  unsigned int base
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
  //HUMANS -  DO NOT USE THIS METHOD - only to be used as a helper for constructors
  //          NOT BUILT TO HANDLE EMPTY Big_Numbers!
  void big_number::prepend(const char in){
    node* incoming = new node();
    incoming->data = in;
    incoming->prev = nullptr;
    incoming->next = (*this).head_ptr;
    (*this).head_ptr->prev = incoming;
    (*this).head_ptr = incoming;
    (*this).digits++;
  }
  
  //Determine whether (*this) has more digits than 'other'
  int big_number::hasMoreDigitsThan(const big_number& other){
		if((*this).digits > other.digits){
			return 1;
		}
		if((*this).digits == other.digits){
			return 0;
		}
		else{
			return -1;
		}
	}
  
  //helper function for adding two bignums - assumes that |*this| >= |m|
  // -- Modifies *this, summing 'other' into its data
  big_number& big_number::sum(const big_number& other){
    (*this).digits = 0;                                       //set *this's digits = 0, and increment each time a digit is added
    
    //pointers
    node* cursor = (*this).tail_ptr; 
    const node* otherCursor = other.tail_ptr;
    
    //addition variables
    unsigned int top, bottom, sum;
    unsigned int carry = 0;
    
    while(cursor != nullptr && otherCursor != nullptr){       //As long as both numbers still have digits to be added,
      top = alpha.find(cursor->data);
      bottom = alpha.find(otherCursor->data);
      sum = carry + top + bottom;
      
      if(sum >= (*this).base){                                //carrying needed... sum is greater than one digit can hold
        if((sum % (*this).base) < 10){                        //if remainder > 10, use conversion for ASCII characters '0'-'9'
					cursor->data = (sum % (*this).base) + '0';
        }
        else{                                                 //otherwise, use conversion for ASCII characters 'a'-'z'
          cursor->data = (sum % (*this).base) + 'a' - 10;
        }
        carry = 1;                                            //add carry
      }
      else{                                                   //carrying not needed... write in the sum.
        if(sum < 10){
          cursor->data = sum + '0';                           //for digits '0'-'9'
        }
        else{
          cursor->data = sum + 'a' - 10;                      //for digits 'a'-'z'
        }
        carry = 0;
      }
      (*this).digits++;
			if(cursor->prev == nullptr && carry){
				(*this).head_ptr = new node();
				(*this).head_ptr->data = '1';
				(*this).head_ptr->prev = nullptr;
				(*this).head_ptr->next = cursor;
				cursor->prev = (*this).head_ptr;
				cursor = nullptr;
				(*this).digits++;
				break;
			}
			
			cursor = cursor->prev;
			otherCursor = otherCursor->prev;
    }
    
    
    //reaching the loop below implies that all of the digits of the 'bottom' number have been added
    //**carry may still remain
        
    while(cursor != nullptr){
      top = alpha.find(cursor->data);
      sum = carry + top;
      if(sum >= (*this).base){                                //if carry exists, check the sum exceeds the maximum digit value for this base
        if((sum % (*this).base) < 10){
          cursor->data = (sum % (*this).base) + '0';
        }
        else{
          cursor->data = (sum % (*this).base) + 'a' - 10;
        }
      }
      else{
        if(sum < 10){
          cursor->data = sum + '0';
        }
        else{
          cursor->data = sum + 'a' - 10;
        }
        carry = 0;																						//carry has been satisfied
      }
      (*this).digits++;
      if(cursor->prev == nullptr && carry){														//if the head of the list has been reached, and a carry still remains,
				(*this).head_ptr = new node();
				(*this).head_ptr->data = '1';
				(*this).head_ptr->prev = nullptr;
				(*this).head_ptr->next = cursor;
				(*this).digits++;
				cursor = nullptr;
			}
			else{
				cursor = cursor->prev;
			}
    }
    return (*this);
  }
  
  //helper function for subtracting two big_nums - assumes that |*this| > |other|
  //-- Modifies *this, subtracting 'other' from it's sum.
  big_number& big_number::diff(const big_number& other){    
    int top, bottom, result;
    int borrow = 0;

    node* cursor = (*this).tail_ptr;
    node* otherCursor = other.tail_ptr;
    (*this).digits = 0;
    
    while(cursor != nullptr){
      top = alpha.find(cursor->data);
      if(otherCursor != nullptr){
        bottom = alpha.find(otherCursor->data);
        if(borrow){																						//a borrow has occured on this digit.
          if((top - borrow) >= bottom){													//top digit - borrow is sufficient to handle subtraction
						borrow = 0;																					//borrow has been handled
						result = (top - 1) - bottom;
						if(result < 10){																		//write appropriate digit
							cursor->data = result + '0';
						}
						else{
							cursor->data = result + 'a' - 10;
						}
						(*this).digits++;
					}
					else{																									//top digit is insufficient to handle subtraction
						result = ((*this).base + (top - borrow)) - bottom;								//complete subtraction borrowin from previous
						if(result < 10){																			//write appropriate digit
							cursor->data = result + '0';
						}
						else{
							cursor->data = result + 'a' - 10;
						}
						(*this).digits++;
					}
        }
        else{																									//the current top digit has not been borrowed from
					if(top >= bottom){																		//top digit is large enought to handle subtraction
						result = (top - bottom);
						if(result < 10){																		//write appropriate digit
							cursor->data = result + '0';
						}
						else{
							cursor->data = result + 'a' - 10;
						}
						(*this).digits++;
					}
					else{																								//the current top digit is insufficient to handle subtraction
						borrow = 1;																					//borrow from previous digit
						result = ((*this).base + top) - bottom;
						if(result < 10){																		//write appropriate digit
							cursor->data = result + '0';
						}
						else{
							cursor->data = result + 'a' - 10;
						}
						(*this).digits++;
					}
				}
      }
      //reaching this else implies there are no more bottom digits
      else{
				if(borrow){
					if((top - borrow) > 0){															//top is sufficient to satisfy the borrow
						borrow = 0;																					//borrow has been handled
						result = (top - 1);
						if(result < 10){																		//write appropriate digit
							cursor->data = result + '0';
						}
						else{
							cursor->data = result + 'a' - 10;
						}
						(*this).digits++;
					}
					else{																								//top is not sufficient to satisy the borrow
						if(cursor->prev != nullptr){
							result = ((*this).base - borrow);
							if(result < 10){																	//write appropriate digit
								cursor->data = result + '0';
							}
							else{
								cursor->data = result + 'a' - 10;
							}
							(*this).digits++;
						}
						else{
							node* first = (*this).head_ptr;
							(*this).head_ptr = (*this).head_ptr->next;
							(*this).head_ptr->prev = nullptr;
							delete first;
						}
					}
				}
				else{
					(*this).digits++;																	//no remaining digits to subtract, no borrows to handle, finish incrementing digits until head_ptr reached.
				}
			}
      
      cursor = cursor->prev;
      if(otherCursor != nullptr){
				otherCursor = otherCursor->prev;
			}
    }
    (*this).killWorthlessZeros();
		return (*this);
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
  
  // conversion constructor; convert m to a different base
	big_number::big_number(const big_number& m, unsigned int b){
		head_ptr = tail_ptr = nullptr;
		positive = m.positive;
		
		big_number zero;
		zero.base = b;
		*this = zero;
		unsigned int digit;
		
		big_number* values = new big_number[m.base + 1];
		
		big_number j = 0;
		j.base = b;
		
		for (unsigned int i = 0; i <= m.base; ++i){
			values[i] = j;
			++j;
		}
		
		for (const node* cursor = m.head_ptr; cursor != nullptr; cursor = cursor->next){
			if (isdigit(cursor->data)){
				digit = cursor->data - '0';
			}
			else{
				digit = cursor->data - 'a' + 10;
			}
			big_number intermed = values[m.base] * (*this);
			if (intermed > zero){
				intermed.sum(values[digit]);
			}
			else{
				big_number temp(intermed);
				intermed = values[digit];
				intermed += temp;
			}
			*this = intermed;
		}
		delete [] values;
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
		
		big_number thiss((*this));																								//make copies
		big_number other(b);
		
		if(thiss.base != other.base){																							//ensure same bases
			big_number temp(other, thiss.base);
			other = temp;
		}
		//sum big_numbers if both negative or both positive
		if(thiss.positive == other.positive){
			if(thiss.hasMoreDigitsThan(other) == 1){
				thiss.sum(other);
				(*this) = thiss;
			}
			else{
				other.sum(thiss);
				(*this) = other;
			}
		}
		//compute difference between big_numbers otherwise
		else{
			if(thiss.hasMoreDigitsThan(other) == 1){
				thiss.diff(other);
				(*this) = thiss;
			}
			else{
				other.diff(thiss);
				(*this) = other;
			}
		}
		return (*this);
  }

  // set value to original value * b; return answer in original number's base
  big_number& big_number::operator*= (const big_number& b){
    return *this;
  }

  // set value to original value - b; return answer in original number's base
  big_number& big_number::operator-= (const big_number& b){
    
    big_number thiss((*this));																					//make copies to play with
    big_number other(b);
    
    if(thiss.base != other.base){																				//ensure same bases
			big_number temp(other, thiss.base);
			other = temp;
		}
		//compute difference of two numbers if they are both positive or negative
		if(thiss.positive == other.positive){
			if(thiss.hasMoreDigitsThan(other)){
				thiss.diff(other);
				(*this) = thiss;
			}
			else{
				other.diff(thiss);
				(*this) = other;
			}
		}
		//sum big_numbers if both positive or both negative
		else{
			if(thiss.hasMoreDigitsThan(other)){
				thiss.sum(other);
				(*this) = thiss;
			}
			else{
				other.sum((*this));
				(*this) = other;
			}
		}
    return (*this);
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
    out << "\nbase: " << n.base << "\nbig_number: ";
		if(!n.positive){
			out << '-';
		}
    node* cursor = n.head_ptr;
    while(cursor != nullptr){
      out << cursor->data;
      cursor = cursor->next;
    }
    out << "\ndigits: " << n.digits << "\nhead_ptr: " << n.head_ptr->data << "\ntail_ptr: " << n.tail_ptr->data << "\npositive: ";
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
    big_number answer(a);
    answer += b;
    return answer;
  }

  big_number operator-(const big_number& a, const big_number& b){
    big_number answer(a);
    answer -= b;
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


