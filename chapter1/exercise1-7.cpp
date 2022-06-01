// Exercise 1.7: Compile a program that has incorrectly nested comments


/* This is a comment
* That spans multiple lines	
* /* However, this is a nested comment
* * Although, so far, everything is fine
* */ <- This marked the end of the comment block
* Thus, this is not part of the comment
*/

int main(){
	return 0;
} 