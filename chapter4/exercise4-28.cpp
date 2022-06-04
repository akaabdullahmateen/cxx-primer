// Exercise 4.28: Write a program to print the size of each of the built-in types.

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
	cout << "[TYPE]\t\t\t[MINIMUM]\t\t[ACTUAL]" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "(signed char)\t\t8 bits\t\t\t" 		<< sizeof(signed char) * 8 	<< " bits" << endl;
	cout << "(short int)\t\t16 bits\t\t\t" 		<< sizeof(short int) * 8 	<< " bits" << endl;
	cout << "(int)\t\t\t16 bits\t\t\t" 			<< sizeof(int) * 8 			<< " bits" << endl;
	cout << "(long int)\t\t32 bits\t\t\t" 		<< sizeof(long int) * 8 	<< " bits" << endl;
	cout << "(long long int)\t\t64 bits\t\t\t" 	<< sizeof(long int) * 8 	<< " bits" << endl;
	cout << "(string)\t\t-- bits\t\t\t"			<< sizeof(string) * 8		<< " bits" << endl;
	cout << "(vector)\t\t-- bits\t\t\t"			<< sizeof(vector<int>) * 8	<< " bits" << endl;
	return 0;
}