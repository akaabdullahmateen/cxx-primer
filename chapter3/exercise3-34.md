# Exercise 3.34: Given that `p1` and `p2` point to elements in the same array, what does the following code do?

**Are there values of `p1` or `p2` that make this code illegal?**

```cpp
p1 += p2 - p1;
```

The lvalue expression evaluates the difference between the two pointers (`p1` and `p2`). The difference evaluated has type `ptrdiff_t` defined in the `cstddef` header. Since, `p1` and `p2` are pointers to elements in the same array, the difference can be added to `p1`. The pointer `p1` then points to the same element as the one pointed to by `p2`.

This compound assignment would make `p1` invalid, if either of the pointers do not point to elements in the same array or object. The assignment would be meaningless yet again, if either of the pointers were null pointers - which allow only integral value of zero to be added or subtracted, resulting in null pointers.