# Features for specialized uses

In this section, we will cover three function-related features that are useful in many but not all programs: default arguments, inline, and `constexpr` function, and some facilities that are often used in debugging.

## Default arguments

Some functions have parameters that are given a particular value in most, but not all, calls. In such cases, we can declare that common value as default argument for the function. Functions with default arguments can be called with or without this argument. For example, we might use a `string` to represent the contents of a window. By default, we might want the window to have a particular height, width, and background character. However, we might also want to allow the users to pass values other than the defaults. To accomodate both default and specified values, we would declare our function to define the window as follows:

```cpp
typedef string::size_type sz;
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
```

Here we have provided a default for each parameter. A default argument is specified as an initializer for a parameter in the parameter list. We may define defaults for one or more parameters. However, if a parameter has a default argument, all the parameters that follows it must also have default arguments.
