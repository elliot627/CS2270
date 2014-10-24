#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

//singly linked list code

node* head_ptr;

void add_node(node*& head_ptr, const int& payload){
	if(head_ptr == nullptr){				//check if list is empty
		node* fresh = new node;
		fresh->data = payload;
		fresh->next = nullptr;
		head_ptr = fresh;
		return;
	}
	if(head_ptr->data > payload){			//check if payload should be first in list
		node* first = new node;
		first->data = payload;
		first->next = head_ptr;
		head_ptr = first;
		return;
	}
	node* cursor = head_ptr;
	while(cursor->next != nullptr && cursor->next->data < payload){		//traverse list until appropriate place is found
			cursor = cursor->next;
	}
	node* incoming = new node;
	incoming->data = payload;
	incoming->next = cursor->next;
	cursor->next = incoming;

}

bool remove_node(node*& head_ptr, const int& target){
	if(head_ptr != nullptr){											//ensure list is not empty
		if(head_ptr->data == target){									//handle target removal at list head
			node* unwanted = head_ptr;
			head_ptr = head_ptr->next;
			delete unwanted;
			return true;
		}
		node* cursor = head_ptr;
		while(cursor->next != nullptr){
			if(cursor->next->data == target){							//once target found, stop looking,
				break;
			}
			cursor = cursor->next;										//otherwise, keep looking
		}
		node* unwanted = cursor->next;									//and kill it!
		cursor->next = cursor->next->next;
		delete unwanted;
		return true;
	}
	else{
		return false;
	}
}

bool find_list(const node*& head_ptr, const int& target){
	if(head_ptr->next == nullptr){
		return false;													//check for empty list
	}
	if(head_ptr->data == target){										//check first item for target
		return true;
	}
	const node* cursor = head_ptr;										//otherwise, check all others
	while (cursor->next != nullptr){
		if(cursor->next->data == target){
			return true;
		}
		cursor = cursor->next;
	}
	return false;
}

void clear_list(node*& head_ptr){
	if(head_ptr == nullptr){
		return;										//base case for empty list / reaching end of list
	}
	clear_list(head_ptr->next);						//Recursive call will work to end of list, then start deleting nodes on the way back
	delete head_ptr;								//[after recursion] delete this particular node which was passed in as head_ptr
	head_ptr = nullptr;
	return;
}

void print_list(const node* head_ptr){
	const node* cursor = head_ptr;
	while (cursor != nullptr)
	{
		cout << cursor->data << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

void copy_list(const node*& source_ptr, node*& dest_ptr){
	if(dest_ptr != nullptr){								//if dest_ptr isn't already null, clear it
		clear_list(dest_ptr);
	}
	if(source_ptr != nullptr){								//proceed if source_ptr has nodes to copy
		if(source_ptr->next == nullptr){					//if source only has one node, add it and return
			add_node(dest_ptr, source_ptr->data);
			return;
		}
		add_node(dest_ptr, source_ptr->data);				//add the first node
		const node* cursor = source_ptr;
		while(cursor->next != nullptr){						//then add the rest
			add_node(dest_ptr, cursor->next->data);
			cursor = cursor->next;
		}
	}
}

void reverse_list(node* cursor){
	if(cursor == nullptr) return; 							//handles empty list
	if(cursor->next == nullptr){							//exit condition
		head_ptr = cursor;
		return;
	}
	reverse_list(cursor->next);
	cursor->next->next = cursor;									//after recursion returns, assign pointers to reverse the list!
	cursor->next = nullptr;									
}


int main(){
	add_node(head_ptr, 0);
	add_node(head_ptr, 1);
	add_node(head_ptr, 2);
	add_node(head_ptr, 3);
	add_node(head_ptr, 4);
	add_node(head_ptr, 5);
	add_node(head_ptr, 6);
	
	print_list(head_ptr);
	
	reverse_list(head_ptr);
	
	print_list(head_ptr);
	
	
}
