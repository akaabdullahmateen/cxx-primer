// Exercise 6.38: Revise the arrPtr function to return a reference to the array.

#include <iostream>

using std::cout;
using std::endl;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

decltype(odd) &arrPtr(int i){
	return (i % 2) ? odd : even;
}

int main(){
	int (&arr)[5] = arrPtr(0);
	for(const int i : arr){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}