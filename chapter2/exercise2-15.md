# Exercise 2.15: Which of the following definitions, if any, are invalid? Why?

```cpp
int ival = 1.01;
int &rval1 = 1.01;
int &rval2 = ival;
int &rval3;
```

## a) `int ival = 1.01;`

**Validity:** Legal

**Value:** `1`

**Explanation:** Identifier `ival` is being defined with built-in type `int`, and initialized to double-precision floating-point literal `1.01`. Due to type promotion, the fractional part is truncated, and `ival` is initialized to `1`.

## b) `int &rval1 = 1.01;`

**Validity:** Illegal

**Error:** cannot bind non-const lvalue reference of type ‘int&’ to a value of type ‘double’

**Explanation:** Because, the identifier `rval1` has an ampersand symbol `&` appended before it, it is being defined as a reference. But refernces are bound to only objects and not literals, so the statement is illegal.

## c) `int &rval2 = ival;`

**Validity:** Legal

**Value:** `1` (same value as that of `ival`)

**Explanation:** L-value reference `rval2` is being bound to the object `ival`. Since, the types of both the object to which the reference is being bound to, and of the reference itself, matches exactly, the definition is successful.

## d) `int &rval3;`

**Validity:** Illegal

**Error:** ‘rval3’ declared as reference but not initialized

**Explanation:** References must be initialized at the time of their definition; since, there is no way to assign them (bind them) to a different object after they are defined.