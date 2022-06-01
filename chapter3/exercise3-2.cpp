// Exercise 3.2: Write a program to read the standard input a line at a time.
// Modify your program to read word at a time.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	
	string prompt = ">> ";
	string token = ";";
	string word;

	cout << prompt;

	while(cin >> word){
		
		// std::cin treats all whitespaces (newlines and spaces) the same, so there is no way to insert the prompt at the correct location (which is after a newline)
		// As such, the user needs to enter a token ";" to display the prompt for the next iteration of IO

		if(word == token){
			cout << prompt;
		}
		else{
			cout << word << endl;
		}
	}

	// Remove the last displayed prompt with no corresponding input, because we entered CTRL + D to invalidate std::cin

	cout << "\b\b\b";

	/*
	string prompt = ">> ";
	string line;

	cout << prompt;

	while(getline(cin, line)){
		if(line.empty()){
			cout << prompt;
			continue;
		}
		cout << line << endl << prompt;
	}
	cout << "\b\b\b";
	*/

	return 0;
}