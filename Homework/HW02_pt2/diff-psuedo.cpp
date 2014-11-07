  //diff method for subtracting digits assumes |*this| > |m|
  big_number&  big_number::diff(const big_number& m){
		unsigned int borrow = 0;
		unsigned int top, bottom, result;
		node* cursor = tail_ptr;
		const node* mcursor = m.tail_ptr;
		
		while(cursor != nullptr){			
			top = alpha.find(cursor->data);
			if(mcursor != nullptr){
				bottom = alpha.find(mcursor->data);
				if(top >= (bottom + borrow)){
					result = top - bottom - borrow;
					borrow = 0;
				}
				else{
					result = (base + top) - (bottom - borrow);
					borrow = 1;
				}
			}
			else{
				if(top >= borrow){
						result = top - borrow;
						borrow = 0;
				}
				else{
					result = base + top - borrow;
					borrow = 1;
				}
			}
			
			//convert result to a digit character
			cursor->data = .............;
			digits++;
			cursor = cursor->prev;
			if(mcursor != nullptr){
				mcursor = mcursor->prev;
			}
		}
		(*this).killWorthlessZeros();
		
																																		//TODO - Check for -000 as a result, make positive;
	}
  
