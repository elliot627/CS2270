#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "hash1.h"

using namespace std;

int main()
{
	string name;
	unsigned int key;
	open_address_hashtable h;
	vector<string> values;
	vector<unsigned int> keys;
    for (unsigned int k = 0; k < 10; ++k)
	{
		cout << "Enter a name: ";
		getline(cin, name);
		values.push_back(name);
		key = rand() % 1000000000;
		keys.push_back(key);
		h.insert(key, name);
	}
	
	for (unsigned int k = 0; k < 10; ++k)
	{
		key = keys[k];
		name = values[k];
		if (!h.find(key, name))
			cout << "can't find " << key << " " << name << endl;
		else
			cout << "found " << key << " " << name << endl;
		
	}	
	
	h.remove(keys[2], values[2]);
	h.remove(keys[4], values[4]);
	h.remove(keys[6], values[6]);
	
	for (unsigned int k = 0; k < 10; ++k)
	{
		key = keys[k];
		name = values[k];
		if (!h.find(key, name))
			cout << "can't find " << key << " " << name << endl;
		else
			cout << "found " << key << " " << name << endl;
	}	
}
