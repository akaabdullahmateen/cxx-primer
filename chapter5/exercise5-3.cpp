// Exercise 5.3: Use the comma operator (§ 4.10, p. 157) to rewrite the while loop from § 1.4.1 (p. 11)
// So that it no longer requires a block.
// Explain whether this rewrite improves or diminishes the readability of this code.

#include <iostream>

int main () {
	int sum = 0, val = 0;

	while (++val, val <= 10) sum += val;

	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	return 0;
}

// This dimished the readability of the program,
// since new programmers unexperiences with comma-operators might have hard time
// figuring out why writing two expressions in while loop condition is legal