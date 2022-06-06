// Exercise 5.12: Modify our vowel-counting program so that
// It counts the number of occurrences of the following two-character sequences: ff, fl, and fi.

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
	bool is_last_newline = false;
	string text;
	char last = 0;
	vector<char> cache;
	vector<char>::size_type line_count = 0;
	string::size_type vowel_count = 0;
	string::size_type space_count = 0;
	string::size_type special_count = 0;
	cout << ">> ";
	while(getline(cin, text)){
		for(const char &c : text){
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
				cache.push_back(c);
				++vowel_count;
			}
			else if(isspace(c)){
				++space_count;
			}
			if(last == 'f'){
				if(c == 'f' || c == 'l' || c == 'i'){
					++special_count;
				}
			}
			last = c;
		}
		cout << ">> ";
	}
	cout << "\b\b\b   \b\b  \b \n";
	cout << "[VOWELS DETECTED] : " << endl;
	for(const char &c : cache){
		if(line_count && !(line_count % 8)){
			cout << endl;
			is_last_newline = true;
		}
		else{
			is_last_newline = false;
		}
		cout << c << " ";
		++line_count;
	}
	if(!is_last_newline){
		cout << endl;
	}
	cout << endl;
	cout << "[VOWEL COUNT] : " << vowel_count << endl;
	cout << "[SPACE COUNT] : " << space_count << endl;
	cout << "[SPECIAL COUNT] : " << special_count << endl;
	return 0;
}