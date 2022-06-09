// Exercise 6.36: Write the declaration for a function that returns a reference to an array of ten strings
// Without using either a trailing return, decltype, or a type alias

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string arr[10] = {"aeta", "beta", "ceta", "deta", "eeta", "feta", "geta", "heta", "ieta", "jeta"};

string (&dummy_func())[10]{
	return arr;
}

int main(){
	string (&arr_local)[10] = dummy_func();
	for(const string &s : arr_local){
		cout << s << endl;
	}
	return 0;
}