// Exercise 6.7: Write a function that returns 0 when it is first called
// And then generates numbers in sequence each time it is called again.

#include <iostream>
#include <string>

using std::size_t;
using std::string;
using std::cin;
using std::cout;
using std::endl;

size_t persistent_sequence(){
	static size_t n = 0;
	return n++;
}

int main(){
	string response;
	size_t i = 0;
	while(response != "n" && response != "no"){
		cout << "CALL [" << i++ << "] : " << persistent_sequence() << endl;
		cout << "(repeat?) \'yes\' or \'no\'" << endl;
		cout << ">> ";
		cin >> response;
		for(char &c : response){
			c = tolower(c);
		}
	}
	return 0;
}