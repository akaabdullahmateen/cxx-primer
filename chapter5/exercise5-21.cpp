// Exercise 5.21: Revise the program from the exercise in § 5.5.1 (p. 191) so that
// It looks only for duplicated words that start with an uppercase letter.

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
		if(islower(current.at(0))){
			cout << ">> ";
			continue;
		}
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