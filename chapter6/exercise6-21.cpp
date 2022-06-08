// Exercise 6.21: Write a function that takes an int and a pointer to an int
// And returns the larger of the int value or the value to which the pointer points
// What type should you use for the pointer?

#include <iostream>

using std::cout;
using std::endl;

int find_max(const int i, const int * const p){	
	return (i >= *p) ? i : *p;
}

int main(){
	int i = -6;
	int j = -13;
	cout << find_max(i, &j) << endl;
	return 0;
}

// Since, modifying the value (address stored within) of pointer is likely to make it invalid
// The pointer has top-level const-qualification
// Also, we do not need to change the pointed object's value - only read it
// The pointer also has low-level const-qualification