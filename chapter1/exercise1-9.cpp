//Exercise 1.9: Write a program that uses the a while loop to sum the numbers from 50 to 100

#include <iostream>

int main(){
	int i = 50;
	int sum = 0;

	while(i <= 100){
		sum += i;
		++i;
	}

	std::cout << "The sum of all numbers from 50 through 100 (inclusive) is " << sum << std::endl;
	return 0;
}