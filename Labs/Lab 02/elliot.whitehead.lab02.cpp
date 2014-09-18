//Elliot Whitehead
//09-04-14
//CS 2270

#include <iostream>
using namespace std;

int main(){
	
	//prompt user for upper number range
	cout << "Welcome! Please enter desired number range (greater than 0): ";
	unsigned int upperRange;
	cin >> upperRange;
	
	upperRange++;
	
	bool primeNums[upperRange];
	
	//set 0 & 1 to false
	primeNums[0] = false;
	primeNums[1] = false;
	
	//assign all other values to true
	for(unsigned int i = 2; i < sizeof(primeNums); i++){
		primeNums[i] = true;
	}
	
	//kill the non-primes!
	unsigned int base = 2;
	while(base < upperRange - 1){
		unsigned int multiple = 2;
		while((multiple * base) <= upperRange - 1){
			primeNums[(base * multiple)] = false;
			multiple++;
		}
		base++;
	}
	
	//print out primeNums array
	cout << "\nNumber\t|\tPrime?" << endl;
	cout << "-----------------------" << endl;
	for(unsigned int i = 0; i < sizeof(primeNums); i++){
		cout << i << "\t|\t" << primeNums[i] << endl;
	}	
}
