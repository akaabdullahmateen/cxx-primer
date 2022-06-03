# The conditional operator

The conditional operator (`?:`) lets us embed simple if-else logic inside an expression. The conditional operator has the following syntax:

```cpp
cond ? expr1 : expr2;
```

Where `cond` is an expression that is used as a condition, and `expr1` and `expr2` are expressions of the same type (or types that can be converted to a common type). This operator executes by evaluating `cond`. If the condition is `true`, then `expr1` is evaluated; otherwise, `expr2` is evaluated. As one example, we can use a conditional operator to determine whether a grade is pass or fail:

```cpp
string final_grade = (grade < 60) ? "fail" : "pass";
```

The condition checks whether grade is less than 60. If so, the result of the expression is "fail"; otherwise the result is "pass". Like the logical AND and logical OR (`&&` and `||`) operators, the conditional operator guarantees that only one of `expr1` or `expr2` is evaluated. That result of the conditional operator is an lvalue if both expressions are lvalues or if they convert to a common lvalue type. Otherwise the result is an rvalue.

## Nesting conditional operators

We can nest one conditional operator inside another. That is, the conditional operator can be used as the `cond` or as one or both of the `expr`s of another conditional expression. As an example, we’ll use a pair of nested conditionals to perform a three-way test to indicate whether a grade is a high pass, an ordinary pass, or fail:

```cpp
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```

The first condition checks whether the grade is above 90. If so, the expression after the `?` is evaluated, which yields "high pass". If the condition fails, the `:` branch is executed, which is itself another conditional expression. This conditional asks whether the grade is less than 60. If so, the `?` branch is evaluated and yields "fail". If not, the `:` branch returns "pass". The conditional operator is right associative, meaning (as usual) that the operands group right to left. Associativity accounts for the fact that the right-hand conditional — the one that compares grade to 60 — forms the `:` branch of the left-hand conditional expression. Nested conditionals quickly become unreadable. It’s a good idea to nest no more than two or three.

## Using a conditional operator in an output expression

The conditional operator has fairly low precedence. When we embed a conditional expression in a larger expression, we usually must parenthesize the conditional subexpression. For example, we often use the conditional operator to print one or another value, depending on the result of a condition. An incompletely parenthesized conditional operator in an output expression can have surprising results:

```cpp
cout << ((grade < 60) ? "fail" : "pass"); 	// prints pass or fail
cout << (grade < 60) ? "fail" : "pass"; 	// prints 1 or 0!
cout << grade < 60 ? "fail" : "pass"; 		// error: compares cout to 60
```

The second expression uses the comparison between `grade` and 60 as the operand to the `<<` operator. The value 1 or 0 is printed, depending on whether `grade < 60` is `true` or `false`. The `<<` operator returns `cout`, which is tested as the condition for the conditional operator. That is, the second expression is equivalent to:

```cpp
cout << (grade < 60); 	// prints 1 or 0
cout ? "fail" : "pass"; // test cout and then yield one of the two literals
						// depending on whether cout is true or false
```

The last expression is an error because it is equivalent to:

```cpp
cout << grade; // less-than has lower precedence than shift, so print grade first
cout < 60 ? "fail" : "pass"; // then compare cout to 60!
```