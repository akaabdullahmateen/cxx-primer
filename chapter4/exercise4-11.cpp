// Exercise 4.11: Write an expression that tests four values, a, b, c, and d
// And ensures that a is greater than b, which is greater than c, which is greater than d.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	cout << "[a] = ";
	cin >> a;
	cout << "[b] = ";
	cin >> b;
	cout << "[c] = ";
	cin >> c;
	cout << "[d] = ";
	cin >> d;

	if(a > b && b > c && c > d){
		cout << "[TRUE]" << endl;
	}
	else{
		cout << "[FALSE]" << endl;
	}
	return 0;
}