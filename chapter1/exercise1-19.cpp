// Exercise 1.19: Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers
// So that it handles input in which the first number is smaller than the second

#include <iostream>

int main(){
	int min = 0, max = 0, tmp = 0;

	std::cout << "Min: ";
	std::cin >> min;
	std::cout << "Max: ";
	std::cin >> max;

	if(min > max){
		tmp = min;
		min = max;
		max = tmp;
	}

	for(min; min <= max; ++min){
		std::cout << min << std::endl;
	}

	return 0;
}