// Exercise 6.5: Write a function to return the absolute value of its argument.

#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::domain_error;

unsigned long long abs(long long n){
	return (n >= 0) ? n : -n;
}

int main(){
	long long input;
	bool is_input_successful = false;
	while(!is_input_successful){
		try{
			cout << ">> ";
			cin >> input;
			if(cin.fail()){
				throw domain_error("invalid character(s) input");
			}
			is_input_successful = true;
		}
		catch(domain_error err){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string response;
			cout << "[EXCEPTION] : " << err.what() << endl;
			cout << "(retry?) \'yes\' or \'no\'" << endl;
			cout << ">> ";
			cin >> response;
			if(!response.empty() && response.at(0) == 'n'){
				break;
			}
		}	
	}
	if(is_input_successful){
		cout << "(abs) : | " << input << " | = " << abs(input) << endl;
	}
	return 0;
}