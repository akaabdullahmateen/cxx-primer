// Exercise 6.45: Review the programs you’ve written for the earlier exercises
// and decide whether they should be defined as inline.
// If so, do so. If not, explain why they should not be inline.

#include <iostream>
#include <stdexcept>
#include <climits>
#include <limits>
#include <string>
#include <vector>
#include <initializer_list>

using std::size_t;
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::string;
using std::vector;
using std::initializer_list;
using std::numeric_limits;
using std::streamsize;
using std::domain_error;
using std::overflow_error;

typedef string (&typedef_str_arr_ref)[10];
using using_str_arr_ref = string (&) [10];

string arr[10] = {"aeta", "beta", "ceta", "deta", "eeta", "feta", "geta", "heta", "ieta", "jeta"};

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};


// cannot be defined as inline - as inline functions cannot contain loops
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

// inline specifier is used for small functions whose definition is to be written in header files
// the inline specifier prevents compiler / linker from complaining about multiple definitions
// this function is probably only called once, so it should not be inlined
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

// this function probably will be used many times and is really small
// it should be inlined
inline unsigned long long abs(long long n){
	return (n >= 0) ? n : -n;
}

// inline functions cannot contain static variables
size_t persistent_sequence(){
	static size_t n = 0;
	return n++;
}

// this function also will be used many times and is comparatively small
// so it should be inlined
inline bool swap(int * const a, int * const b){
	if(a == nullptr || b == nullptr){
		return false;
	}
	const int temp = *a;
	*a = *b;
	*b = temp;
	return true;
}

// should be inline, one-liner
inline void reset(int &i){
	i = 0;
}

// should be inline, one-liner
inline void reset(long int &i){
	i = 0L;
}

// should be inline, one-liner
inline void reset(long long int &i){
	i = 0LL;
}

// small function that will be called frequently - should be inlined
inline void swap(int &a, int &b){
	const int temp = a;
	a = b;
	b = temp;
}

// inline functions cannot contain loops
bool has_any_uppercase(const string &s){
	for(const char c : s){
		if(isupper(c)){
			return true;
		}
	}
	return false;
}

// inline functions cannot contain loops
void to_all_lowercase(string &s){
	for(char &c : s){
		c = tolower(c);
	}
}

// inline because one-liner
inline int find_max(const int i, const int * const p){	
	return (i >= *p) ? i : *p;
}

// inline because small
inline void swap(const int *&p1, const int *&p2){
	const int * const temp = p1;
	p1 = p2;
	p2 = temp;
}

// inline functions cannot contain loops
void print(const char *cp){
	cout << "(1) print(const char *cp)" << endl;
	if(cp){
		while(*cp){
			cout << *cp++ << " ";
		}
	}
	cout << endl;
}

// inline functions cannot contain loops
void print(const int *begin, const int *end){
	cout << "(2) print(const int *begin, const int *end)" << endl;
	while(begin != end){
		cout << *begin++ << " ";
	}
	cout << endl;
}

// inline functions cannot contain loops
void print(const int ia[], size_t size){
	cout << "(3) print(const int ia[], size_t size)" << endl;
	for(size_t i = 0; i != size; ++i){
		cout << ia[i] << " ";
	}
	cout << endl;
}

// inline functions cannot contain loops
void print(const int (&arr)[2]){
	cout << "(4) print(const int (&arr)[2])" << endl;
	for(const int i : arr){
		cout << i << " ";
	}
	cout << endl;
}

// inline functions cannot contain loops
void print(const int (*inner_arr)[2], int rowsize){
	cout << "(5) print(const int(*inner_arr)[2], size_t rowsize)" << endl;
	for(int i = 0; i != rowsize; ++i){
		print(begin(*inner_arr), end(*inner_arr));
		++inner_arr;
	}
}

// inline functions cannot contain loops
void print(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << *ia++ << endl;
}

// inline functions cannot contain loops
int sum(initializer_list<int> li){
	int sum = 0;
	for(const int i : li){
		sum += i;
	}
	return sum;
}

// inline functions cannot contain loops
bool str_subrange(const string &str1, const string &str2){
	if (str1.size() == str2.size())
		return str1 == str2;
	
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	
	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}

// inline because one-liner
inline int &get(int *arry, int index){
	// return the element at that index
	// this assumes that the index is valid
	return arry[index];
}

// inline functions cannot be recursive
void print(vector<int> &v, vector<int>::size_type i){
	if(i){
		print(v, i - 1);
	}
	cout << v.at(i) << " ";
}

// inline because one-liner
inline string (&dummy_func())[10]{
	return arr;
}

// inline because one-liner
inline typedef_str_arr_ref dummy_func_one(){
	return arr;
}

// inline because one-liner
inline using_str_arr_ref dummy_func_two(){
	return arr;
}

// inline because one-liner
inline auto dummy_func_three() -> string (&)[10] {
	return arr;
}

// inline because one-liner
inline decltype(arr) &dummy_func_four(){
	return arr;
}

// inline because one-liner
inline decltype(odd) &arrPtr(int i){
	return (i % 2) ? odd : even;
}

// inline because one-liner
inline string make_plural(const string &word, const string &ending = "s"){
	return word + ending;
}

// inline because one-liner
inline bool isShorter(const string &s1, const string &s2){
	return s1.size() < s2.size();
}

// cannot declare main to be inline
int main(){
	return 0;
}