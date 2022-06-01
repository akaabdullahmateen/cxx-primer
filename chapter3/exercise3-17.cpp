// Exercise 3.17: Read a sequence of words from cin and store the values in a vector.
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

using s_vector = vector<string>;
using size_type = vector<string>::size_type;

void remove_last_prompt()
{
    cout << "\b\b\b   \b\b  \b \n";
}

void display_prompt()
{
    string prompt = ">> ";
    cout << prompt;
}

void add_newline()
{
    cout << endl;
}

bool is_multiple_of_eight(size_type n)
{
    bool remainder = n % 8;
    if (remainder)
        return false;
    return true;
}

int main()
{
    const string space = " ";
    string word;
    s_vector vec;
    size_type counter = 0;
    bool just_added_newline = false;

    display_prompt();
    while (cin >> word)
    {
        vec.push_back(word);
        display_prompt();
    }
    remove_last_prompt();

    for (string &s : vec)
    {
        for (char &c : s)
        {
            c = toupper(c);
        }
    }

    for (string s : vec)
    {
        cout << s << space;
        if (is_multiple_of_eight(counter) && counter != 0)
        {
            add_newline();
            just_added_newline = true;
        }
        else
            just_added_newline = false;
        ++counter;
    }

    if (!just_added_newline)
        add_newline();

    return 0;
}