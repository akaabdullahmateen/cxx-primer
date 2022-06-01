# Exercise 2.30: For each of the following declarations indicate whether the object being declared has top-level or low-level `const`.

```cpp
const int v2 = 0;
// v2: top-level
int v1 = v2;
// v1: none
int *p1 = &v1, &r1 = v1;
// p1: none
// r1: none
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
// p2: low-level
// p3: both
// r2: low-level
```