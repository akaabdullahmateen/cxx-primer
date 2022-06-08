// Exercise 6.17: Write a function to determine whether a string contains any capital letters
// Write a function to change a string to all lowercase
// Do the parameters you used in these functions have the same type?
// If so, why? If not, why not?

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

bool has_any_uppercase(const string &s){
	for(const char c : s){
		if(isupper(c)){
			return true;
		}
	}
	return false;
}

void to_all_lowercase(string &s){
	for(char &c : s){
		c = tolower(c);
	}
}

int main(){
	string s = 	"Exercise 6.17: Write a function to determine whether a string contains any capital "
				"letters. Write a function to change a string to all lowercase. Do the parameters you "
				"used in these functions have the same type? If so, why? If not, why not?";

	if(has_any_uppercase(s)){
		cout << "[UPPERCASE DETECTED]" << endl;
	}

	to_all_lowercase(s);

	cout << s << endl;

	return 0;
}

// No, the parameter for has_any_uppercase() is declared as reference to const, whereas
// the parameter for to_all_lowercase() is declared as plain reference.
// This is because the former does not need to modify the value of string s, whereas the later has to.
// Sacrificing the advantages of using const qualification does not make sense for has_any_uppercase() function