// Exercise 1.11: Write a program that prompts the user for two integers
// Print each number in the range specified by those two integers

#include <iostream>

int main(){
	int min = 0;
	int max = 0;
	int tmp = 0;

	std::cout << "Enter min value: ";
	std::cin >> min;
	std::cout << "Enter max value: ";
	std::cin >> max;

	if(min > max){
		tmp = min;
		min = max;
		max = tmp;
	}

	while(min <= max){
		std::cout << min << std::endl;
		min++;
	}

	return 0;
}