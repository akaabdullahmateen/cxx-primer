// Exercise 3.32: Copy the array you defined in the previous exercise into another array.
// Rewrite your program to use vectors.

#include <iostream>
#include <cstddef>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    constexpr size_t size = 10;
    size_t pos = 0;
    int arr[size];
    int dup[size];
    vector<int> vec;
    for (int &i : arr)
    {
        i = pos++;
    }
    for (pos = 0; pos < size; ++pos)
    {
        dup[pos] = arr[pos];
    }
    for (int i : dup)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : arr)
    {
        vec.push_back(i);
    }
    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}