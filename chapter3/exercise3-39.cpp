// Exercise 3.39: Write a program to compare two strings.
// Now write a program to compare the values of two C-style character strings.

#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main(){
	string str1("alpha");
	string str2("alpha");

	cout << "(is equal?) " << (str1 == str2) << endl;
	cout << "(is greater?) " << (str1 > str2) << endl;
	cout << "(is lesser?) " << (str1 < str2) << endl;

	const char cstr1[] = {'a','l','p','h','a',0};
	const char cstr2[] = {'a','l','p','h','a',0};

	cout << "(comparison?) " << strcmp(cstr1, cstr2) << endl;
	return 0;
}