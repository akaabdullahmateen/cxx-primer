# Exercise 3.18: Is the following program legal? If not, how might you fix it?

```cpp
vector<int> ivec;
ivec[0] = 42;
```

**Validity:** Illegal

**Explanation:** The declaration `vector<int> ivec` defines `ivec` as a vector with `int` type elements. Since, no initializer is provided, `ivec` is default-initialized - it is empty. The second statement tries to access and modify the value at position `0` in `ivec` using the subscript notation. Since, subscript operator does not perform any bound checking, the operation is executed, however, the result of using an out-of-range index is *undefined*. The subscript operator can only fetch *existing* elements, not append new ones.

**Correction:** Use the `vector` operation `push_back()`.

```cpp
vector<int> ivec;
ivec.push_back(42);
```