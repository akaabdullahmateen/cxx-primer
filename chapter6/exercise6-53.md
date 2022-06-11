# Exercise 6.53: Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

```cpp
int calc(int&, int&);
int calc(const int&, const int&);
// Low-level const-qualifaction is not ignored
// therefore, call with arguments which are references to const, will be matched with the second function in this overload set
// whereas, call with arguments which are plain references would require const conversion, thus, the first function will be an exact match

int calc(char*, char*);
int calc(const char*, const char*);
// Again, low-level const-qualification is not ignored
// thus, call with arguments that are pointers to const will be matched with second function
// whereas, plain pointers will be matched with the first function

int calc(char*, char*);
int calc(char* const, char* const);
// Top-level const-qualification is however, discarded when initializing parameters from arguments
// An exact match occurs by discarding or adding const-qualification
// Therefore, both of these functions are equivalent. Hence, the second function is redeclaration of the first one
// The second declaration is thus in error.
```