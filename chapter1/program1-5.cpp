#include <iostream>

int main(){
	int v = 0, sum = 0;

	// The input operator returns its left operand, which in this case is std::cin
	// When we use an istream as a condition, the effect is to test the state of the stream
	// If the state is valid - that is, if the stream hasn't encountered an error - then the test succeeds
	// An istream becomes invalid when we hit the end-of-file or encounter an invalid input, such as reading a value that is not an integer
	// An istream that is in an invalid state will cause the condition to yield false
	// On UNIX systems and Mac OS X machines, the end-of-file is entered from the keyboard by the combination: CTRL + d or CTRL + D
	// On Windows systems, the end-of-file is entered by hitting: CTRL + z or CTRL + Z, followed by: Enter or Return key

	while(std::cin >> v){
		sum += v;
	}
	std::cout << sum << std::endl;
}