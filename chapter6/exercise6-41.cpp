// Exercise 6.41: Which, if any, of the following calls are illegal? Why?
// Which, if any, are legal but unlikely to match the programmer’s intent? Why?

char *init(int ht, int wd = 80, char bckgrnd = ' ');

int main(){
	init();			// illegal; parameter 1: ht, does not have a default argument
	init(24,10);	// legal; 24 is passed as argument to ht, and 10 is passed as argument to wd, bckgrnd has default argument of ' '
	init(14, '*');	// legal but logically incorrect; 14 is passed as argument to ht, '*' is converted to int and passed to wd, bckgrnd is passed default argument
					// if bckgrnd is to be passed this '*' argument, then wd must also be passed a some argument
					// this is because default arguments are used for right-most (trailing) arguments of a call
	return 0;
}