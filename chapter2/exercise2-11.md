# Exercise 2.11: Explain whether each of the following is a declaration or a definiton:

```cpp
extern int ix = 1024;
int iy;
extern int iz;
```

## a) `extern int ix = 1024;`

**Kind:** Definition

**Explanation:** Any declaration that includes an explicit initializer is a defintion. Providing an initializer on a variable defined as `extern` overrides the `extern`. Therefore, an `extern` that has an initializer is a defintion.

## b) `int iy;`

**Kind:** Definition

**Explanation:** Any variable declared without the `extern` keyword with a type and idenitifer, is a definition.

## c) `extern int iz;`

**Kind:** Declaration

**Explanation:** Expressions of the form: "[extern] [type] [identifier]" without an initializor, are valid declarations, that lets program know about the definition of variable - defined somewhere else - without created a duplicate associated entry into the memory.