// Exercise 1.15: Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

// Syntax errors - The programmer has made a grammatical error in the C++ language.


#include <iostream>

int main( {
	std::cout << "Read each file." << std::endl:
	std::cout << Update master. << std::endl;
	std::cout << "Write new master." std::endl;
	return 0
}


// Type errors - Passing literal or variable of not the same type than what the function / expression / operator expects.

// Declaration errors - Failure to declare a name before it is used.


#include <iostream>

int main(){
	int v1 = 0, v2 = 0;
	std::cin >> v >> v2;
	cout << v1 + v2 << std::endl;
	return 0;
}


// Note: It is often a good idea to use the edit-compile-debug cycle when fixing errors.
// Since, an error early in source code can cause a cascading effect, it is a good practice to correct the errors in the order they are reported.