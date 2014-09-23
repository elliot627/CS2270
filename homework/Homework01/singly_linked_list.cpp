#include "singly_linked_list.h"

using namespace std;

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
		}
		node* 
		while(){
			
		}
		
		
	}
	else{
		return false;
	}
}

bool find_list(const node*& head_ptr, const int& target){
	return false;
}

void clear_list(node*& head_ptr){

}

void print_list(const node*& head_ptr){
	const node* cursor = head_ptr;
	while (cursor != nullptr)
	{
		cout << cursor->data << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

void copy_list(const node*& source_ptr, node*& dest_ptr){

}

