# Exercise 2.22: Assuming `p` is a pointer to `int`, explain the following code:

```cpp
if (p) // ...
if (*p) // ...
```

## `if (p)`

This statement evaluates the expression `p` as a condition for the `if` statement. Since, this expression is type converted to `bool`. If `p` contains the value `0` as is the case for null pointers - initialized with `nullptr`, `0`, or `NULL` - the condition evaluates to `false`. Any other value (address) in the pointer will make this expression evaluate to `true`.

Since, it is provided that the pointer `p` points to an `int` object. The pointer's value is not null, and contains a valid address. Thereby, the condition evaluates as `true`; and the statements in the block next to the `if` statement are executed.

## `if (*p)`

This statement checks the value of the object to which the pointer `p` points to, as the condition for the `if` statement. Therefore, if the integer object contains any value other than `0`, this expression will evalulate as `true`; and `false` otherwise.