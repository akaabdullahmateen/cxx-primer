# Exercise 2.26: Which of the following are legal? For those that are illegal, explain why?

```cpp
const int buf;
int cnt = 0;
const int sz = cnt;
++cnt;
++sz;
```

## `const int buf;`

**Validity:** Illegal

**Error:** uninitialized `const buf`

**Explanation:** `const` qualified objects must be initialized at the time of definition.

## `int cnt = 0;`

**Validity:** Legal

## `const int sz = cnt;`

**Validity:** Legal

## `++cnt;`

**Validity:** Legal

## `++sz;`

**Validity:** Illegal

**Error:** increment of read-only variable `sz`

**Explanation:** `const` qualified objects can not be assigned a new value, since doing so defeats their purpose.