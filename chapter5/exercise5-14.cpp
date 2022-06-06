// Exercise 5.14: Write a program to read strings from standard input looking for duplicated words.
// The program should find places in the input where one word is followed immediately by itself.
// Keep track of the largest number of times a single repetition occurs and which word is repeated.
// Print the maximum number of duplicates,
// Or else print a message saying that no word was repeated.
// For example, if the input is:
// how now now now brown cow cow
// The output should indicate that the word now occurred three times.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	string word;
	string last;
	string winner;
	string::size_type highest = 0;
	string::size_type repition = 0;
	cout << ">> ";
	while(cin >> word){
		if(word == last){
			++repition;
		}
		else{
			if(repition > highest){
				highest = repition;
				winner = last;
			}
			repition = 0;
		}
		last = word;
		cout << ">> ";
	}
	cout << "\b\b\b   \b\b  \b \n";
	if(repition > highest){
		highest = repition;
		winner = last;
	}
	if(highest == 0){
		cout << "[NO WORD WAS REPEATED]" << endl;
	}
	else {
		cout << "[WORD] : " << winner << "\t[COUNT] : " << highest + 1 << endl;
	}
	return 0;
}