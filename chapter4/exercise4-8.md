# Explain when operands are evaluated in the logical AND, logical OR, and equality operators.

The order of evaluation for logical AND, and logical OR is well-defined. However, for the equality operator, the order of evaluation is undefined according to the C++17 standard, and is decided by implementation - which can choose which operand to evaluate first for the sake of optimization.

For logical AND `&&`, and logical `OR`, the short-circuit evaluation describes, that the right-hand operand need only be evaluated for certain values of the left-hand operand.

Since, logical AND evaluates to `true` only if both the operands evaluate to `true`; result can be speculated only from the left-hand operand if that happens to be `false`. Therefore, the right-hand operand is only evaluated if the left-hand operand evaluates to `true`.

Similarly, logical OR evaluates to `true` if either of the operands is `true`. If the left-operand is found to be `true`, there is no need to evaluate the right-hand operand. As an implication, the right-hand operand is only evaluated if the left-hand operand is `false`.