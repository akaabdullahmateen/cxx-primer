// Exercise 4.21: Write a program to use a conditional operator
// To find the elements in a vector<int>
// That have odd value
// And double the value of each such element.

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(){
	vector<int> vec = {1,2,3,4,5,6,7,8,9};
	for(auto it = vec.begin(); it != vec.end(); ++it){
		*it = *it % 2 ? *it * 2 : *it;
		// v = v % 2 ? v * 2 : v
		// v = v % 2 ? v * 2 : v
		// v = (v % 2) ? v * 2 : v
		// v = ((v % 2) ? v * 2 : v)
	}
	// Operator Associativity 	Purpose
	//---------|---------------|-----------
	// *		R 				dereference
	// %		L 				modulus
	// *		L 				multiply
	// ?:		R 				conditional
	// =		R 				assignment
	for(const int &i : vec){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}