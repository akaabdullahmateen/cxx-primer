// Exercise 5.6: Rewrite your grading program to use the conditional operator in place of the if–else statement.

#include <iostream>
#include <vector>

using std::vector;
using std::string;

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

int main() {
    double raw = 0.0;
    vector <string> ranges = {"A", "B", "C", "D", "F"};
    string grade;
    vector<string>::size_type index;

    cout << ">> ";
    cin >> raw;

    if (raw > 4.0 || raw < 0.0) {
        cerr << "ERROR: INVALID INPUT" << endl;
        return -1;
    }

    unsigned int gpa = 41 - raw * 10;

    grade = (gpa > 23) ? ranges.at(ranges.size() - 1) : (index = gpa / 6, ranges.at(index));

    if (gpa <= 23){
        if (gpa % 6 > 3) {
        grade += '-';
        } else if (gpa % 6 < 2) {
            grade += '+';
        }
    }
    
    cout << "[GRADE] " << grade << endl;

    return 0;
}