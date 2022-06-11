// Exercise 6.55: Write four functions that add, subtract, multiply, and divide two int values.
// Store pointers to these functions in your vector from the previous exercise.

#include <iostream>
#include <vector>

int add(int a, int b){
	return a + b;
}

int subtract(int a, int b){
	return a - b;
}

int multiply(int a, int b){
	return a * b;
}

int divide(int a, int b){
	return a / b;
}

int main(){
	std::vector<int (*) (int, int)> v = {add, subtract, multiply, divide};
	std::cout << (*(v.at(0)))(5, 4) << std::endl;
	return 0;
}
