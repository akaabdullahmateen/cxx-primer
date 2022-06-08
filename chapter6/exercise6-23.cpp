// Exercise 6.23: Write your own versions of each of the print functions presented in this section
// Call each of these functions to print i and j defined as follows:
// int i = 0, j[2] = {0, 1};

#include <iostream>
#include <string>
#include <cstddef>

using std::string;
using std::cout;
using std::endl;
using std::begin;
using std::end;

void print(const char *cp){
	cout << "(1) print(const char *cp)" << endl;
	if(cp){
		while(*cp){
			cout << *cp++ << " ";
		}
	}
	cout << endl;
}

void print(const int *begin, const int *end){
	cout << "(2) print(const int *begin, const int *end)" << endl;
	while(begin != end){
		cout << *begin++ << " ";
	}
	cout << endl;
}

void print(const int ia[], size_t size){
	cout << "(3) print(const int ia[], size_t size)" << endl;
	for(size_t i = 0; i != size; ++i){
		cout << ia[i] << " ";
	}
	cout << endl;
}

void print(const int (&arr)[2]){
	cout << "(4) print(const int (&arr)[2])" << endl;
	for(const int i : arr){
		cout << i << " ";
	}
	cout << endl;
}

void print(const int (*inner_arr)[2], int rowsize){
	cout << "(5) print(const int(*inner_arr)[2], size_t rowsize)" << endl;
	for(int i = 0; i != rowsize; ++i){
		print(begin(*inner_arr), end(*inner_arr));
		++inner_arr;
	}
}

int main(){
	string s = "Hello, World!";
	int i = 0, j[2] = {0, 1};
	int k[][2] = {{1,2},{3,4},{5,6},{7,8}};
	constexpr size_t i_size = 1;
	constexpr size_t j_size = 2;
	constexpr size_t k_size = 4;
	print(s.c_str());
	print(begin(j), end(j));
	print(&i, i_size);
	print(j, j_size);
	print(j);
	print(k, k_size);
	return 0;
}