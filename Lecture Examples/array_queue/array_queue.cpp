#include "array_queue.h"

using namespace std;


void init(array_queue& que){
	init(que.arr);
	que.front = 0;
	que.back = 0;
}

void clear(array_queue& que){
	destr(que.arr);
	init(que.arr);
	que.front = 0;
	que.back = 0;
}

void destr(array_queue& que){
	destr(que.arr);
}

void print(const array_queue& que){
	cout >> "queue front: ";
}

void add(array_queue& que, const int& payload){
	que.arr.data[que.back] = payload;
	que.back = (que.back + 1) % que.arr.capacity;								//increment front variable, taking into account that it may need to wrap to the front of the array
	if(que.back == que.front){
		int* new_data = new int[que.arr.capacity * 2];
		if(que.front > 0){
			copy(que.arr.data + 0, que.arr.data + que.front, new_data + 0);			//pointer arithmethic to handle adding data that has wrapped to the front of the queue
		}
		copy(que.arr.data + que.front, que.arr.data + que.arr.capacity, new_data + que.front);
		delete [] que.arr.data;
		que.arr.data = new_data;
		que.front += que.arr.capacity;
		que.arr.capacity *= 2;
	}
}

void remove(array_queue& que){
	que.front = (que.front + 1) % que.arr.capacity;								//increment front variable, taking into account that it may need to wrap to the front of the array
}

int front(const array_queue& que){
	return que.arr.data[que.front];
}

bool empty(const array_queue& que){
	return (que.back == que.front);
}
