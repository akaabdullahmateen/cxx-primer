// Write a program containing the variables and assignments from the previous exercise.
// Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct.
// If not, study the exam-ples until you can convince yourself you know what led you to the wrong conclusion.

#include <iostream>

int main(){
	int i = 0, &r = i;				// i is int, r is int&
	const int ci = i, &cr = ci;		// ci is const int, cr is const int&
	auto a = r;						// a is int (r is an alias for i)
	auto b = ci;					// b is int
	auto c = cr;					// c is int (cr is an alias for ci)
	auto d = &i; 					// d is int*
	auto e = &ci;					// e is const int*
	auto &g = ci;					// g is const int&

	a = 42; 						// a is assigned 42
	b = 42; 						// b is assigned 42
	c = 42; 						// c is assigned 42
	//d = 42; 						// error: invalid conversion from int to int*
	//e = 42; 						// error: cannot assign to read-only variable
	//g = 42; 						// error: connot assign to read-only variable

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	return 0;
}