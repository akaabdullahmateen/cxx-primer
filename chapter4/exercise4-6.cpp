// Exercise 4.6: Write an expression to determine whether an int value is even or odd.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int i;
	cout << ">> ";
	cin >> i;

	if(i % 2){
		cout << "(odd)" << endl;
	}
	else{
		cout << "(even)" << endl;
	}
	return 0;
}