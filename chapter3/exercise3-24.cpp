// Exercise 3.24: Redo the last exercise from § 3.3.3 (p. 105) using iterators.

// Read a set of integers into a vector.
// Print the sum of each pair of adjacent elements.
// Change your program so that it prints the sum of the first and last elements
// Followed by the sum of the second and second-to-last, and so on.

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using cvi_iterator = vector<int>::const_iterator;

int main()
{
    int n = 0;
    vector<int> vec;
    cout << ">> ";
    while (cin >> n)
    {
        vec.push_back(n);
        cout << ">> ";
    }
    cout << "\b\b\b   \b\b  \b \n";
    cout << "[ADJACENT SUM]" << endl;
    if (vec.empty())
    {
        cout << "[EMPTY]" << endl;
    }
    else if (vec.size() == 1)
    {
        cout << "[UNITY] " << vec.at(0) << endl;
    }
    else
        for (cvi_iterator itr = vec.cbegin(); itr != vec.cend() - 1;)
        {
            cout << "[SUM] " << *itr + *(++itr) << endl;
        }
    cout << endl;
    cout << "[END SUM]" << endl;
    if (vec.empty())
    {
        cout << "[EMPTY]" << endl;
    }
    cvi_iterator right = vec.cend() - 1;
    for (cvi_iterator left = vec.cbegin(); left <= right; ++left)
    {
        if (left == right)
        {
            cout << "[SUM] " << *left << endl;
        }
        else
        {
            cout << "[SUM] " << *left + *right << endl;
            --right;
        }
    }

    return 0;
}