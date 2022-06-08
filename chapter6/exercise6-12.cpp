// Exercise 6.12: Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210)
// To use references instead of pointers to swap the value of two ints
// Which version do you think would be easier to use and why?

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

void swap(int &a, int &b){
	const int temp = a;
	a = b;
	b = temp;
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
	swap(a, b);
	cout << "(a) : " << a << " \t (b) : " << b << endl;
	return 0;
}

// I would prefer the version of swap which uses references instead of pointers
// because with pointers, there is need for checking its validity and whether or not it is a nullptr
// with references, however, if the bound object is valid, it is guaranted that the reference is valid as well
// also, with pointers, there is added complication of passing address-of object, and operating on dereferenced versions
// since, dereference and address-of operators needs to be used with caution, there are most chances of error, and program crashing