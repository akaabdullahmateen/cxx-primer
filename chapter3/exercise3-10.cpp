// Exercise 3.10: Write a program that reads a string of characters including punctuation
// And writes what was read but with the punctuation removed.

#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(){
	string s_str;
	string r_str;

	cout << ">> ";
	
	getline(cin, s_str, '\n');
	
	if(s_str.empty()){
		cout << "(transformed): " << "EMPTY_STRING" << endl; 
		return -1;
	}

	for(char c : s_str){
		if(!ispunct(c)){
			r_str.append(1, c);
		}
	}

	if(r_str.empty()) r_str = "EMPTY_STRING";

	cout << "(transformed): " << r_str << endl;
	return 0;
}