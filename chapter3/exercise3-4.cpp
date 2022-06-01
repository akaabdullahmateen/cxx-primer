// Exercise 3.4: Write a program to read two strings.
// And report whether the strings are equal.
// If not, report which of the two is larger.
// Now change the program to report whether the strings have the same length.
// And if not, report which is longer.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	string s1, s2;
	string prompt = ">> ";

	cout << "Please do not terminate the program using CTRL+D (end-of-file) input!" << endl;

	cout << prompt;
	cin >> s1;
	cout << prompt;
	cin >> s2;

	if(s1 == s2){
		cout << "EQUAL CHARACTERS: both strings have same characters sequence" << endl;
	}
	else{
		cout << "UNEQUAL CHARACTERS: ";

		if(s1 > s2){
			cout << "s1: " << s1 << " is case-sensitive dictionary-wise greater than s2: " << s2 << endl; 
		}
		else{
			cout << "s2: " << s2 << " is case-sensitive dictionary-wise greater than s1: " << s1 << endl; 

		}
	}

	if(s1.size() == s2.size()){
		cout << "EQUAL LENGTH: both strings have the same length of characters" << endl;
	}
	else{
		cout << "UNEQUAL LENGTH: ";

		if(s1.size() > s2.size()){
			cout << "s1: " << s1 << " has larger length than s2: " << s2 << endl; 
		}
		else{
			cout << "s2: " << s2 << " has larger length than s1: " << s1 << endl;
		}
	}

	return 0;
}