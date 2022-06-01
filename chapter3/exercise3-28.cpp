// Exercise 3.28: What are the values in the following arrays?

#include <string>

using std::string;

// Defined outside a function => value-initialized
// 10 empty strings
string sa[10];

// Defined outside a function => value-initiailized
// 10 zero-valued integers
int ia[10];

int main()
{
    // Defined inside a function => default-initialized
    // 10 undefined strings
    string sa2[10];

    // Defined inside a function => default-initialized
    // 10 undefined integers
    int ia2[10];

    return 0;
}