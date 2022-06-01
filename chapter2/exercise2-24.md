# Exercise 2.24: Why is the initialization of `p` legal but that of `lp` illegal?

```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```

The types of the pointer object and that of the object to which it shall point to, *must* match. Since, type mismatch occurs in the init-definition of the pointer `lp`, the compiler complains with error message: "cannot convert `int*` to `long int*` in initialization". However, void pointers - pointers of type `void` are allowed to point to objects of any type. This is possible because they only allow limited operations on pointers and none on the pointer value. Since there is no information of the address's pointed object's type, and type determines what operations are legal. The C++17 Standard specifies:

> If the resulting pointer is not correctly aligned for the referenced type, the behavior is undefined.
