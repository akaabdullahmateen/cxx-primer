# Which if any of the following `vector` definitions are in error?

**For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal?**

```cpp
vector<vector<int>> ivec;
vector<string> svec = ivec;
vector<string> svec(10, "null");
```

## a) `vector<vector<int>> ivec;`

**Validity:** Legal

**Explanation:** Creates a `vector` named `ivec` of `vector` objects, which itself have `int` objects. Since, no initializer is provided, `ivec` is default initialized, i.e., it is empty - no elements.

## b) `vector<string> svec = ivec;`

**Validity:** Illegal

**Explanation:** The init-definition of `svec` tries to declare it as of `vector` type made up of `string` objects. And, tries to copy-initialize it with `ivec` as initializer. However, the underlying structure of `ivec` which is `vector<int>` is not convertible to the declared structure of `svec` - `string`. As a result, the compiler complains with the error message:

```
error: conversion from ‘vector<std::vector<int>>’ to non-scalar type ‘vector<std::__cxx11::basic_string<char>>’ requested
```

## c) `vector<string> svec(10, "null");`

**Validity:** Legal

**Explanation:** Declares `svec` as `vector` of `string` objects, and constructs it with `10` strings of value `"null"`.
