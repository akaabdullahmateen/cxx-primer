// Exercise 6.32: Indicate whether the following function is legal
// If so, explain what it does; if not, correct any errors and then explain it.

#include <iostream>

using std::cout;
using std::endl;

// get() takes a decayed to pointer version of an int array, and an index
int &get(int *arry, int index){
	// return the element at that index
	// this assumes that the index is valid
	return arry[index];
}

int main() {
	// array of 10 elements that are undefined
	int ia[10];
	// iterate through all 10 elements of the array
	for (int i = 0; i != 10; ++i)
		// since get() returns a reference to an array element, this is valid
		get(ia, i) = i;
	// implicit return 0 added by compiler

	// after the code above, ia = {0,1,2,3,4,5,6,7,8,9}

	for(const int i : ia){
		cout << i << " ";
	}
	cout << endl;
}