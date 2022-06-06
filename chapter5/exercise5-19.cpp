// Exercise 5.19: Write a program that uses a do while loop
// To repetitively request two strings from the user
// And report which string is less than the other

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	string str1;
	string str2;
	string response;
	do{
		cout << "(1) >> ";
		cin >> str1;
		cout << "(2) >> ";
		cin >> str2;
		if(str1 == str2){
			cout << "[EQUAL STRINGS]" << endl;
		}
		else if(str1 < str2){
			cout << "[FORMER SHORTER]" << endl;
		}
		else if(str1 > str2){
			cout << "[LATER SHORTER]" << endl;
		}
		cout << "(continue?) 'yes' or 'no'? ";
		cin >> response; 
	}
	while(!response.empty() && response[0] != 'n');

	return 0;
}