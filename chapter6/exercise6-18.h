// Exercise 6.18: Write declarations for each of the following functions
// When you write these declarations, use the name of the function to indicate what the function does

#ifndef EXERCISE6_18_H
#define EXERCISE6_18_H

#include "matrix.h"
#include <vector>

// A function named compare that returns a bool and has two parameters
// That are references to a class named matrix.

bool compare(matrix &m1, matrix &m2);

// A function named change_val that returns a vector<int> iterator and takes two parameters
// One is an int and the other is an iterator for a vector<int>.

std::vector<int>::iterator change_val(int n, std::vector<int>::iterator itr);

#endif