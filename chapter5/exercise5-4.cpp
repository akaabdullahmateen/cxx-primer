// Exercise 5.4: Explain each of the following examples, and correct any problems you detect.

#include <string>

using std::string;

bool find(string word){
	if(word.empty()) return false;
	return true;
}

int main(){

	// error: condition of while loop can be either an expression or initialized declaration
	// since the ill-formed expression string::iterator iter != s.end() is neither an initialization declaration or an expression
	// the compiler thinks this is an ill-formed initialization declaration
	// and complains with the error message: expected initializer before "!=" token

	// correction: since the purpose of the control structure is to check whether iter (string iterator) is not equal to s.end()
	// declare or init-declare iter before the loop

	// note: although the following loop is now legal, it will never terminate
	// since, neither is iter initialized, nor is its value updated in the statement's body

	// advice: initialize iter to s.begin() and increment this iterator on each iteration

	std::string s("some_string");

	string::iterator iter = s.begin();

	while (iter != s.end()) {
		/* . . . */
		++iter;
	}

	// explanation: this works fine because on every iteration
	// the boolean variable status is defined (created) and initialized by calling find(word)
	// this causes the init-definition to be evaluated, and return its left-hand operand - status
	// status is tested for its truth value
	// since status is a bool variable, the loop will terminate when status is initialized with false or zero

	// advice: suggest parentheses around assignment used as truth value
	// compiler advices this because it equality operator is often confused with assignment operator
	// therefore assignments should be explicit to make the intentions clear to the compiler

	string word = s;

	bool status;

	while ((status = find(word))) {
		/* . . . */
	}

	// error: status is defined inside the control structure of previous loop
	// and is only visible inside that statement
	// using it inside the if statement below will cause compilation error
	// as status is out of scope

	// correction: define status outside of the statement

	if (!status) {
		/* . . . */
	}

	return 0;
}