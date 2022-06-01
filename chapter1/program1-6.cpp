#include <iostream>

int main(){
	int curr_val = 0;
	int count = 0;
	int val = 0;

	// The outer if statement only executes when there is valid input to read
	// Therefore, if no valid input is entered, the program simply returns and prints nothing
	if(std::cin >> curr_val){

		// On valid input, the count variable is initialized to one value, to indicate that the curr_val is encountered one time already
		count = 1;

		// The while loop keeps running as long as subsequent valid inputs are entered
		while(std::cin >> val){

			// If the subsequent valid input is the same as the curr_val - the previous valid input
			if(val == curr_val){

				// The count is incremented
				++count;
			}

			// Else, a distinct value is entered, therefore, we flush the previous record
			// And initialize our variables appropriately to account for a change in curr_val
			else{
				std::cout << curr_val << ": " << count << std::endl;
				count = 1;
				curr_val = val;
			}
		}

		// Remember, that the standard output was only printed to, when a distinct value is first encountered
		// Therefore, the last series of values will not be printed on termination of the loop, in case of invalid or end-of-file input
		// As such, we much manually flush the last record
		std::cout << curr_val << ": " << count << std::endl;
	}

	return 0;
}