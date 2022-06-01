// Exercise 3.30: Identify the indexing errors in the following code:

#include <cstddef>

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    // Tries to access out-of-range element: ia[array_size] => ia[10]
    // When maximum addressable index is 9
    // Compiler will complain with error: stack smashing detected
    for (size_t ix = 1; ix <= array_size; ++ix)
        ia[ix] = ix;
    return 0;
}