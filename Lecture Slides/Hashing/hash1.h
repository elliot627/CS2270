#ifndef HASH1_H
#define HASH1_H
#include <cstdlib>  // Provides size_t
#include <iostream> // Provides istream and ostream
#include <vector>
#include <map>
#include <deque>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
//#include <pair>
	
class open_address_hashtable
{
	public:
	
	// CONSTRUCTORS and DESTRUCTORS
	open_address_hashtable();
	~open_address_hashtable();
	
	// MEMBER FUNCTIONS
	bool insert(unsigned int key, std::string s);
	bool remove(unsigned int key, std::string s);
	bool find(unsigned int key, std::string s);

	private:
		// list of cities
		std::pair<int, std::string>** entries;
		const unsigned int size = 3079;
		unsigned int count;
	};

	
#endif



