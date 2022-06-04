// Exercise 4.29: Predict the output of the following code and explain your reasoning.
// Now run the program. Is the output what you expected? If not, figure out why.

#include <iostream>

using std::cout;
using std::endl;

int main(){
	int x[10];
	int *p = x;
	// int width 4 bytes
	// x width 10 * 4 = 40 bytes
	// *x points to the first int in x
	// *x width 4 bytes
	// sizeof(x) / sizeof(*x) = 10
	// pointer to int, p, is stored in 8 bytes
	// pointer points to x array
	// but since array decayed to pointer
	// p is the same x
	// *p is the first element in x
	// sizeof(p) / sizeof(*p) = 8 / 4 = 2
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
	return 0;
}