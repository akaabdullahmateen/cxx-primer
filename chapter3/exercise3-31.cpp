// Exercise 3.31: Write a program to define an array of ten ints.
// Give each element the same value as its position in the array.

#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

int main()
{
    int arr[10];
    size_t pos = 0;
    for (int &i : arr)
    {
        i = pos++;
    }
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}