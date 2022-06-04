# Exercise 4.33: Using Table 4.12 (p. 166) explain what the following expression does:

```cpp
someValue ? ++x, ++y : --x, --y
```

| **Operator** | **Function** | **Associativty** |
|:------------:|:------------:|:----------------:|
| `++`         | increment    | R                |
| `--`         | decrement    | R                |
| `?:`         | conditional  | R                |
| `,`          | comma        | L                |

```cpp
someValue ? (++x), (++y) : (--x), (--y)
(someValue ? (++x), (++y) : (--x)), (--y)
```

Because comma operator has lower precedence than conditional operator, the second expression in the conditional expression is divided with the left-hand subexpression operand of comma operator being grouped tightly with the rest of the conditional expression. Therefore, this expression evaluates the conditional expression based on the value of `someValue` - evaluating the first expression if `true` or second expression if `false`. This two expressions in the conditional expression are `++x, ++y` and `--x`. The conditional expression itself is grouped as: `someValue ? ++x, ++y : --x`. Because the comma operator guarantees the order of evaluation, this conditional expression is evaluated first, and its result is discarded. Then, the right-hand operand of comma operator is evaluated and returned. Because, `--y` uses the prefix decrement operator, it returns lvalue, and thus, comma operation returns lvalue.