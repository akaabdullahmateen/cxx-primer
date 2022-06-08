# Exercise 6.15: Explain the rationale for the type of each of `find_char`’s parameters

**In particular, why is `s` a reference to `const` but `occurs` is a plain reference? Why are these parameters references, but the `char` parameter `c` is not? What would happen if we made `s` a plain reference? What if we made `occurs` a reference to `const`?**

```cpp
string::size_type find_char(const string &s, char c, string::size_type &occurs);
```

## Why is `s` a reference to `const`, but `occurs` is a plain reference?

The string on which the function `find_char` will operate might be large. Passing by value causes compiler to generate copy of the argument, but because this string might be large, this can be signicantly slow. Thus, we pass by reference, so that instead of copying, the code can simply operate on the same underlying string.

Functions can be overloaded in C++, however, because top-level `const` qualification is ignored when initializing parameters from arguments; function with `const`-qualified parameter, and another function without `const`-qualified parameter will contradict. Call to the function name will be ambiguous. Therefore, we have to choose one of `const` or non-`const`. Choosing `const` is suitable because the code does not change the passed string. Also, reference to `const` can initialize from literals as well as expressions and support type conversion - something that non-`const` references does not.

The counter parameter `occurs` however needs to be modified in the function. Therefore, it should not be `const` qualified. Moreover, `occurs` is used to pass the information about how many times the character `c` occured in the passed string, back to the calling function. Therefore, it needs to be a reference, so that its modified value is reflected in the local variable of calling function. 

## Why are these parameters references, but the `char` parameter `c` is not?

Character `c` however, only needs to be pass its value; it is not used to communicate back information to the calling function. Also, passing by reference for primitive types like `char` is less efficient than passing them by value, therefore, `c` is not a reference.

## What would happen if we made `s` a plain reference?

If string `s` is declared as plain reference, literals and expressions cannot be used as arguments for `find_char` function. But they are far too convenient to be ignored. `const` qualification resolves this problem. Also, this gives the called function `find_char` access to modification of the string `s`, something that is not desired. Moreoever, `const`-qualified strings cannot be passed to such a function, because, compiler will not promote non-`const` to `const`.

## What if we made `occurs` a reference to `const`?

If `occurs` is declared as reference to `const`, then it cannot be used to modify the underlying object. But the very purpose of this parameter is to update its value and communicate this information back to the calling function.