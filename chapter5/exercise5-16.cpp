// Exercise 5.16: The while loop is particularly good at executing while some condition hold.
// For example, when we need to read values until end-of-file.
// The for loop is generally thought of as a step loop:
// An index steps through a range of values in a collection.
// Write an idiomatic use of each loop and then rewrite each using the other loop construct.
// If you could use only one loop, which would you choose? Why?

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	string word;
	while(cin >> word){
		/* do something */
	}

	for(; cin >> word;){
		/* do something */		
	}

	// while loop is clearly more readable and less error-prone
	// considering the fact that you have to be careful with semicolons in for loop

	for(int i = 0; i < 10; ++i){
		/* do something */
	}

	int i = 0;
	while(i < 10){
		/* do something */
		++i;
	}

	// for loop is more readable and concise
	// although while loop can achieve the same functionality
	// it is less readable and requires more typing, plus there are more opportunities for error

	// if I have to choose one loop, it would be for loop
	// because although running loops indefinitely requires caution with syntax in for loop
	// it has places for init-statement and expression that are run at correct times
	// so if need be, the loop syntax makes it less likely to mess up
	// whereas, with while loop, one has to write a lot more and correct places
	// giving opportunity for errors and logic mistakes

	return 0;
}