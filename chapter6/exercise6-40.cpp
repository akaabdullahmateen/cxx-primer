// Exercise 6.40: Which, if either, of the following declarations are errors? Why?

int ff(int a, int b = 0, int c = 0);

// if a parameter has a default argument, all parameters that follow it, must also have default parameters
// however, because ht has a default argument, wd and bckgrnd must also have default arguments
char *init(int ht = 24, int wd, char bckgrnd);

int main(){
	return 0;
}