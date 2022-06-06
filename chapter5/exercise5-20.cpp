// Exercise 5.20: Write a program to read a sequence of strings from the standard input
// Until either the same word occurs twice in succession or all the words have been read
// Use a while loop to read the text one word at a time.
// Use the break statement to terminate the loop if a word occurs twice in succession.
// Print the word if it occurs twice in succession
// Or else print a message saying that no word was repeated

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	string current;
	string last;
	bool found = false;
	cout << ">> ";
	while(cin >> current){
		if(!current.empty() && current == last){
			found = true;
			break;
		}
		last = current;
		cout << ">> ";
	}
	cout << "\b\b\b   \b\b  \b \n";
	if(found){
		cout << "[WORD] : " << current << " (occured twice)" << endl;
	}
	else{
		cout << "[NO REPITIONS FOUND]" << endl;
	}
	return 0;
}