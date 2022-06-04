# The bitwise operators

The bitwise operators take operands of integral type that they use as a collection of bits. Theses operators let us test and set individual bits. We can also use these operators on a library type called `bitset` that represents a flexibly sized collection of bits. As usual, if an operand is a "small integer type", its value is first promoted to a larger integer type. The operand(s) can be either signed or unsigned. Bitwise operators include: `~` (bitwise NOT), `<<` (left shift), `>>` (right shift), `&` (bitwise AND), `^` (bitwise XOR), and `|` (bitwise OR).

If the operand is signed and its value is negative, then the way that the sign bit is handled in a number of bitwise operations is machine dependent. Moreover, doing a left shift that changes the value of the sign bit has undefined behavior. Because, there are no guarantees for how the sign bit is handled, it is strongly recommended to use `unsigned` types for bitwise operations.

## Bitwise shift operators

The built-in meaning of the operators `>>` and `<<` is to perform bitwise shift on their operands. They yield a value that is a copy of the (possibly promoted) left-hand operand with the bits shifted as directed by the right-hand operand. The right-hand operand must not be negative and must be a value strictly less than the number of bits in the result. Otherwise, the operation is undefined. The bits are shifted left `<<` or right `>>`. Bits that are shifted off the end are discarded:

The left-shift operator inserts 0-valued bits on the right. The behavior of the right-shift operator depends on the type of the left-hand operand: If the operand is `unsigned`, then the operator inserts 0-valued bits on the left; if it is signed type, the result is implementation defined - either copies of sign bit or 0-valued bits are inserted on the left.

## Bitwise NOT operator

The bitwise NOT operator `~` generates a new value with the bits of its operand inverted. Each 1 bit is set to 0, and each 0 bit is set to 1. If for example, the NOT operation is performed on an operand of type `unsigned char`, the operand is first promoted to type: `unsigned int`. And then, each bit is inverted.

## Bitwise AND, XOR, and OR operators

The bitwise AND `&`, XOR `^`, and OR `|` operators generate new values with the bit-pattern composed from its two operands. Type promotion is performed as needed. For each bit position in the result of the bitwise AND operator, the bit is 1 if both operands contain 1; otherwise the result is 0. For the OR (inclusive or) operator `|`, the bit is 1 if either or both operands contain 1; otherwise, the result is 0. For the XOR (exclusive or) operator `^`, the bit is 1 if either but not both operands contain 1; otherwise, the result is 0.

It is a common error to confuse the bitwise and logical operators. For example, to confuse the bitwise AND `&` with the logical AND `&&`, the bitwise OR `|` with the logical OR `||`, and the bitwise NOT `~` with the logical NOT `!`.