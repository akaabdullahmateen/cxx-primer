// What is the value returned by 5 + 10 * 20 / 2?

#include <iostream>

using std::cout;
using std::endl;

int main(){
	// 5 + (10 * 20) / 2
	// 5 + (200 / 2)
	// 5 + 100
	// 105
	int x = 5 + 10 * 20 / 2;
	cout << x << endl;
	return 0;
}