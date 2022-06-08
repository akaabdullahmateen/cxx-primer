// Exercise 6.22: Write a function to swap two int pointers.

#include <iostream>

using std::cout;
using std::endl;

void swap(const int *&p1, const int *&p2){
	const int * const temp = p1;
	p1 = p2;
	p2 = temp;
}

int main(){
	const int i = 5;
	const int j = 6;
	const int *p1 = &i;
	const int *p2 = &j;
	cout << "(p1) : " << p1 << endl;
	cout << "(p2) : " << p2 << endl;
	swap(p1, p2);
	cout << "(p1) : " << p1 << endl;
	cout << "(p2) : " << p2 << endl;
	return 0;
}