// Write a program to sum the numbers from 1 through 10, inclusive, using while loop

#include <iostream>

int main(){
	int i = 1, sum = 0;
	while(i <= 10){
		sum += i;
		i++;
	}
	std::cout << sum << std::endl;
	return 0;
}