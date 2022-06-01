// Exercise 3.22: Revise the loop that printed the first paragraph in text
// To instead change the elements in text that correspond to the first paragraph to all uppercase.
// After you’ve updated text, print its contents.

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
    vector<string> text = {"Revise the loop that printed the first paragraph in text ",
                           "to instead change the elements in text that correspond to ",
                           "the first paragraph to all uppercase. After you’ve updated ",
                           "text, print its contents.",
                           "",
                           "Dummy second paragraph"};

    for (auto string_itr = text.begin(); string_itr != text.end() && !string_itr->empty(); ++string_itr)
    {
        for (auto char_itr = string_itr->begin(); char_itr != string_itr->end(); ++char_itr)
        {
            *char_itr = toupper(*char_itr);
        }
    }

    for (auto itr = text.cbegin(); itr != text.cend() && !itr->empty(); ++itr)
    {
        cout << *itr << endl;
    }

    return 0;
}