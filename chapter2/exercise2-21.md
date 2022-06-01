# Exercise 2.21: Explain each of the following definitions. Indicate whether any are illegal and, if so, why.

```cpp
int i = 0;

double* dp = &i;
int *ip = i;
int *p = &i;
```

## `double* dp = &i;`

**Validity:** Illegal

**Error:** cannot convert "int*" to "double*" in initialization

**Explanation:** This statement defines a pointer object of type `double` with identifier name `dp` and initialize it to the address of the integer variable `i` using the address-of operator `&`. However, the types of the pointer and the object to which it points to must match, as the operations done on this pointed object can be done through the deference operator on pointer itself - but if the type is mismatched, illegal or unsupported operations can be deemed valid. Therefore, this init-definition fails.

## `int *ip = i;`

**Validity:** Illegal

**Error:** invalid conversion from "int" to "int*"

**Explanation:** This statement defines a pointer object `ip` of type `int` and tries to initialize it with the value of the integer variable `i`. However, this initialization is not allowed since a pointer can only contain a valid address or null value. The value stored in a pointer objects can be in either one of the following four states: 
 - It can point to an object
 - It can point to the location just immediately past the end of an object
 - It can be null pointer, indicating that is not bound to any object
 - It can be invalid; values other than the preceding three are invalid

## `int *p = &i;`

**Validity:** Legal

**Action:** `p` contains the address of the integer object `i`

**Explanation:** This statement defines a pointer object of type `int` with identifier name `p` and initializes it to the address of the integer variable `i` using the address-of operator `&`. Since, the types of the pointer and the variable objects match, and the address of an object is a valid value to be stored inside a pointer, this init-declaration is successful.