// Exercise 3.43: Write three different versions of a program to print the elements of ia.
// One version should use a range for to manage the iteration
// The other two should use an ordinary for loop in one case using subscripts and in the other using pointers.
// In all three programs write all the types directly.
// That is, do not use a type alias, auto, or decltype to simplify the code.

#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main(){
	constexpr size_t rowCount = 3;
	constexpr size_t colCount = 4;
	int ia[rowCount][colCount];

	for(size_t i = 0; i != rowCount; ++i){
		for(size_t j = 0; j != colCount; ++j){
			ia[i][j] = i * colCount + j;
		}
	}

	for(int (&i)[colCount] : ia){
		for(int &j : i){
			cout << j << "\t";
		}
		cout << endl;
	}

	cout << endl;

	for(size_t i = 0; i < rowCount; ++i){
		for(size_t j = 0; j < colCount; ++j){
			cout << ia[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

	for(int (*p)[colCount] = begin(ia); p != end(ia); ++p){
		for(int *q = begin(*p); q != end(*p); ++q){
			cout << *q << "\t";
		}
		cout << endl;
	}

	return 0;
}