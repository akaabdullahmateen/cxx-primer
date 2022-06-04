# Exercise 4.34: Given the variable definitions in this section, explain what conversions take place in the following expressions:

```cpp
float 	fval;
double 	dval;
int 	ival;
char 	cval;

if (fval) { /* . . . */ }
dval = fval + ival;
dval + ival * cval;
```

## `if (fval)`

The `if` statement expects conditional expression to return `bool` value, therefore, `float` `fval` is convertd to `bool` value. This value is `true` if `fval` has nonzero value, and `false` otherwise.

## `dval = fval + ival;`

Because, addition operator has higher precedence than assignment operator, the expression `fval + ival` is evaluated first. The arithmetic conversion tries to preserve precision, therefore, the `int` `ival` is converted to `float`. This expression returns `float` value. Then, assignment occurs, in which, `float` is converted to `double`, because the lvalue object has type `double`.

## `dval + ival * cval;`

Multiplication operator has higher precedence than addition operator. Thus, the subexpression `ival * cval` is evaluated first. The `char` `cval` is promoted to type `int`. Because, types of promoted `cval` and `ival` match, no further conversion is done, and this subexpression returns `int` result. This `int` result becomes the right-hand operand of the addition operator with `dval`. Because, the arithmetic conversion rules tries to preserve precision, `int` is converted to `double`, and the expression result is `double`.
