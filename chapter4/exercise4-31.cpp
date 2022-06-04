// Exercise 4.31: The program in this section used the prefix increment and decrement operators.
// Explain why we used prefix and not postfix.
// What changes would have to be made to use the postfix versions?
// Rewrite the program using postfix operators.

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

using size_type = vector<int>::size_type;
int main(){
	vector<int> ivec(10);
	size_type cnt = ivec.size();

	for(size_type ix = 0; ix != ivec.size(); ix++, cnt--){
		ivec[ix] = cnt;
	}

	for(int &i : ivec){
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}

// Postfix operators needs to return a copy of the unmodified value, therefore, they have slightly slower than prefix versions.
// Just replacing prefix with postfix versions should work, because the post-execution expression in the for loop does not need to return anything
// If something was assigned in the post-execution expression of the for loop, the pre-decremented value of cnt will be returned