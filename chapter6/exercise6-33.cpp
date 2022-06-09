// Exercise 6.33: Write a recursive function to print the contents of a vector.

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void print(vector<int> &v, vector<int>::size_type i){
	if(i){
		print(v, i - 1);
	}
	cout << v.at(i) << " ";
}

int main(){
	vector<int> v = {1,2,3,4,5,6};
	print(v, v.size() - 1);
	cout << endl;
	return 0;
}