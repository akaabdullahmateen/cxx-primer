# Exercise 4.19: Given that `ptr` points to an `int`, that `vec` is a `vector<int>`, and that
`ival` is an `int`, explain the behavior of each of these expressions.

**Which, if any, are likely to be incorrect? Why? How might each be corrected?**

1. `ptr != 0 && *ptr++`
2. `ival++ && ival`
3. `vec[ival++] <= vec[ival]`

## `ptr != 0 && *ptr++`

Since, the left-hand side of the logical AND operator is always evaluated first, the subexpression `ptr != 0` is evaluated first. This expression tests the value of `ptr` against the literal `0` for inequality. Since, `ptr` is a pointer to an `int`, this subexpression effectively ensures that `ptr` is not a null pointer. If pointer `ptr` is not a null pointer, the right-hand expression of the logical AND operator is evaluated. This subexpression dereferences the current value of pointer, and increments the pointer later. Hence, this right-hand side will evaluate to `true` only if the current value pointed to by `ptr` is nonzero, and `false` if zero. The overall expression evaluates to `true`, only if the pointer `ptr` is not a null pointer, and the value pointed to by the pointer is nonzero initially. The effect will be to increment the value of pointer `ptr` after the evaluation of the expression (after right-hand side evaluation).

## `ival++ && ival`

Because the logical AND always tests its left-hand operand first, the expression `ival++` is evaluated. This expression returns the value of `ival` as prvalue, and increments the value of `ival`. This expression will have truth value of `true` if the current value in `ival` is nonzero, and `false` otherwise. If this current value is nonzero, the right-hand side of the logaical AND is evaluated, whereby, the value of `ival` is yet again tested for truth value. Since, `ival` was incremented by the left-hand side expression, and because this order of evaluation is guaranteed, the value of `ival` will be the result of incrementing the original value of `ival`. If this incremented value is nonzero, the overall expression evaluates to `true`, and `false` otherwise. The effect is to test whether the current value of `ival` is nonzero, and the incremented value is nonzero as well. The intention must have been to test whether `ival` is nonzero, and if so, increment it. The correct expression is provided below. Also, because the prefix / postfix operations perform the same intended operation, either one of them can be used - but prefix is recommended due to slight performance advantage and better readability.

```cp
ival && ++ival;
```

## `vec[ival++] <= vec[ival]`

As the subscript operator `[]` have higher precedence than the relationship operator `<=`, the element at the respective indexes are compared with the less than or equal to relationship operator. But, the order of evaluation for the relationship operator `<=` is undefined, either of the two expressions can be evaluated first. If the left-hand expression is evaluated first, the value pointed to by `vec[ival]` will be yielded. Whereas, when the right-hand operand is evaluated, the value of `ival` will be incremented. Therefore, `vec[ival]` is infact `vec[ival + 1]`. Thus, the implied meaning of the expression will be test whether the value at index `ival` is less than the value at index `ival + 1`. If however, the right-hand operand evaluated first, the value at index `ival` will be yielded. The left-hand operand will also return the value at `vec[ival]` while incrementing `ival` for future expressions. Since either of the two possibilities (or even something else) can happen, the expression is in error, the resulting behavior is undefined, and the program is ill-formed. The correction however, will be to explicitly use the index `ival + 1` for the left-hand subexpression. If the value of `ival` needs to be incremented, it should be done on the next statement.

```cpp
vec[ival + 1] <= vec[ival]
// ++ival; if needed
```
