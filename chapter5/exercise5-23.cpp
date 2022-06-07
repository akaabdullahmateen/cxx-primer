// Exercise 5.23: Write a program that reads two integers from the standard input
// And prints the result of dividing the first number by the second

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int first = 0;
	int second = 0;
	cout << "(1) >> ";
	cin >> first;
	cout << "(2) >> ";
	cin >> second;
	cout << "[DIVISON] " << first / second << endl;
	return 0;
}