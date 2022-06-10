# Exercise 6.39: Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

## Pair a)

```cpp
int calc(int, int);
int calc(const int, const int);
```

Illegal. Top-level `const`-qualification is ignored when passing arguments to functions. Therefore, these both functions will result in ambiguous calls. The second function redeclares the first one, and thus in error.

## Pair b)

```cpp
int get();
double get();
```

Illegal. Function calls that differ only in return type are not overloaded because they are not differnt. The second declaration of `get` redeclares the first one.

## Pair c)

```cpp
int *reset(int *);
double *reset(double *);
```

Legal. Both function declarations are overloading the function name `reset`. They both differ in the type of parameters, and although there is conversion between those types, calls to these functions will result in a best match being found, and thus, these are not ambiguouus calls.
