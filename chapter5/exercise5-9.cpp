// Exercise 5.9: Write a program using a series of if statements to count the number of vowels in text read from cin.

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
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
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