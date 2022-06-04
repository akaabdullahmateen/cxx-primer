// Exercise 4.36: Assuming i is an int and d is a double
// Write the expression i *= d so that it does integral
// Rather than floating-point, multiplication

#include <iostream>

using std::cout;
using std::endl;

int main(){
	int i = 7;
	double d = 2.3;
	// floating-point multiplication => 7 * 2.3 = 16.1
	// integer multiplication => 7 * 2 = 14
	i *= static_cast<int>(d);
	cout << i << endl;
	return 0;
}