// Exercise 6.24: Explain the behavior of the following function
// If there are problems in the code, explain what they are and how you might fix them

#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;
using std::size_t;

void print(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << *ia++ << endl;
}

int main(){
	const int ia[10] = {0,1,2,3,4,5,6,7,8,9};
	print(ia);
	return 0;
}

// arrays cannot be passed as values, they are decayed to pointers
// therefore, const int ia[10] parameter is basically equivalent to const int *ia
// since pointers cannot be subscripted, ia[i] does not work