# Exercise 4.9: Explain the behavior of the condition in the following `if` statement:

```cpp
const char *cp = "Hello World";
if (cp && *cp)
```

- `cp` is defined as a C-style string - array of `const` `char` for which end is detected by the precense of the null terminator.
- The `if` statement evalutes a logical AND expression. The logical AND only evaluates the right-hand operand if the left-hand operand evaluates to `true`.
- The left-hand operand tests the truth value of the pointer `cp` - which will evaluate to `true` if `cp` is not a null pointer.
- Since, the left-hand operand will evaluate to `true` - provided that `cp` is initialized successfully, therefore not be a null pointer - the right-hand operand is evaluated which tests for the truth value of the `char` pointed to by the pointer `cp`.
- This test will evaluate to `true` if the character pointed to by the pointer is not a null terminator.
- Since, `cp` initially points to the first character in the C-style string - which is `H` - this test also evaluates to `true`.
- Therefore, the `if` statement evalutes the condition to be `true`, and executed the following statement.