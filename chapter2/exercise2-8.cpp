// Exercise 2.8: Using escape sequences, write a program to print 2M followed by a newline
// Modify the program to print 2, then a tab, then an M, followed by a newline

#include <iostream>

int main(){
	std::cout << "\x32\x4D\x0A";
	std::cout << "\x32\x09\x4D\x0A";

	return 0;
}