// Exercise 3.16: Write a program to print the size and contents of the vectors from exercise 3.13.
// Check whether your answers to that exercise were correct.
// If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using i_size_type = vector<int>::size_type;
using s_size_type = vector<string>::size_type;

void depict(vector<int> v, i_size_type g_size, string value_msg)
{
    i_size_type counter = 0;

    cout << "(size) [GUESSED] " << g_size << " | [ACTUAL] " << v.size() << endl;
    cout << "(value) [GUESSED] \"" << value_msg << "\"" << endl;
    cout << "[START_ACTUAL]\n";

    if (!v.empty())
    {
        for (int i : v)
        {
            cout << "[" << counter++ << "] " << i << endl;
        }
    }
    else
    {
        cout << "[EMPTY]" << endl;
    }

    cout << "[END_ACTUAL]\n";
}

void depict_string(vector<string> v, i_size_type g_size, string value_msg)
{
    i_size_type counter = 0;

    cout << "(size) [GUESSED] " << g_size << " | [ACTUAL] " << v.size() << endl;
    cout << "(value) [GUESSED] \"" << value_msg << "\"" << endl;
    cout << "[START_ACTUAL]\n";

    if (!v.empty())
    {
        for (string s : v)
        {
            if (s.empty())
                s = "[EMPTY]";
            cout << "[" << counter++ << "] " << s << endl;
        }
    }
    else
    {
        cout << "[EMPTY]" << endl;
    }

    cout << "[END_ACTUAL]\n";
}

int main()
{
    i_size_type size = 0;
    s_size_type s_size = 0;
    string msg;

    vector<int> v1;
    size = 0;
    msg = "empty vector - no element";
    depict(v1, size, msg);

    vector<int> v2(10);
    size = 10;
    msg = "each element has value: 0";
    depict(v2, size, msg);

    vector<int> v3(10, 42);
    size = 10;
    msg = "each element has value: 42";
    depict(v3, size, msg);

    vector<int> v4{10};
    size = 1;
    msg = "first (and only) element has value: 10";
    depict(v4, size, msg);

    vector<int> v5{10, 42};
    size = 2;
    msg = "first has value: 10; second has value: 42";
    depict(v5, size, msg);

    vector<string> v6{10};
    s_size = 10;
    msg = "each element has value: \"\" - empty string";
    depict_string(v6, s_size, msg);

    vector<string> v7{10, "hi"};
    s_size = 10;
    msg = "each element has value: \"hi\"";
    depict_string(v7, s_size, msg);

    return 0;
}