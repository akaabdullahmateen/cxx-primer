# Exercise 4.14: Explain what happens in each of the `if` tests:

```cpp
if (42 = i) // ...
if (i = 42) // ...
```

In the condition of the first `if` statement, the assignment operator tries to assign the value from the object `i` to the integer literal `42`. However, integer literals are rvalues, and cannot be assigned some value. The compiler hence complains with the error message: `lvalue required as left operand of assignment`

In the second condition, the assignment operator tries to assign the value `42` to the object `i`. Since, `i` is an lvalue, the assignment is successful, and the left-hand operand which is `i`, is returned. The condition is then to check the truth value of `i`, which is `true`, since, `i` has the value `42`, and any nonzero integer value is `true`. The condition thereby succeeds, and the statement(s) next to the `if` statement are executed.