#include <iostream>

struct char_array {
	char* data;
	unsigned int count;
	unsigned int capacity;
	static const unsigned int DEFAULT_CAPACITY = 20;
};

void init(char_array& arr);

void destr(char_array& arr);

void resize(char_array& arr);

void clear(char_array& arr);

void add(char_array& arr, const char& payload);

bool contains(const char_array& arr, const char& target);

bool remove(char_array& arr, const char& target);

void print(const char_array& arr);

