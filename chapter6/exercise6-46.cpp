// Exercise 6.46: Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


// we cannot do define isShorter as constexpr because, return and parameter types must be literal types
// and we are calling non-constexpr function s1.size()
inline bool isShorter(const string &s1, const string &s2){
	return s1.size() < s2.size();
}

int main(){
	cout << isShorter("alpha", "beta") << endl;
	return 0;
}