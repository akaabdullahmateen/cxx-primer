// Exercise 3.44: Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.

#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;
using std::begin;
using std::end;

using int_arr = int[4];

int main(){
	constexpr size_t rowCount = 3;
	constexpr size_t colCount = 4;
	int ia[rowCount][colCount];

	for(size_t i = 0; i != rowCount; ++i){
		for(size_t j = 0; j != colCount; ++j){
			ia[i][j] = i * colCount + j;
		}
	}

	for(int_arr &i : ia){
		for(int j : i){
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

	for(int_arr *p = begin(ia); p != end(ia); ++p){
		for(int *q = begin(*p); q != end(*p); ++q){
			cout << *q << "\t";
		}
		cout << endl;
	}

	return 0;
}