// What is the result of each of these expressions?

#include <iostream>

using std::cout;
using std::endl;

int main(){
	unsigned long ul1 = 3, ul2 = 7;
	// 		0011 (3)
	// AND 	0111 (7)
	// =	0011 (3)
	// 		0011 (3)
	// OR 	0111 (7)
	// =	0111 (7)
	// 		0011 (true)
	// && 	0111 (true)
	// =	   1 (true)
	// 		0011 (3)
	// || 	0111 (7)
	// =	   1 (true)
	// >> 3 7 1 1 NEWLINE
	cout 	<< (ul1 & ul2) 	<< "\t"
			<< (ul1 | ul2) 	<< "\t"
			<< (ul1 && ul2) << "\t" 
			<< (ul1 || ul2) << endl;
	return 0;
}
