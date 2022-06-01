// Exercise 3.36: Write a program to compare two arrays for equality.
// Write a similar program to compare two vectors.

#include <cstddef>
#include <iterator>
#include <iostream>
#include <vector>

using std::begin;
using std::end;
using std::vector;
using std::cout;
using std::endl;

using std::ptrdiff_t;
using size_type = std::vector<int>::size_type;

int main(){
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {1,2,3,4,5};

	int *pbegin1 = begin(arr1);
	int *pbegin2 = begin(arr2);

	int *pend1 = end(arr1);
	int *pend2 = end(arr2);

	ptrdiff_t size1 = pend1 - pbegin1;
	ptrdiff_t size2 = pend2 - pbegin2;

	bool is_equal = true;

	if(size1 != size2){
		is_equal = false;
	}

	for(size_t i = 0; i < size1; ++i){
		if(arr1[i] != arr2[i]){
			is_equal = false;
		}
	}

	cout << "(equal) " << is_equal << endl;

	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = {1,2,3,4,5};

	is_equal = true;

	if(v1.size() != v2.size()){
		is_equal = false;
	}

	for(size_type i = 0; i < v1.size(); ++i){
		if(v1.at(i) != v2.at(i)){
			is_equal = false;
		}
	}

	cout << "(equal) " << is_equal << endl; 

	return 0;
}