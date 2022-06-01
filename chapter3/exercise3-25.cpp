// Exercise 3.25 : Rewrite the grade clustering program from § 3.3.3(p.104) using iterators instead of subscripts.

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    unsigned idx;
    vector<unsigned>::iterator itr;
    while (cin >> grade)
    {
        if (grade <= 100)
        {
            itr = scores.begin() + (grade / 10);
            *itr = *itr + 1;
        }
    }
    for (auto it = scores.cbegin(); it != scores.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}