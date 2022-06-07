// Exercise 5.24: Revise your program to throw an exception if the second number is zero
// Test your program with a zero input to see what happens on your system if you don’t catch an exception.

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main(){
	int first = 0;
	int second = 0;
	cout << "(1) >> ";
	cin >> first;
	cout << "(2) >> ";
	cin >> second;
	if(!second){
		throw runtime_error("Cannot divide by zero");
	}
	cout << "[DIVISON] " << first / second << endl;
	return 0;
}