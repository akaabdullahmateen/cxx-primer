// Exercise 4.5: Determine the result of the following expressions.

// -30 * 3 + 21 / 5 = -90 + 4 = -86
// 30 / 3 * 21 % 5 = 10 * 21 % 5 = 210 % 5 = 0
// -30 + 3 * 21 / 5 = -30 + 63 / 5 = -30 + 12 = -18
// -30 / 3 * 21 % 4 = -10 * 21 % 4 = -210 % 4 = -2

#include <iostream>

using std::cout;
using std::endl;

int main(){
	cout << -30 * 3 + 21 / 5 << endl;
	cout << 30 / 3 * 21 % 5 << endl;
	cout << -30 + 3 * 21 / 5 << endl;
	cout << -30 / 3 * 21 % 4 << endl;
	return 0;
}

