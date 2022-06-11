// Exercise 6.47: Revise the program you wrote in the exercises in § 6.3.2 (p. 228)
// that used recursion to print the contents of a vector to conditionally print information about its execution.
// For example, you might print the size of the vector on each call.
// Compile and run the program with debugging turned on and again with it turned off.

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::clog;

void print(vector<int> &v, vector<int>::size_type i){
	#ifndef NDEBUG
		clog 	<< "LOG :\t " << __FILE__ << " : In function " << __func__ << " at line " << __LINE__ << endl
				<< "\t Compiled on " << __DATE__ << " at " << __TIME__ << endl
				<< "\t vector : v has has size() = " << v.size() << " and current element " << v.at(i) << endl << endl;
	#endif
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