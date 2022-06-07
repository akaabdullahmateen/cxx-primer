// Exercise 5.25: Revise your program from the previous exercise to use a try block to catch the exception
// The catch clause should print a message to the user
// And ask them to supply a new number and repeat the code inside the try

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;

int main(){
	int first = 0;
	int second = 0;
	bool is_division_successful = false;
	string response;
		
	while(!is_division_successful){
		try {
			cout << "(1) >> ";
			cin >> first;
			cout << "(2) >> ";
			cin >> second;
			if(!second){
				throw runtime_error("cannot divide by zero");
			}
			cout << "[DIVISON] " << first / second << endl;
			is_division_successful = true;
		}
		catch(runtime_error err){
			cout << "[ERROR] : " << err.what() << endl;
			cout << "retry? ('yes' or 'no')\n>> ";
			cin >> response;
			if (!response.empty() && response.at(0) == 'n'){
				break;
			}
		}
	}
	return 0;
}