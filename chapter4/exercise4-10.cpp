// Exercise 4.10: Write the condition for a while loop that would read ints from the standard input
// And stop when the value read is equal to 42.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int i = 0;
	bool is_prompt = true;
	cout << ">> ";
	while(cin >> i){
		if(i == 42){
			cout << "[TERMINATED]" << endl;
			is_prompt = false;
			break;
		}
		is_prompt = true;
		cout << i << "\n>> ";
	}
	if(is_prompt){
		cout << "\b\b\b   \b\b  \b \n";
	}
	return 0;
}