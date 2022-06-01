// Exercise 3.15: Repeat the previous program but read strings this time.

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str;
    vector<string> svec;

    cout << ">> ";

    while (getline(cin, str))
    {
        if (!str.empty())
        {
            svec.push_back(str);
        }
        cout << ">> ";
    }

    cout << "\b\b\b   \b\b \b \n";

    for (string s : svec)
    {
        cout << s << endl;
    }

    return 0;
}