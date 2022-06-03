# Exercise 4.15: The following assignment is illegal. Why? How would you correct it?

```cpp
double dval;
int ival;
int *pi;

dval = ival = pi = 0;
```

The multiple assignment statement can be broken down into individual assignments based on the fact that assignment is right associative:

```cpp
pi = 0; // pi is a pointer to int; thus, pi is now the null pointer
ival = pi; // error: pointer value cannot be converted to be assigned to an int
dval = ival; // this should be successful, provided the previous assignment did not fail
```

The compiler complains with the following error message:

```
error: invalid conversion from ‘int*’ to ‘int’
```

Since, there is no suitable conversion from `int*` to `int`, but there is conversion possibility from `int` to `double`; the pointer assignment `pi = 0` must be a separate assignment. The other variables can be assigned using mutliple assignment:

```cpp
pi = 0;
dval = ival = 0;
```
