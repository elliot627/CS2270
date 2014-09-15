#include "singly_linked_list.h"

using namespace std;

void add_node(node*& head_ptr, const int& payload)
{

}

bool remove_node(node*& head_ptr, const int& target)
{
	return false;
}

bool find_list(const node*& head_ptr, const int& target)
{
	return false;
}

void clear_list(node*& head_ptr)
{

}

void print_list(const node*& head_ptr)
{
	const node* cursor = head_ptr;
	while (cursor != nullptr)
	{
		cout << cursor->data << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

void copy_list(const node*& source_ptr, node*& dest_ptr)
{

}

