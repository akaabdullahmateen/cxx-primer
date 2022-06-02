// Exercise 3.45: Rewrite the programs again, this time using auto.

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

	for(auto i = 0; i != rowCount; ++i){
		for(auto j = 0; j != colCount; ++j){
			ia[i][j] = i * colCount + j;
		}
	}

	for(auto &i : ia){
		for(auto j : i){
			cout << j << "\t";
		}
		cout << endl;
	}

	cout << endl;

	for(auto i = 0ul; i < rowCount; ++i){
		for(auto j = 0ul; j < colCount; ++j){
			cout << ia[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

	for(auto p = begin(ia); p != end(ia); ++p){
		for(auto q = begin(*p); q != end(*p); ++q){
			cout << *q << "\t";
		}
		cout << endl;
	}

	return 0;
}