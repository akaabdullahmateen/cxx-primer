// Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25).
// For now, you should define your Sales_data class in the same file as your main function.

#include <iostream>
#include <string>

struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

int main(){
	Sales_data total, trans;
	double price = 0;
	unsigned count = 0;

	if(std::cin >> total.bookNo >> total.units_sold >> price){
		total.revenue = total.units_sold * price;
		std::cout << "Transaction: " << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;

		Sales_data trans;
		count = 1;

		while(std::cin >> trans.bookNo >> trans.units_sold >> price){
			trans.revenue = trans.units_sold * price;
			std::cout << "Transaction: " << trans.bookNo << " " << trans.units_sold << " " << trans.revenue << std::endl;
			
			if(total.bookNo == trans.bookNo){
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
				count++;
			}
			else{
				std::cout << "Record: " << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << std::endl;
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
				count = 1;
			}
		}

		std::cout << "Record: " << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << std::endl;
	}
	else{
		std::cerr << "(no data)" << std::endl;
		return -1;
	}

	return 0;
}

/*
#include <iostream>
#include <string>

struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

int main(){
	Sales_data data1, data2;
	double price = 0;

	std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;

	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;

	std::cout << data1.bookNo << data1.units_sold << data1.revenue << std::endl;
	std::cout << data2.bookNo << data2.units_sold << data2.revenue << std::endl;

	if(data1.bookNo == data2.bookNo){
		unsigned totalCount = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;

		std::cout << data1.bookNo << " " << totalCount << " " << totalRevenue << " ";

		if(totalCount != 0){
			std::cout << totalRevenue/totalCount << std::endl;
		}
		else{
			std::cout << "(no sales)" << std::endl;
			return 0;
		}
	}
	else{
		std::cerr << "Data must refer to the same ISBN" << std::endl;
		return -1;
	}
}
*/