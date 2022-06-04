# Type conversions

In C++, some types are related to each other. When two types are related, we can use an object of one type where an operand of the other related type is expecetd. Two types are related if there is a conversion between them. As an example, consider the following expression which initializes `ival` to 6:

```cpp
int ival = 3.541 + 3; // the compiler might warn you about loss of precisions (a.k.a narrowing conversion)
```

The operands of the addition operator are values of different types: 3.541 has type `double`, whereas, 3 has type `int`. Rather than trying to add values of different types, C++ defines a set of conversions to transform the operands to a common type. These conversions are carried out automatically without the programmer's intervention - and sometimes without the programmer's knowledge. For that reason, they are referred to as implicit conversion.

The implicit conversion among the arithmetic types are defined to preserve precision, if possible. Most often, if expression has both an integral type and a floating-point type, the integral type is converted to the floating-point type. In the example above, 3 was converted to `double`, and floating-point addition is done, and the result has type `double`.

Then initialization happens. In an inilization, the type of the object we are initializing, dominates. The initializer is converted to the object's type. In this case, `double` result 6.541 is converted to `int`, and used to initialize `ival`. Converting `double` to `int` discards the decimal portion (truncation). Thus, 6 is assigned to `ival`.

## When implicit conversion happens

The compiler automatically converts operands in the following circumstances:

- In most expressions, values of integral types smaller than `int` are first promoted to an appropriate large integral type.
- In conditions, non-`bool` expressions are converted to `bool`.
- In initializations, the initializer is converted to the type of the variable; in assignments, the right-hand operand is converted to the type of the left-hand operand.
- In arithmetic and relational expressions with mixed type operands, the types are converted to a common type.
- Conversions also happen in function calls.

## The arithmetic conversions

The arithmetic conversions convert one arithmetic type to another. The rules define a hierarchy of type conversions in which operands to an operand are converted to the widest type. For example, if one operand is of type `long double`, then the other operand is converted to `long double` regardless of what the second type is. More generally, in expressions that mix floating-point and integral values, integral values are converted to an appropriate floating-point type.

## Integral promotions

The integral promotions convert the small integral types to a larger integral type. The types `bool`, `char`, `unsigned char`, `signed char`, `short`, and `unsigned short` are promoted to `int` if all possible values of that type can fit into `int`, otherwise the value is promoted to `unsigned int`. A `bool` that is `false` is promoted to `0`, and `true` to `1`.

The larger `char` types `wchar`, `char16_t`, `char32_t`, are promoted to the smallest type of `int`, `unsigned int`, `long`, `unsigned long`, `long long`, or `unsigned long long` in which all possible values of that type can fit into.

## Operands of unsigned type

If the operands of an operator have different types, those operands are ordinarilly converted to a common type. If any operand is `unsigned` type, the type to which the operands are converted depends on the relative sizes of the integral types on the machine.

As usual, integral promotion happens first. If the resulting type(s) match, no further conversion is needed. If both (possibly promoted) operands have the same signedness, then the operand with the smaller type is converted to the larger type.

When signedness differs and the type of the unsigned operand is the same as or larger than that of the signed operand, the signed operand is convertd to the unsigned type. For example, given an `unsigned int` and an `int`, the `int` is converted to `unsigned int`. It is worth noting that if `int` has negative value, the result will be converted with the same results.

The remaining case is when the signed operand has a larger type than the unsigned operand. In this case, the result is machine dependent. If all values in the unsigned type fit into the larger type, then the unsigned operand is converted to the signed type. If the values do not fit, then the signed operand is converted to the unsigned type. For example, if the operands are `long` and `unsigned int`, and `int` and `long` have the same size, the `long` will be converted to `unsigned int`. If the `long` has more width (bits), then the `unsigned int` will be converted to `long`.
