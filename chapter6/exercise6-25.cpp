// Exercise 6.25: Write a main function that takes two arguments
// Concatenate the supplied arguments and print the resulting string

#include <string>
#include <iostream>
#include <stdexcept>

using std::string;
using std::cout;
using std::endl;
using std::logic_error;

int main(int argc, char *argv[]){
	try{
		if(argc < 3){
			throw logic_error("need atleast two arguments");
		}		
	}
	catch(logic_error err){
		cout << "[EXCEPTION] : " << err.what() << endl;
		cout << "(please restart the program with correct arguments!)" << endl;
		return -1;
	}
	string s1 = argv[1];
	string s2 = argv[2];
	cout << s1 + s2 << endl;
	return 0;
}