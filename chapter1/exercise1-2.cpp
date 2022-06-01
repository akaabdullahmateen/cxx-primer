// Exercise 1.2: Change the program to return -1.
// A return value of -1 is often treated as an indicator that the program failed.
// Recompile and rerun your program to see how your system treats a failure indicator from main

// Positive return values (including zero), makes the status code (as retrieved through "echo $?" on UNIX systems) the same as the return value.
// However, negative return values makes status code calculated as: status_code = 256 - return_value
// Therefore, a return value of -1 will give a status code of 255

int main(){
	return -1;
}