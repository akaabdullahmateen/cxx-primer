// Exercise 3.35: Using pointers, write a program to set the elements in an array to zero.

#include <cstddef>
#include <iterator>
#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main(){
	constexpr size_t n = 10;
	int arr[n];
	int *pbegin = begin(arr);
	int *pend = end(arr);
	for(pbegin; pbegin != pend; ++pbegin){
		*pbegin = 0;
	}
	for(int i : arr){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}