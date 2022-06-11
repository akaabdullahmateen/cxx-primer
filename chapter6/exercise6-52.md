# Exercise 6.52: Given the following declarations, what is the rank (§ 6.6.1, p. 245) of each conversion in the following calls?

```cpp
void manip(int, int);
double dobj;
```

```cpp
manip(’a’, ’z’);
manip(55.4, dobj);
```

## Ranking for finding best match

- Exact match - including arrays and functions converted to pointers, and top-level `const`-qualification being ignored
- `const`-qualification promotion from non-`const` to `const`.
- Integral promotion
- Arithmetic and pointer conversions
- Class type conversion

`manip` requires two arguments both of type `int`. In the first call, the arguments are both of type `char` literal. These `char` literals are promoted to `int` types. Therefore, this call's best match has rank 3 as integral promotion.

The second call provides a `double` literal and a `double` object as arguments. Both of these arguments require arithmetic conversion to `int`, therefore, this call ranks 4 as arithmetic conversion.