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

    //if incoming int is only one digit, handle appropriately
    if(i < (*this).base){
      (*this).head_ptr->data = i + '0';
      (*this).digits = 1;
    }
    else{
      //disect i's digits, from right to left and prepend to big_num
      while(i > (*this).base){
        (*this).prepend((i % 10) + '0');                     //adding '0' to the int results in the char version of the same number
        i /= 10;
      }
      //add final digit if it is not == 0
      if(i != 0){
        (*this).prepend(i + '0');
      }
    }

  }

  // copy constructor, creates a deep copy of m
  big_number::big_number(const big_number& m){
    (*this).head_ptr = (*this).tail_ptr = new node();
    (*this).positive = m.positive;
    (*this).base = m.base;
    (*this).digits = m.digits;
    copy_list(m.head_ptr, (*this).head_ptr, (*this).tail_ptr);
  }

  // create a big_number from a string
  big_number::big_number(const string& s, unsigned int b){
    (*this).digits = 0;
    (*this).base = b;
    (*this).positive = true;
    int index = 0;

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
  }

  // destructor
  big_number::~big_number(){

  }

  // assignment operator
  big_number& big_number::operator=(const big_number& m){
    return *this;
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
    return false;
  }

  bool operator >=(const big_number& a, const big_number& b){
    return false;
  }

  bool operator <(const big_number& a, const big_number& b){
    return false;
  }

  bool operator <=(const big_number& a, const big_number& b){
    return false;
  }

  bool operator==(const big_number& a, const big_number& b){
    return false;
  }

  bool operator!=(const big_number& a, const big_number& b){
    return false;
  }

  ostream& operator <<(ostream& out, const big_number& n){
    out << "big_number: ";
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


