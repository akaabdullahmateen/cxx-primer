// Exercise 1.24: Test the previous program by giving multiple transactions representing multiple ISBNs
// The records for each ISBN should be grouped together

#include <iostream>
#include "Sales_item.h"

int main(){

	std::string curr_isbn = "";
	int count = 0;
	Sales_item item;

	// Outer if statemeent helps us set the current ISBN for the inner loop
	// Otherwise, how can the while loop know what is the initial ISBN to check against?
	if(std::cin >> item){
		curr_isbn = item.isbn();
		count = 1;

		while(std::cin >> item){
			if(item.isbn() == curr_isbn){
				count++;
			}
			else{
				std::cout << curr_isbn << " : " << count << std::endl;
				curr_isbn = item.isbn();
				count = 1;
			}
		}
		std::cout << curr_isbn << " : " << count << std::endl;
	}

	return 0;
}