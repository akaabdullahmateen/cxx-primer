# Overloaded functions

Functions that have the same name but different parameter lists and that appear in the same scope are overloaded. For example, we defined several functions named `print`:

```cpp
void print(const char *cp);
void print(const int *beg, const int *end);
void print(const int ia[10], size_t size);
```


These functions perform the same general action but apply to different parameter types. When we call these functions, the compiler can deduce which function we want based on the argument type we pass:

```cpp
int j[2] = {0, 1};
print("Hello, World");
print(j, end(j) - begin(j));
print(begin(j), end(j));
```

Function overloading eliminates the need to invent - and remember - the names that exist only to help the compiler figure out which function to call. The `main` function however, should not be overloaded.

## Defining overloaded functions

Consider a database application with several functions to find record based on name, phone number, account number, and so on. Function overloading lets us define a collection of functions each named `lookup`, that differ in terms of how they do the search. We can call `lookup` passing a value of any of several types:

```cpp
Record lookup(const Account&); // find by Account 
Record lookup(const Phone&);   // find by Phone 
Record lookup(const Name&);    // find by Name
Account acct;
Phone phone;
Record r1 = lookup(acct); 	// call version that takes an Account
Record r2 = lookup(phone); 	// call version that takes a Phone
```

Here all three functions have the same name, yet they are three distinct functions. The compiler uses the argument(s) type to figure out which one to call. Overloaded functions must differ in the number of type(s) of their parameters. Each of the above function takes a single parameter, but differ in parameter types.

It is an error for two functions to differ only in return type. If the parameter list of two functions match, but the return types differ, then the second declaration is an error:

```cpp
Record lookup(const Account&);
bool lookup(const Accoutn&);
```

## Determining whether two parameter types differ

Two parameter lists can be identical, even if they do not look the same:

```cpp
// each pair declares the same function
Record lookup(const Account &acct);
Record lookup(const Account&); // parameter names are ignored
typedef Phone Telno;
Record lookup(const Phone&);
Record lookup(const Telno&); // Telno and Phone are the same type
```

In the first pair, the first declaration names its parameter. Parameter names are only for documentation purposes. They do not change the parameter list. In the second pair, `Telno` is not a new type; it is synonym for `Phone`. A type alias provides an alternate name for an existing type; it does not create a new type. Therefore, two parameter list that differs only because one uses type alias and the other directly uses the type to which the alias corresponds do not differ.

## Overloading and `const` parameters

Top-level `const` has no effect on objects that can be passed to a function. A parameter that has a top-level `const` is indistinguishable from one without a top-level `const`:

```cpp
 Record lookup(Phone);
 Record lookup(const Phone);

 Record lookup(Phone *);
 Record lookup(Phone * const);
 ```

 In these declarations, the second declaration redeclares the same functions as the first. On the other hand, we can overload based on whether a parameter is a reference or pointer to the `const` or non-`const` version of a given type; such `const`s are low-level:

```cpp
Record lookup(Account&);
Record lookup(const Account&);

Record lookup(Account*);
Record lookup(const Account*);
```

In these cases the compiler can use the `const`ness of the argument to distinguish which function to call. Because there is no conversion from `const`, we can pass a `const` object (or a pointer to `const`) only to the version with a `const` parameter. Because there is a conversion to `const`, we can call either function on a non-`const` object or pointer to non-`const`. However, the compiler will prefer the non-`const` version when we pass non-`const` object or pointer to non-`const`.

## `const_cast` and overloading

`const_cast` are most useful in the context of overloading functions. As one example, recall our `shorterString` function:

```cpp
const string &shorterString(const string &s1, const string &s2){
	return s1.size() <= s2.size() ? s1 : s2;
}
```

Although overloading lets us avoid having to invent and remember names for common operations, we should only overload operations which actually do similar things. There are cases when providing different functions adds information that makes the program easier to understand. Consider a set of functions that move the cursor on screen:

```cpp
Screen &moveHome();
Screen &moveAbs(int, int);
Screen &moveRel(int, int, string direction);
```

It might seen at first that overloading this set of functions under the name `move` is the correct decision:

```cpp
Screen &move();
Screen &move(int, int);
Screen &move(int, int, string direction);
```

However, by overloading these functions, we have lost information that was inherent in the function names. Although cursor movement is a general operation shared by all these functions, the specific nature of that movement is unique to each of these functions. `moveHome`, for example, represents a special instance of cursor movement. Whether to overload or not, these functions, depends on which of these two calls is easier to understand:

```cpp
myScreen.moveHome(); // we think this one!
myScreen.move();
```

This function takes and returns references to `const string`. We can call this function on a pair of non-`const` string arguments, but we will get a reference to `const` string as a result. We might want to have a version of `shorterString` that, when given non-`const` arguments, would yield a plain reference. We can write this version of our program using `const_cast` explicit cast:

```cpp
string &shorterString(string &s1, string &s2){
	return const_cast<string &>(shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2)));
}
```

This version calls the `const` version of `shorterString` by casting its arguments to reference to `const`. That function returns a reference to `const` string, which we know is bound of one of our non-`const` string. Therefore, it is safe to cast it back to plain `string &` in `return` statement.

## Calling an overloaded function

Once we have defined a set of overloaded functions, we need to be able to call them with appropriate arguments. Function matching also known as function resolution, is the process by which a particular function call is associated with a specific function from a set of overloaded functions. The compiler determines which function to call by comparing the arguments in the call with the parameters offered by each function in the overload set.

In many, probably most, cases, it is straightforward for a programmer to determine whether a particular call is legal, and if so, which function is called. Often functions in the overload set differs in terms of the number of arguments, or the types of the arguments are unrelated. In such cases, it is easy to determine which function is called. Determining which function is called when the overloaded functions have the same number of parameters, and those parameters are related by conversions, can be less obvious. We will look at how compiler resolves calls involving conversions in section: Function Matching. For now, what's important to realize is that for any given call to an overloaded function, there are three possible outcomes:

- The compiler finds exactly one function that is a best match for the actual argument and generates code to call that function.
- There is no function with parameters that match the arguments in the call, in which case the compiler issues an error message that there was no match.
- There is more than one function that matches and none of those matches is clearly best. This case is also an error, it is an ambiguous call.