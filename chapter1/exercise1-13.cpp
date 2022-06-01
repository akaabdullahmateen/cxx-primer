// Exercise 1.13: Rewrite the first two exercises from § 1.41 (p. 13) using for loops
// § 1.41 Exercise 1.9: Write a program that uses a while loop to sum numbers from 50 to 100
// § 1.41 Exercise 1.10: In addition to the ++ operator that adds 1 to its operand
// There is a decrement operator (--) that subtracts 1
// Use the decrement operator to write a while loop that prints the numbers from ten down to zero

#include <iostream>

int main(){
	int sum = 0;

	for(int i = 50; i <= 100; ++i){
		sum += i;
	}

	std::cout << sum << std::endl;
	std::cout << "----" <<std::endl;

	for(int i = 10; i >= 0; --i){
		std::cout << i << std::endl;
	}

	return 0;
}