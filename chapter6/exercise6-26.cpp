// Exercise 6.26: Write a program that accepts the options presented in this section
// Print the values of the arguments passed to main

#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;
using std::size_t;

int main(int argc, char *argv[]){
	size_t i = 0;
	while(argv[i]){
		cout << argv[i++] << endl;
	}
	return 0;
}