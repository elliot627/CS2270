//Elliot Whitehead
//08-28-14
//CS 2270

#include <string>
#include <iostream>
using namespace std;

int main(){
	
	//initialization of final output string
	string topSecret;
	
	
	//Prompt for and store top secret message, and its size
	cout << "Please enter message to be encoded." << endl;
	string message;
	cin >> message;
	int messageLength = message.length();
	
	
	//prompt for and store shift amount
	cout << "How far would you like to shift?" << endl;
	int shift;
	cin >> shift;
	
	
	
	for(int i = 0; i < messageLength; i++){
		//assign ascii # for letter
		int asc = message[i];
		if((asc + shift) > 122){		//if the shift causes a letter to overflow...
			topSecret += (96 + ((asc + shift) - 122));
		}
		else{
			topSecret += (asc + shift);
		}
		
	}
	
	//TADA!
	cout << "Your encoded message is: " + topSecret << endl;
	
	
}


