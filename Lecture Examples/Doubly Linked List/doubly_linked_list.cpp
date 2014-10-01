#include "doubly_linked_list.h"

using namespace std;

void add_node(node*& head_ptr, node*& tail_ptr, const int& payload){
	node* added_node = new node;
	added_node->data = payload;
	if (head_ptr == nullptr)											//if list is empty, add first node and assign pointers
	{
		head_ptr = added_node;
		added_node->next = nullptr;
		added_node->prev = nullptr;
		tail_ptr = head_ptr;
	}
	else
	{
		if (head_ptr->data > payload)															//if payload should be added at head
		{
			added_node->next = head_ptr;
			added_node->prev = nullptr;
			head_ptr = added_node;
		}
		else
		{
			node* cursor = head_ptr;
			while (cursor != nullptr && cursor->next != nullptr			//walk along list until appropriate place is found
				&& cursor->next->data < payload)
				cursor = cursor->next;
			if (cursor->next == nullptr)
			{
				tail_ptr = added_node;
				cursor->next = added_node;
				added_node->next = nullptr;
				added_node->prev = cursor;
			}
			else
			{
				added_node->next = cursor->next;
				added_node->prev = cursor;
				cursor->next = added_node;
			}
		}
	}
}

bool remove_node(node*& head_ptr, node*& tail_ptr, const int& target){
	if (head_ptr == nullptr) return false;

	node* removed_node_ptr = head_ptr;
	if (removed_node_ptr->data == target){
		head_ptr = head_ptr->next;
		head_ptr->prev = nullptr;
		delete removed_node_ptr;
		removed_node_ptr = nullptr;
		return true;
	}

	while (removed_node_ptr != nullptr &&
		removed_node_ptr->next != nullptr &&
		removed_node_ptr->next->data != target)
		removed_node_ptr = removed_node_ptr->next;

	if (removed_node_ptr != nullptr && removed_node_ptr->next != nullptr){
		node* next_node_ptr = removed_node_ptr->next->next;
		delete removed_node_ptr->next;
		removed_node_ptr->next = next_node_ptr;
		if(next_node_ptr != nullptr){
			next_node_ptr->prev = removed_node_ptr;
		}
		else{
			tail_ptr = removed_node_ptr;
		}
		return true;
	}

	return false;
}

bool find_list(const node* head_ptr, const int& target){
		const node* cursor = head_ptr;
	while (cursor != nullptr)
	{
		if (cursor->data == target)
			return true;
		cursor = cursor->next;
	}
	return false;
}

void clear_list(node*& head_ptr, node*& tail_ptr){
	node* destroyed_node_ptr;
	while (head_ptr != nullptr)
	{
		destroyed_node_ptr = head_ptr;
		head_ptr = head_ptr->next;
		delete destroyed_node_ptr;
	}
	tail_ptr = nullptr;
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

void print_list_backwards(const node* tail_ptr){
	cont node* cursor = tail_ptr;
	while(cursor != nullptr){
		cout << cursor->data << " ";
		cursor = cursor->prev;
	}
}

void copy_list(const node* source_head_ptr,
	node*& dest_head_ptr, node*& dest_tail_ptr)
{
	clear_list(dest_head_ptr, dest_tail_ptr);
	if (source_head_ptr == nullptr)												//check if list to be copied is empty
		return;
	dest_head_ptr = new node();
	dest_head_ptr->data = source_head_ptr->data;
	dest_head_ptr->next = nullptr;
	dest_head_ptr-prev = nullptr;
	node* cursor = dest_head_ptr;
	while (source_head_ptr->next != nullptr)
	{
		source_head_ptr = source_head_ptr->next;
		cursor->next = new node();
		cursor->next->data = source_head_ptr->data;
		cursor->next->next = nullptr;
		cursor->next->prev = cursor;
		cursor = cursor->next;
		dest_tail_ptr = cursor;
	}
}
