// Exercise 3.5: Write a program to read strings from the standard input
// Concatenating what is read into one large string
// Print the concatenated string
// Next change the program to separate adjacent input strings by a space

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	string str;
	string concat_string;
	string space_sep_concat_string;
	string prompt = ">> ";

	bool is_first = true;

	cout << prompt;
	
	while(cin >> str){
		concat_string += str;
		
		if(is_first){
			is_first = !is_first;
			space_sep_concat_string = str;
		}
		else{
			space_sep_concat_string = space_sep_concat_string + " " + str;
		}

		cout << prompt;
	}

	cout << "\b\b\b   \b\b  \b " << std::flush << endl;

	cout << "CONCAT_STRING: " << concat_string << endl;
	cout << "SPACE_SEP_CONCAT_STRING: " << space_sep_concat_string << endl;

	return 0;
}