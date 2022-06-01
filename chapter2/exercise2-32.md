# Exercise 2.32: Is the following code legal or not? If not, how might you make it legal?

```cpp
int null = 0, *p = null;
```

## Is it legal?

No, the init-defintions tries to initialize the pointer `p` with value from integer `null` as a memory address - which is illegal. GNU C Compiler v11.2.0 complains:

> error: invalid conversion from `int` to `int*`

## Null pointer

```cpp
int null = 0, *p = nullptr;
```

## Address-of `null`

```cpp
int null = 0, *p = &null;
```