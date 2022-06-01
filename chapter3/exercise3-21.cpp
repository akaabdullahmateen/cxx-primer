// Exercise 3.21: Redo the first exercise from § 3.3.3 (p. 105) using iterators

// Read a sequence of words from cin and store the values a vector.
// After you’ve read all the words, process the vector and change each word to uppercase.
// Print the transformed elements, eight words to a line.

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using s_iterator = string::iterator;
using cvs_iterator = vector<string>::const_iterator;
using size_type = string::size_type;

int main()
{
    string str;
    vector<string> vec;
    cout << ">> ";
    while (cin >> str)
    {
        vec.push_back(str);
        cout << ">> ";
    }
    cout << "\b\b\b   \b\b  \b \n";
    for (string &s : vec)
    {
        for (s_iterator itr = s.begin(); itr != s.end(); ++itr)
        {
            *itr = toupper(*itr);
        }
    }
    size_type counter = 0;
    for (cvs_iterator itr = vec.cbegin(); itr != vec.cend(); ++itr)
    {
        cout << *itr << " ";
        if (counter and !(counter % 8))
        {
            cout << endl;
        }
        ++counter;
    }
    cout << endl;

    return 0;
}