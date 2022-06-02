// Exercise 3.40: Write a program to define two character arrays initialized from string literals.
// Now define a third character array to hold the concatenation of the two arrays.
// Use strcpy and strcat to copy the two arrays into the third.

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strcat;
using std::strcpy;

int main(){
	const char cstr1[] = "string";
	const char cstr2[] = "literal";
	char cstr3[14];

	strcpy(cstr3, cstr1);
	strcat(cstr3, "_");
	strcat(cstr3, cstr2);
	
	cout << cstr3 << endl;

	return 0;
}