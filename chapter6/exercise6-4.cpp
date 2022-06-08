// Exercise 6.4: Write a function that interacts with the user
// Asking for a number and generating the factorial of that number
// Call this function from main.

#include <iostream>
#include <stdexcept>
#include <climits>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::overflow_error;

unsigned long long factorial(unsigned int n){
	if(n == 0U) return 1ULL;
	unsigned long long recursive_product = 1ULL;
	unsigned int i = 0;
	while(n > 1U){
		try{
			if(recursive_product > 0.5 * ULLONG_MAX){
				throw overflow_error("(recursive product) overflowed max representable value");
			}
			recursive_product *= n--;
			cout << "[" << ++i << "] " <<  recursive_product << endl;		
		}
		catch(overflow_error err){
			cout << "[EXCEPTION] : " << err.what() << endl;
			cout << "(cannot continue) .. (need to terminate)" << endl;
			cout << "(corrupted value) : " << recursive_product << endl;
			return 0;
		}
	}
	return recursive_product;
}

void begin_session(){
	unsigned int n;
	cout << ">> ";
	cin >> n;
	unsigned long long recursive_product = factorial(n);
	if(!recursive_product){
		cerr << "(exception detected) .. (program terminated)" << endl;
		return;
	}
	cout << "[FACTORIAL] " << n << "! : " << recursive_product << endl;
}

int main(){
	begin_session();
	return 0;
}