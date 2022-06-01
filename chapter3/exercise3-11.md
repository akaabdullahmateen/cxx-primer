# Is the following range `for` legal? If so, what is the type of `c`?

```cpp
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
```

**Validity:** Legal

**Explanation:** The for-range-declaration `auto &c` in the range-based `for` statement, has declarator modifier `&` - to declare `c` as a reference bound to each character in the `const`-qualified string `s`. Because string `s` has top-level `const`; each character in it are `const`. As a result, the type induced by `auto` for each `c` is `const char` - as low-level `const` are always qualified for type deductions from `auto`. This means that no assignment shall be done to read-only objects referenced by `c`. Otherwise, the compiler complains with the following error message:

```bash
error: assignment of read-only reference "c"
```

**Type:** `const char`