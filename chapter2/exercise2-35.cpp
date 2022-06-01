// Exercise 2.35: Determine the types deduced in each of the following definitions.
// Once you’ve figured out the types, write a program to see whether you were correct.

/*
* const int i = 42;				// i is const int
* auto j = i;					// j is int
* const auto &k = i;			// k is const int&
* auto *p = &i;					// p points to const int
* const auto j2 = i, &k2 = i;	// j2 is const int, k2 is const int&
*/

#include <iostream>

int main(){
	const int i = 42;
	auto j = i;
	const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;

	i = 21;						// error: cannot assign to read-only variable
	j = 84;
	k = 63;						// error: cannot assign to read-only reference
	p = &j;
	*p = 10;					// error: cannot assign to read-only location
	j2 = 5;						// error: cannot assign to read-only variable
	k2 = 2;						// error: cannot assign to read-only reference

	return 0;
}