# Exercise 6.19: Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.

```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
```

```cpp
calc(23.4, 55.1);
// Illegal; only one argument allowed but two are passed

count("abcda", ’a’);
// Legal; reference to const can initialize from string literal
// also, passing by value allows initialization from char literal

calc(66);
// Legal; int can be converted from double type

sum(vec.begin(), vec.end(), 3.8);
// Legal; double can be converted to int type (through truncation)
```