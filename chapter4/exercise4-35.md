# Exercise 4.35: Given the following definitions, identify the implicit type conversions, if any, taking place:

```cpp
char 			cval;
float 			fval;
int 			ival;
unsigned int 	ui;
double 			dval;
```

```cpp
cval = ’a’ + 3;
dval = ui * fval;
fval = ui - ival * 1.0;
cval = ival + fval + dval;
```

## `cval = ’a’ + 3;`

Character literal `'a'` of type `char` is promoted to type `int`. This matches the type of the integer literal which has type `int`. Thus, integer addition is done. The result is converted to type `char` under narrowing conversion, whereby, if the result is too large to fit into `char`, its left-most portion will be discarded to fit into `char`.

## `dval = ui + fval;`

Variable `ui` with type `unsigned int` is converted to type `float`, because arithmetic conversion tries to preserve precision. The `float` result is assigned to `dval` after being converted to `double`.

## `fval = ui - ival * 1.0;`

Multiplication operator has the highest precedence in the expression, thus, `ival * 1.0` is evaluated first, whereby, `ival` is converted to `float` type. The single-precision floating point result is subtracted from `unsigned int` `ui`. Again, `ui` is converted to `float`. The floating point result is assigned to `fval`, with no further conversion.

## `cval = ival + fval + dval;`

Addition operator is left-associative. Therefore, `ival + fval` is evaluated first. `ival` is converted to `float`. The single-precision floating-point result is then added to `dval` after being converted to `double`. The result of type `double` is then converted to `char` type under narrowing conversion.
