# Overloading and scope

Ordinarilly, it is a bad idea to declare a function locally. However, to explain how scope interacts with overloading, we will violate this practice and use local function declarations.

Programmers new to C++ are often confused about the interaction between scope and overloading. However, overloading has no special properties with respect to scope: As usual, if we declare a name in an inner scope, that name hides uses of that name declared in an outer scope. Names do not overload across scopes:

```cpp
string read();					//
void print(const string &);		// 
void print(double);				// overloads print function 
void foobar(int val){			// 
	bool read = false;			// new scope; hides outer declaration of read
	string s = read();			// error: read is a bool variable, not a function
	// bad practice: usually, its a bad idea to declare functions at local scope
	void print(int);			// new scope; hides previous instances of print
	print("Value: ");			// error: print(const string &) is hidden
	print(ival);				// ok: print(int) is visible
	print(3.14);				// ok: calls print(int); print(double) is hidden
}
```

Most readers will not be surprised that the call to `read` is in error. When the compiler processes the call to read, it finds the local declaration of `read`. That name is a `bool` variable, and we cannot call a `bool`. Hence, the call is illegal. Exactly the same process is used to resolve the calls to `print`. The declarations of `print(const string &)` and `print(double)` are hidden by the declaration of `print(int)`. It is as if there is only one `print` function available: the one that takes a single `int` parameter.

When we call `print`, the compiler first looks for a declaration of that name. It finds the local declaration for `print` that takes an `int`. Once a name is found, the compiler ignores uses of that name in any outer scope. Instead, the compiler assumes that the declaration found is the one for the name we are using. What remains is to see if the use of that name is valid. In C++, name lookup happens before type checking.

The first call passes a string literal, but the only declaration for `print` that is in scope, has a parameter that is an `int`. A string literal cannot converted to an object of type `int`, so this is an error. This `print(const string&)` function, which would otherwise have matched this call, is hidden and is not considered.

When we call `print` passing a `double`, the process is repeated. The compiler finds the local defintion of `print(int)`. The `double` argument is converted to type `int`, so the call is legal.

Had we declared `print(int)` in the same scope as the other `print` functions, then it would be another overloaded version of `print`. In that case, these calls would be resolved differently, because the compiler will see all three functions:

```cpp
string read();					//
void print(const string &);		// 
void print(double);				// overloads print function 
void print(int);				// overloads print function
void foobar(int val){			// 
	bool read = false;			// new scope; hides outer declaration of read
	string s = read();			// error: read is a bool variable, not a function
	print("Value: ");			// ok: matches with print(const string &)
	print(ival);				// ok: matches with print(int)
	print(3.14);				// ok: matches with print(double)
}
```