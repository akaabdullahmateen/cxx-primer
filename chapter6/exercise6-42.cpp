// Exercise 6.42: Give the second parameter of make_plural (§ 6.3.2, p. 224) a default argument of ’s’
// Test your program by printing singular and plural versions of the words success and failure.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string make_plural(const string &word, const string &ending = "s"){
	return word + ending;
}

int  main(){
	string str1 = "success";
	string str2 = "failure";
	cout << "[SINGULAR] \t " << str1 << endl;
	cout << "[PLURAL] \t " << make_plural(str1, "es") << endl;
	cout << "[SINGULAR] \t " << str2 << endl;
	cout << "[PLURAL] \t " << make_plural(str2) << endl;
	return 0;
}