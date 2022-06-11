// Exercise 6.56: Call each element in the vector and print their result.

#include <iostream>
#include <vector>
#include <string>

int add(int a, int b){
	std::string uppercase_func = __func__;
	for(char &c : uppercase_func){
		c = std::toupper(c);
	}
	std::cout << "[" << uppercase_func << "] : " << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "[ARGUMENTS] : int a = " << a << ", int b = " << b << std::endl;
	int ret = a + b;
	std::cout << "[RETURN] : " << ret << std::endl << std::endl;
	return ret;
}

int subtract(int a, int b){
	std::string uppercase_func = __func__;
	for(char &c : uppercase_func){
		c = std::toupper(c);
	}
	std::cout << "[" << uppercase_func << "] : " << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "[ARGUMENTS] : int a = " << a << ", int b = " << b << std::endl;
	int ret = a - b;
	std::cout << "[RETURN] : " << ret << std::endl << std::endl;
	return ret;
}

int multiply(int a, int b){
	std::string uppercase_func = __func__;
	for(char &c : uppercase_func){
		c = std::toupper(c);
	}
	std::cout << "[" << uppercase_func << "] : " << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "[ARGUMENTS] : int a = " << a << ", int b = " << b << std::endl;
	int ret = a * b;
	std::cout << "[RETURN] : " << ret << std::endl << std::endl;
	return ret;
}

int divide(int a, int b){
	std::string uppercase_func = __func__;
	for(char &c : uppercase_func){
		c = std::toupper(c);
	}
	std::cout << "[" << uppercase_func << "] : " << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "[ARGUMENTS] : int a = " << a << ", int b = " << b << std::endl;
	int ret = a / b;
	std::cout << "[RETURN] : " << ret << std::endl << std::endl;
	return ret;
}

int main(){
	std::cout << __func__ << " : " << __FILE__ << " v1.0 compiled on " << __DATE__ << " " << __TIME__ << std::endl << std::endl;
	std::vector<int (*) (int, int)> v = {add, subtract, multiply, divide};
	for(int (*func)(int, int) : v){
		(*func)(4, 5);
	}
	return 0;
}
