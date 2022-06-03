// Exercise 4.22: Extend the program that assigned high pass, pass, and fail grades
// To also assign low pass for grades between 60 and 75 inclusive.
// Write two versions: One version that uses only conditional operators;
// The other should use one or more if statements.
// Which version do you think is easier to understand and why?

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	// grades		final_grade
	// ------------|---------
	// 0 - 59 		fail
	// 60 - 75 		low pass
	// 76 - 90 		pass
	// 90 - ++		high pass
	
	unsigned short grade = 0;
	cout << ">> ";
	cin >> grade;
	string final_grade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade < 60) ? "fail" : "low pass"; 
	cout << "[CONDITIONAL VERDICT] " << final_grade << endl;
	if(grade > 90) final_grade = "high pass";
	else if(grade > 75) final_grade = "pass";
	else if(grade < 60) final_grade = "fail";
	else final_grade = "low pass";
	cout << "[IF VERDICT] " << final_grade << endl;
	return 0;
}

// if statements are considerably easier to read and understand, because they are less crpytic
