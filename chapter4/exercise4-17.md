# Explain the difference between prefix and postfix increment operators.

## Prefix increment and decrement

The operand of prefix `++` is modified by adding `1`. The operand shall be a modifiable lvalue. The type of the operand shall be an arithmetic type other than cv-qualified `bool`, or a pointer to a completely-defined object type. The result is the updated operand; it is an lvalue. The expression `++x` is equivalent to `x += 1`.

The operand of prefix `--` is modified by subtracting `1`. The requirements on the operand of prefix `--` and the properties of its result are otherwise the same as those of prefix `++`.

## Postfix increment and decrement

The value of the postfix `++` expression is the value of its operand. The value obtained is a copy of the original value. The operand shall be a modifiable lvalue. The type of the operand shall be an arithmetic type other than cv-qualified `bool`, or a pointer to a completely-defined object type. The value of the operand object is modified by adding `1` to it. The value computation of the `++` expression is sequenced before the modification of its operand object. With respect to an undeterminately-sequenced function call, the operation of postfix `++` is a single expression. Therefore, a function call cannot intervene between the lvalue-to-rvalue conversion and the side effect associated with any single postfix `++` operator.

The result is a prvalue. The type of the result is the cv-unqualified version of the type of its operand. The operand of postfix `--` is decrementing analogously to the postfix `++` operator.

## Differences between prefix and postfix versions

- The result of the prefix operators is its modified operand; whereas, the result of the postfix operators is a copy of the original value.
- The result of the prefix operators is an lvalue; whereas, the result of the postfix operators is a prvalue.