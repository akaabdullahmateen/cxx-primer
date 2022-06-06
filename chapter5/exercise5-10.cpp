// Exercise 5.10: There is one problem with our vowel-counting program as we’ve implemented it
// It doesn’t count capital letters as vowels
// Write a program that counts both lower and uppercase letters as the appropriate vowel
// That is, your program should count both ’a’ and ’A’ as part of aCnt, and so forth.

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
	string text;
	vector<char> cache;
	vector<char>::size_type line_count = 0;
	string::size_type vowelCount = 0;
	cout << ">> ";
	while(getline(cin, text)){
		for(const char &c : text){
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
				cache.push_back(c);
				++vowelCount;
			}
		}
		cout << ">> ";
	}
	cout << "\b\b\b   \b\b  \b \n";
	cout << "[DETECTED] : " << endl;
	for(const char &c : cache){
		if(line_count && !(line_count % 8)){
			cout << endl;
		}
		cout << c << " ";
		++line_count;
	}
	cout << endl;
	cout << "[VOWEL COUNT] : " << vowelCount << endl;
	return 0;
}