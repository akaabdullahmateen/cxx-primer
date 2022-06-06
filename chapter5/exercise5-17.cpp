// Exercise 5.17: Given two vectors of ints
// Write a program to determine whether one vector is a prefix of the other
// For vectors of unequal length, compare the number of elements of the smaller vector
// For example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8 respectively
// Your program should return true

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(){
	vector<int> first = {0, 1, 1};
	vector<int> second = {0, 1, 1, 2, 3, 5, 8};
	vector<int> smaller;
	vector<int> larger;

	if(first.size() < second.size()){
		smaller = first;
		larger = second;
	}
	else{
		smaller = second;
		larger = first;
	}

	for(vector<int>::size_type index = 0; index != smaller.size(); ++index){
		if(smaller.at(index) != larger.at(index)){
			cout << "VERDICT: FALSE \t [ELEMENT MISMATCH] (Cannot be prefixes)" << endl;
			return 0;
		}
	}
	cout << "VERDICT: TRUE \t [ELEMENT MATCH] (Are prefixes of each other)" << endl;
	return 0;
}