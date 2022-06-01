// Exercise 3.14: Write a program to read a sequence of ints from cin and store those values in a vector

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int in = 0;
    vector<int> vec;

    cout << ">> ";
    while (cin >> in)
    {
        vec.push_back(in);
        cout << ">> ";
    }

    cout << "\b\b\b   \b\b  \b \n";

    unsigned counter = 0;

    for (int i : vec)
    {
        cout << "[" << counter++ << "] " << i << endl;
    }

    return 0;
}