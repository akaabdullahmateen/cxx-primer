// Exercise 6.27: Write a function that takes an initializer_list<int>
// And produces the sum of the elements in the list

#include <iostream>
#include <initializer_list>

using std::initializer_list;
using std::cout;
using std::endl;

int sum(initializer_list<int> li){
	int sum = 0;
	for(const int i : li){
		sum += i;
	}
	return sum;
}

int main(){
	cout << sum({1,2,3,4,5,6}) << endl;
	return 0;
}