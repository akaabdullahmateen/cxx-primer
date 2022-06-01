# Exercise 2.9: Explain the following definitions. For those that are illegal, explain what is wrong and how to correct it.

## a) std::cin >> int input_value;

**Validity:** Illegal

**Explanation:** `int input_value` is being defined in a place where an expression in expected by `std::cin` standard input stream.

**Correction:** Define the variable before using the standard input:

```cpp
int input_value;
std::cin >> input_value;
```

## b) int i = { 3.14 };

**Validity:** Illegal

**Explanation:** List initialization of a variable is not permitted if data loss occurs. Here, there is a narrowing conversion of `3.1400000000000001e+0` from `double` to `int`.

**Correction:** If truncation of fractional part is intended and acceptable, use another form of initialization:

```cpp
int i(3.14);
int i = 3.14;
```

## c) double salary = wage = 9999.99;

**Validity:** Illegal

**Explanation:** If multiple operators of the same precedence are present in a single decalaration, their associativty decides which declaration is performed first. Since assignment operator has Group 15 precedence with right-to-left associativity, the multi-assignment statement is broken down into two separate assignments / initializations, with the right one performed first:

```cpp
double salary = (wage = 9999.99);
```

The right assignment is performed, and since an assignment expression returns its lvalue, `wage` is returned. Therefore, provided `wage` was successfully assigned the value `9999.99`, the second phase of the multi-assignement (initialization of `salary`) is performed:

```cpp
double salary = wage;
```

However, the right assignment `wage = 9999.99` is not successful, since `wage` was never declared. As a result, the compiler complains with the error: `wage` was not declared in this scope.

**Correction:** Declare `wage` before performing the multi-assignment in a single statement:

```cpp
double wage;
double salary = wage = 9999.99;
```

## d) int i = 3.14;

**Validity:** Legal

**Explanation:** The rvalue in this initializing declaration is a double-precision floating-point literal. Performing an initiliazation / assignment for `int` from a floating-point literal results in arithmetic promotion. The floating-point literal's fractional part is truncated, and `i` is successfully initialized to `3`. 