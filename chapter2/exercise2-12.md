# Exercise 2.12: Which, if any, of the following names are invalid?

```cpp
int double = 3.14;
int _;
int catch-22;
int 1_or_2 = 1;
double Double = 3.14;
```

## a) `int double = 3.14;`

**Validity:** Illegal

**Error:** expected unqualified-id before '-' token

**Reason:** `double` is a reserved keyword and may not be used as a user-defined identifier.

## b) `int _;`

**Validity:** Legal

**Reason:** Identifiers must start with a nondigit - which includes all Latin uppercase and lowercase letters, and underscore. Also, C++ standard does not specify any constraints on identifier size. Moreover, identifier names beginning with underscore are reserved by implementation for any use in the global namespace, so provided, the above definition was done inside a function, it is perfectly valid, though, not recommended.

## c) `int catch-22;`

**Validity:** Illegal

**Error:** expected unqualified-id before 'catch'

**Reason:** Minus symbol is not a valid character to be used in an identifier name.

## d) `int 1_or_2 = 1;`

**Validity:** Illegal

**Error:** expected unqualified-id before numeric constant

**Reason:** Identifier names must start with a nondigit, that can be either lowercase or uppercase Latin letters, or underscore.

## e) `double Double = 3.14;`

**Validity:** Legal

**Reason:** C++ identifier names are case-sensitive. Therefore, although, `double` is a reserved keyword, `Double` is not, and allowed. However, as a convention, variable names for objects that are not of class type, should not begin with a uppercase Latin letter.