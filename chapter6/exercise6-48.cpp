// Exercise 6.48: Explain what this loop does and whether it is a good use of assert:

#include <string>
#include <iostream>
#include <cassert>

using std::string;
using std::cin;

int main(){
	string s;
	string sought = "alpha";

	// the while loop below will keep iterating until either of the following happens:
	// 1) EOF is reached, making cin invalid
	// 2) some other input error occurs, making cin invalid
	// 3) input is equal to sought, keeping cin valid

	while (cin >> s && s != sought) { } // empty body
	
	// this assert checks whether cin is still valid
	// this is a bad use of assert; assert should be used for conditions that should never happen
	// it should only be used to check for coding errors
	// cin can be invalid at runtime even if the code is perfectly valid
	// and should be handled properly by catching an exception
	// which would involve restoring the valid state of cin and clearing its buffer

	assert(cin);
	return 0;
}