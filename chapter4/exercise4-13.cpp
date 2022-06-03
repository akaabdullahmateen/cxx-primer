// Exercise 4.13: What are the values of i and d after each assignment?

#include <iostream>

using std::cout;
using std::endl;

int main(){
	int i;
	double d;
	
	// i is int, therefore, 3.5 which is a double literal is truncated to 3
	// and stored in i, thus, i = 3
	// d is then assigned from value of i which is 3
	// thus, d is also equal to 3
	d = i = 3.5;
	cout << "[d] " << d << "\t" << "[i] " << i << endl;

	// d is a double, which is assigned the value of the double literal 3.5
	// d, hence, is assigned the value 3.5
	// i, because of type conversion is assigned the value from 3.5
	// i, thus, has the value of 3
	i = d = 3.5;
	cout << "[d] " << d << "\t" << "[i] " << i << endl;

	return 0;
}