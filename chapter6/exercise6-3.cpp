// Exercise 6.3: Write and test your own version of fact.

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::overflow_error;

unsigned long long factorial(unsigned int n){
	if(n == 0U) return 1ULL;
	const unsigned long long MAX_LONG_LONG = (1ULL << (sizeof(unsigned long long) * 8U)) - 1U;
	unsigned long long recursive_product = 1ULL;
	unsigned int i = 0;
	while(n > 1U){
		try{
			if(recursive_product > 0.5 * MAX_LONG_LONG){
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

int main(){
	unsigned int n;
	cout << ">> ";
	cin >> n;
	unsigned long long recursive_product = factorial(n);
	if(!recursive_product){
		cerr << "(exception detected) .. (program terminated)" << endl;
		return -1;
	}
	cout << "[FACTORIAL] " << n << "! : " << recursive_product << endl;
	return 0;
}