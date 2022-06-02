// Exercise 3.42: Write a program to copy a vector of ints into an array of ints.

#include <vector>
#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;
using std::vector;
using std::size_t;

int main(){
	vector<int> vec = {1,2,3,4,5};
	int arr[5];
	for(size_t i = 0; i < vec.size(); ++i){
		arr[i] = vec.at(i);
	}
	for(int i : arr){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}