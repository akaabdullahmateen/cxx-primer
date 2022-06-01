// Exercise 1.23: Write a program that reads several transactions and counts how many transactions occur for each ISBN

#include <iostream>
#include <map>
#include "Sales_item.h"

int main(){
	std::map<std::string, int> record;
	Sales_item item;

	while(std::cin >> item){
		record[item.isbn()]++;
	}

	for (const auto& [key, value] : record) {
        std::cout << '[' << key << "] = " << value << std::endl;
    }

	return 0;
}