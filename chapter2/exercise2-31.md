# Exercise 2.31: Given the declarations in the previous exercise, determine whether the following assignments are legal. Explain how the top-level or low-level `const` applies in each case.

```cpp
r1 = v2;
// ok: since top-level const qualification is ignored when copying
p1 = p2;
// error: p1 does not have low-level const qualifier whereas p2 has low-level const qualifier
p1 = p3;
// error: p1 does not have low-level const qualifier whereas p3 has low-level const qualifier
p2 = p1;
// ok: `int*` can be promoted to `const int*`
p2 = p3;
// ok: both have low-level const qualifier
```
