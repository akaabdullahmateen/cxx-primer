// Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appropriate using declarations.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	
	// Exercise 1.9: Write a program that uses a while loop to sum the numbers from 50 to 100.

	int i = 50;
	int sum = 0;
	
	while(i <= 100){
		sum += i++;
	}
	
	cout << sum << endl;

	cout << "--------" << endl;

	// Exercise 1.10: In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1.
	// Use the decrement operator to write a while that prints the numbers from ten down to zero.
	
	int j = 10;

	while(j >= 0){
		cout << j-- << endl;
	}

	cout << "--------" << endl;

	// Exercise 1.11: Write a program that prompts the user for two integers.
	// Print each number in the range specified by those two integers.
	
	int min = 0;
	int max = 0;
	int temp = 0;

	cout << "(min) >> ";
	cin >> min;
	cout << "(max) >> ";
	cin >> max;

	if(min > max){
		temp = min;
		min = max;
		max = temp;
	}

	while(min <= max){
		cout << min++ << endl;
	}

	// Excluding exercises from § 2.6.2 (p. 76) for brevity!

	return 0;
}