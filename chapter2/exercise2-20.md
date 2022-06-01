# Exercise 2.20: Explain what does the following program do?

```cpp
int i = 42;
int *pi = &i;
*pi = *pi * *pi;
```

## Statement #1: `int i = 42;`

A variable object of type `int` - `i` - is defined and initialized with decimal integer literal `42`.

## Statement #2: `int *pi = &i;`

A pointer object of type `int` - `pi` - is defined and initialized with the address of the integer object `i` using the address-of operator `&`.

## Statement #$: `*pi = *pi * pi;`

An lvalue - which is the object pointed to by the pointer `pi` : `i` - is assigned a new value. The new value is the result of the rvalue expression: `*pi * *pi`. This expression accesses the value that the pointer `*pi` points to, and multiplies it by itself. This expression evaluates to `42 * 42` which is equal to `1764`. Therefore, this statement assigns the integer variable `i` the new value `1764`.