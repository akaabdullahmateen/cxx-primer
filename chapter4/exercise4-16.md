# Exercise 4.16: Although the following are legal, they probably do not behave as the programmer expects.

**Why? Rewrite the expressions as you think they should be.**

```cpp
if (p = getPtr() != 0)
if (i = 1024)
```

## Condition in the first `if` statement

- Because assignment operator has lower precedence than the inequality operator, the inequality test is performed first.
- Thus, value returned from `getPtr()` call is checked against the literal value `0`.
- The result of this subexpression is a `bool`, which would be either `true` or `false`, depending on what `getPtr()` returned.
- Assuming, `p` is an `int*`, the `bool` result is promoted to `int`, whereby, `true` becomes `1`, and `false` becomes `0`.
- The pointer `p` is assigned this value - either of `1` or `0`.
- Assigning the pointer `p` the value of `0` would result in a valid null pointer.
- However, assigning the pointer `p` the value of `1` is dangerous and would make the pointer invalid - any dereferencing operation would result in undefined behavior.
- If `p` was assigned the value `0` - `p` is a null pointer - the condition evaluates itself to be `false`, and the `if` execution block never executes.
- If `p` was assigned the value `1`, although, potentially very dangerous and illegal, the condition testifies `true`, and the statements next to the `if` are executed.

The programmer's intention was, however, to get the value from the function call `getPtr()`, and store it inside the pointer `p`. Then, to check whether `p` is not a null pointer, by checking for inequality against the literal `0`. The correction would be to group the assignment more tightly, by enclosing it inside parenthesis:

```cpp
if ((p = getPtr()) != 0)
```

## Condition in the second `if` statement

- The assignment operator assigns the literal value `1024` to the variable `i` - which is successful, because `i` is an lvalue.
- The assignment returns its left-hand operand `i` for the condition test.
- The truth value of `i` which has value `1024` is `true`, because any nonzero integer value evaluates to `true` when converted from `int` to `bool`.
- The statement(s) next to the `if` statement are executed.

The programmer's intention was, however, to test for equality of the value of `i` and the integer literal `1024`. The correction would be to use the equality operator:

```cpp
if (i == 1024)
```
