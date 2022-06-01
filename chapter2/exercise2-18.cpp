// Exercise 2.18: Write code to change the value of a pointer. Write code to change the value to which the pointer points.

#include <iostream>

int main(){
	int i = 1024;
	int *ip = &i;

	std::cout << "Object value:\t" << i << std::endl;
	std::cout << "Object address:\t" << &i << std::endl;
	std::cout << "Pointer value:\t" << ip << std::endl;
	std::cout << "Pointer target:\t" << *ip << std::endl;

	int j = 2048;
	ip = &j;

	std::cout << "Object value:\t" << j << std::endl;
	std::cout << "Object address:\t" << &j << std::endl;
	std::cout << "Pointer value:\t" << ip << std::endl;
	std::cout << "Pointer target:\t" << *ip << std::endl;

	*ip = 3072;

	std::cout << "Object value:\t" << j << std::endl;
	std::cout << "Object address:\t" << &j << std::endl;
	std::cout << "Pointer value:\t" << ip << std::endl;
	std::cout << "Pointer target:\t" << *ip << std::endl;

	return 0;
}