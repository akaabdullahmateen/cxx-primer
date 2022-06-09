// Exercise 6.37: Write three additional declarations for the function in the previous exercise
// One should use a type alias, one should use a trailing return, and the third should use decltype
// Which form do you prefer and why?

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

typedef string (&typedef_str_arr_ref)[10];
using using_str_arr_ref = string (&) [10];

string arr[10] = {"aeta", "beta", "ceta", "deta", "eeta", "feta", "geta", "heta", "ieta", "jeta"};

typedef_str_arr_ref dummy_func_one(){
	return arr;
}

using_str_arr_ref dummy_func_two(){
	return arr;
}

auto dummy_func_three() -> string (&)[10] {
	return arr;
}

decltype(arr) &dummy_func_four(){
	return arr;
}

int main(){
	string (&arr_one)[10] = dummy_func_one();
	for(const string &s : arr_one){
		cout << s << " ";
	}
	cout << endl;
	string (&arr_two)[10] = dummy_func_two();
	for(const string &s : arr_two){
		cout << s << " ";
	}
	cout << endl;
	string (&arr_three)[10] = dummy_func_three();
	for(const string &s : arr_three){
		cout << s << " ";
	}
	cout << endl;
	string (&arr_four)[10] = dummy_func_four();
	for(const string &s : arr_four){
		cout << s << " ";
	}
	cout << endl;
	return 0;
}

// Due to its less intimidating syntax, I prefer the trailing return form