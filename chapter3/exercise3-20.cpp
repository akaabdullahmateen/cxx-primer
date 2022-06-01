// Exercise 3.20: Read a set of integers into a vector.
// Print the sum of each pair of adjacent elements.
// Change your program so that it prints the sum of the first and last elements
// Followed by the sum of the second and second-to-last, and so on.

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

using size_type = vector<int>::size_type;

void print_adjacent_sum(vector<int> vec)
{
    cout << "[ADJACENT SUM]" << endl;

    if (vec.empty())
    {
        cout << "[EMPTY]" << endl;
        return;
    }

    if (vec.size() == 1)
    {
        cout << "[UNITY] " << vec.at(0) << endl;
        return;
    }

    for (size_type idx = 0; idx < vec.size() - 1; ++idx)
    {
        cout << "[SUM] " << vec.at(idx) + vec.at(idx + 1) << endl;
    }

    cout << endl;
}

void print_end_sum(vector<int> vec)
{
    cout << "[END SUM]" << endl;

    if (vec.empty())
    {
        cout << "[EMPTY]" << endl;
    }

    size_type right = vec.size() - 1;
    for (size_type left = 0; left <= right; ++left)
    {
        if (left == right)
        {
            cout << "[SUM] " << vec.at(left) << endl;
        }
        else
        {
            cout << "[SUM] " << vec.at(left) + vec.at(right) << endl;
            --right;
        }
    }
}

int main()
{
    int i = 0;
    vector<int> vec;

    cout << ">> ";
    while (cin >> i)
    {
        vec.push_back(i);
        cout << ">> ";
    }
    cout << "\b\b\b   \b\b  \b \n";

    print_adjacent_sum(vec);
    print_end_sum(vec);

    return 0;
}