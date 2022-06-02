// Exercise 3.41: Write a program to initialize a vector from an array of ints.

#include <vector>
#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main(){
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> vec(begin(arr), end(arr));
	for(int i : vec){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}