// Exercise 6.11: Write and test your own version of reset that takes a reference.

#include <iostream>

using std::cout;
using std::endl;

void reset(int &i){
	i = 0;
}

void reset(long int &i){
	i = 0L;
}

void reset(long long int &i){
	i = 0LL;
}

int main(){
	int dummy_int = 5;
	long int dummy_long_int = 5L;
	long long int dummy_long_long_int = 5LL;

	cout << "(before reset)" << endl;
	cout << "[INT] : \t\t" << dummy_int << endl;
	cout << "[LONG INT] : \t\t" << dummy_long_int << endl;
	cout << "[LONG LONG INT] : \t" << dummy_long_long_int << endl;

	reset(dummy_int);
	reset(dummy_long_int);
	reset(dummy_long_long_int);

	cout << endl;
	cout << "(after reset)" << endl;
	cout << "[INT] : \t\t" << dummy_int << endl;
	cout << "[LONG INT] : \t\t" << dummy_long_int << endl;
	cout << "[LONG LONG INT] : \t" << dummy_long_long_int << endl;

	return 0;
}