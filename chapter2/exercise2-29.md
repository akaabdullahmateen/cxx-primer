# Exercise 2.29: Using the variables in the previous exercise, which of the following assignments are legal? Explain why.

```cpp
i = ic;
// ok: lvalue of type `int` is assigned rvalue of type `const int`
p1 = p3;
// error: invalid conversion from `const int*` to `int*`
p1 = &ic;
// error: invalid conversion from `const int*` to `int*`
p3 = &ic;
// error: assignment of read-only variable `p3`
p2 = p1;
// error: assignment of read-only variable `p2`
ic = *p3;
// error: assignment of read-only variable `ic`
```