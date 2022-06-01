# Exercise 2.28: Explain the following definitions. Identify any that are illegal.

```cpp
int i, *const cp;
// error: uninitialized `const cp`
// plain `int` object
// top-level const-qualified pointer to `int`

int *p1, *const p2;
// error: uninitialized `const p2`
// pointer to `int`
// top-level const-qualified pointer to `int`

const int ic, &r = ic;
// error: uninitialized `const ic`
// const-qualified `int` object
// reference to `const int`

const int *const p3;
// error: unitialized `const p3`
// top-level const-qualified pointer to `const int`

const int *p;
// pointer to `const int`
```