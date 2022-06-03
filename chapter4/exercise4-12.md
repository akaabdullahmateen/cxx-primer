# Exercise 4.12: Assuming `i`, `j`, and `k` are all `int`, explain what `i != j < k` means.

- Since, the relational operator `<` has higher precedence than the equality operator `!=`, `j < k` is grouped more tightly than the equality test.
- The expression therefore checks whether `j` is less than `k`, and evaluates this subexpression to a `bool` value of `true` or `false`, as the case maybe.
- The expression then tries to check for equality among an `int` and a `bool` value, which is not possible, therefore, the `bool` value on the right-hand side, is promoted to `int` value - which will be `1` if the relation test evaluated to `true`, and `0` if it were `false`.
- Thus, the expression is basically testing `i` for equality with one of the two `int` values: `0` and `1`.