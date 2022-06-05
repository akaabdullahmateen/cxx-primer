# Conditional statements

C++ provides two statements that allow for conditional execution. The `if` statement determines the flow of control based on a condition. The `switch` statement evaluates an integral expression and chooses one of several execution paths based on the expression's value.

## The `if` statement

An `if` statement conditionally executes another statement based on the whether a specified condition is true. There are two forms of the `if`: one with an `else` branch, and one without. The syntactical form of the simple `if` is:

```cpp
if(condition)
	statement
```

An `if-else` statement has the form:

```cpp
if(condition)
	statement
else
	statement2
```

In both versions, `condition` must be enclosed in parentheses. `condition` can be an expression or an initialized variable declaration. The expression or variable must have a type that is convertible to `bool`. As usual, either or both `statement` and `statement2` can be a block.

If `condition` is `true`, then `statement` is executed. After `statement` completes, execution continues with the statement following the `if` statement.

If `condition` is `false`, then `statement` is skipped. In a simple `if`, execution continues with the statement following the `if`. In an `if else` statement, `statement2` is executed.