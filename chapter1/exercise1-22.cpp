// Exercise 1.22: Write a program that reads several transactions for the same ISBN
// Write the sum of all the transactions that were read

#include <iostream>
#include "Sales_item.h"

int main(){
	Sales_item item, sum;
	
	if(std::cin >> item){
		sum = item;
	
		while(std::cin >> item){
			sum += item;
		}
	}
	
	std::cout << sum << std::endl;
	return 0;
}