// Exercise 3.6: Use a range for to change all the characters in a string to X.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(){
	string s("some string");

	for(char &c : s){
		c = 'X';
	}

	cout << s << endl;

	return 0;
}