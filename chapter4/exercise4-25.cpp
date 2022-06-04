// Exercise 4.25: What is the value of ~’q’ << 6 on a machine with 32-bit ints and 8 bit chars
// That uses Latin-1 character set in which ’q’ has the bit pattern 01110001?

#include <bitset>
#include <iostream>

using std::cout;
using std::endl;
using std::bitset;

int main(){
	unsigned char q = 0b01110001;
	// ~q = ~(00000000 00000000 00000000 01110001)
	// ~q = 11111111 11111111 11111111 10001110
	unsigned int not_q = ~q;
	cout << "[GUESSES]\t11111111111111111111111110001110" << endl;
	cout << "[ACTUAL]\t" << bitset<32>(not_q) << endl;
	return 0;
}
