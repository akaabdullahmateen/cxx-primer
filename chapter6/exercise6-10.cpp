// Exercise 6.10: Using pointers, write a function to swap the values of two ints
// Test the function by calling it and printing the swapped values

#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>

using std::string;
using std::domain_error;
using std::numeric_limits;
using std::streamsize;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

bool swap(int * const a, int * const b){
	if(a == nullptr || b == nullptr){
		return false;
	}
	const int temp = *a;
	*a = *b;
	*b = temp;
	return true;
}

int main(){
	int a = 0;
	int b = 0;
	bool is_input_successful = false;
	while(!is_input_successful){
		try{
			cout << "(a) >> ";
			cin >> a;
			if(cin.fail()){
				throw domain_error("value input could not be converted to type \'int\'");
			}
			cout << "(b) >> ";
			cin >> b;
			if(cin.fail()){
				throw domain_error("value input could not be converted to type \'int\'");
			}
			is_input_successful = true;
		}
		catch(domain_error err){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string response;
			cout << "[EXCEPTION] : " << err.what() << endl;
			cout << "(retry?) \'yes\' or \'no\'" << endl;
			cout << "(response) >> ";
			cin >> response;
			if(!response.empty() && response.at(0) == 'n'){
				break;
			}
			a = 0;
			b = 0;
		}
	}
	bool is_swap_successful = swap(&a, &b);
	if(is_swap_successful){
		cout << "(a) : " << a << " \t (b) : " << b << endl;
	}
	else{
		cerr << "(pointer passed were nullptr) .. (cannot swap)" << endl;
	}
	return 0;
}