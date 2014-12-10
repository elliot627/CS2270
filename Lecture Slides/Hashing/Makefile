# All compilations occur with -Wall to print warnings, and -g to allow gdb debugging.
# The clean command uses rm to remove all expendable files (rm is part of
# the cs1300 compiler tools from www.cs.colorado.edu/~main/cs1300/README.html).

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = test_open_address_hash.o test_open_address_hash hash1.o 

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your queue and singly_linked_list class together
test_open_address_hash: test_open_address_hash.o hash1.o 
	g++ -std=c++0x -Wall -g test_open_address_hash.o hash1.o -o test_open_address_hash

hash1.o: hash1.h hash1.cpp 
	g++ -std=c++0x -Wall -g -c hash1.cpp -o hash1.o

test_open_address_hash.o: test_open_address_hash.cpp hash1.h
	g++ -std=c++0x -Wall -g -c test_open_address_hash.cpp -o test_open_address_hash.o

# this deletes all the output files
clean:
	rm -f $(EXPENDABLES)
