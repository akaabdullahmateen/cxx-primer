// Exercise 6.51: Write all four versions of f.
// Each function should print a distinguishing message.
// Check your answers for the previous exercise.
// If your answers were incorrect,
// study this section until you understand why your answers were wrong.

#include <iostream>

using std::cout;
using std::endl;

void f(){
	#ifndef NDEBUG
		cout << __PRETTY_FUNCTION__ << endl;
	#endif
	return;
}
void f(int){
	#ifndef NDEBUG
		cout << __PRETTY_FUNCTION__ << endl;
	#endif
	return;
}
void f(int, int){
	#ifndef NDEBUG
		cout << __PRETTY_FUNCTION__ << endl;
	#endif
	return;
}
void f(double, double = 3.14){
	#ifndef NDEBUG
		cout << __PRETTY_FUNCTION__ << endl;
	#endif
	return;
}

int main(){
	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);
	return 0;
}
