// Exercise 5.5: Using an if–else statement
// Write your own version of the program to generate the letter grade from a numeric grade.

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

    // A+		A 		A-		B+		B		B-
    // 4.0 		3.8 	3.6 	3.4 	3.2 	3.0
    //
    // C+		C		C		D+		D		D-		F
    // 2.8 		2.6 	2.4 	2.2 	2.0 	1.8 	<1.8

    // A: GPA >= 3.6	index: 0
    // B: GPA >= 3.0	index: 1
    // C: GPA >= 2.4	index: 2
    // D: GPA >= 1.8	index: 3

    // Filter GPA below 1.8 and assign it F grade
    double raw = 0.0;
    vector <string> ranges = {"A", "B", "C", "D", "F"};
    string grade;

    cout << ">> ";
    cin >> raw;

    if (raw > 4.0 || raw < 0.0) {
        cerr << "ERROR: INVALID INPUT" << endl;
        return -1;
    }

    unsigned int gpa = 41 - raw * 10;

    if (gpa > 23) {
        grade = ranges.at(ranges.size() - 1);
    } else {
        vector<string>::size_type index = (gpa) / 6;
        grade = ranges.at(index);
        if (gpa % 6 > 3) {
            grade += '-';
        } else if (gpa % 6 < 2) {
            grade += '+';
        }
    }

    cout << "[GRADE] " << grade << endl;

    return 0;
}