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

## Dangling `else`

When we nest an `if` inside another `if`, it is possible that there will be more `if` branches than `else` branches. This problem, usually referred to as dangling `else`, is common to many programming languages that have both `if` and `if else` statements. Different languages solve this problem in different ways. In C++, the ambiguity is resolved by specifying that each `else` is matched with the closest preceding unmatching `if`.

Programmers sometimes get into trouble when they write code that contains more `if` than `else` branches. To illustrate this program, we will rewrite the innermost `if else` that adds a plus or minus sign using a different set of conditions:

```cpp
// WRONG: execution does NOT match indentation; the else goes with the inner if
if (grade % 10 >= 3)
	if (grade % 10 > 7)
		letter_grade += '+'; // grades ending in 8 or 9 get a plus
else
	letter_grade += '-'; // grades ending with 3, 4, 5, 6, or 7 get a minus!
```

The indentation in our code indicates that we intend the `else` to match the outer `if`. However, despite our intentions, and contrary to the indentation, the `else` branch is part of the inner `if`. This code adds a `-` to grades ending in 3 to 7 inclusive! Properly indented to match the actual execution, what we wrote is:

```cpp
if (grade % 10 >= 3)
	if (grade % 10 > 7)
		letter_grade += '+';
	else
		letter_grade += '-';
```

## Controlling the execution path with braces

We can make the `else` match with the outer `if` by enclosing the inner `if` in a block:

```cpp
if (grade % 10 >= 3){
	if (grade % 10 > 7)
		letter_grade += '+';
}
else
	letter_grade += '-';
```

Statements do not span block boundaries, so the inner `if` ends at the close curly before the `else`. The `else` cannot be part of the inner `if`. Now, the nearest unmatched `if` is the outer `if`, which is what we intended all along.
