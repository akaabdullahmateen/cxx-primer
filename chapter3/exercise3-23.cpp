// Exercise 3.23: Write a program to create a vector with ten int elements.
// Using an iterator, assign each element a value that is twice its current value.
// Test your program by printing the vector.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec;

    for (int i = 0; i != 10; ++i)
    {
        vec.push_back(i);
    }

    for (auto itr = vec.begin(); itr != vec.end(); ++itr)
    {
        int &i = *itr;
        i *= 2;
    }

    for (auto i : vec)
    {
        cout << i << endl;
    }

    return 0;
}