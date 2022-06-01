// Exercise 3.8: Rewrite the program in the first exercise, first using a while and again using a traditional for loop.
// Which of the three approaches do you prefer and why?

#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
	string str1("some string");
	for(char& c : str1) c = 'X';
	cout << str1 << endl;
	cout << "-----------" << endl;

	string str2("some string");
	decltype(str2.size()) itr = 0;
	while(itr < str2.size()) str2[itr++] = 'X';
	cout << str2 << endl;
	cout << "-----------" << endl;

	string str3("some string");
	string::size_type begin = 0;
	string::size_type end = str3.size();
	for(; begin != end; ++begin){
		char &c = str3[begin];
		c = 'X';
	}
	cout << str3 << endl;

	return 0;
}

// I would prefer range-based for statements since they are:
// Appropriate (fits the purpose), 
// Concise (fewer keystrokes),
// Performative (they are optimized for this exact purpose).