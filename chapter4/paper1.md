# Expressions

An expression is composed of one or more operands and yields a result when evaluated. The simplest form of an expression is a string literal or variable. The result of such an expression is the value of the variable or literal. More complicated expressions are formed from an operator and one or more operands.

## Fundamentals

### Basic concepts

There are both unary operators and binary operators. Unary operators, such as the address-of and dereference operators, act on one operand. Binary operators suchs as equality and multiplication, act on two operands. There is also one ternary operator that takes three operands and one operand, function call that takes unlimited number of operands.

Some symbols such as `*` as used both as unary (dereference) and binary (multiplication) operator. The context in which a symbol is used determines whether the symbol represents a unary or binary operator.

### Grouping operators and operands

Understanding expressions with multiple operators requires understanding of precedence and associativity of the operators and may depend on the order of evaluation of the operands. For example, the result of the following expression depends on how the operands are grouped together to the operator:

```cpp
5 + 10 * 20/2;
```

The operands to the `*` operator could be 10 and 20, or 10 and 20/2, or 15 and 20, or 15 and 20/2.

### Operand conversion

As part of evaluating an expression, operands are often converted from one type to another. For example, the binary operators usually expect operands with the same type. These operators can be used on operands with different types so long as the operands can be converted to a common type.

Although, the rules are somewhat complicated, for the most part, conversions happen in unsurprising ways. For example, we can convert an integer to a floating point, and vice versa, but we cannot convert a pointer type to floating-point. What may be a bit surprising is that small integral type operands (`bool`, `char`, `short`) are generally promoted to a larger integral type, such as `int`.

### Overloaded operators

The language defines what the operators means when applied to built-in and compound types. We can also define what most operators mean when applied to class types. Because such definitions give an alternate meaning to an existing operator symbol, we refer to them as overloaded operators. The IO library `>>` and `<<` operators and the operators we used with `string`, `vector`, and iterators are all overloaded operators.

When we use an overloaded operator, the meaning of the operator - including the type of its operand(s) and the result - depend on how the operator is defined. However, the number of operands, precedence and associativity of the operator cannot be changed.

### Lvalue and rvalue

Every expression in C++ is either an rvalue or an lvalue. These names are inherited from C and originally had a simple mnemonic purpsoe: lvalues could stand on the left-hand side of an assignment, and rvalues could not.

In C++, the distinction is less simple. In C++, an lvalue expression yields an object or function. However, some lvalues, such as `const` objects, may not the left-hand side of an assignment. Moreover, some expressions yield objects but return them as rvalues, not lvalues. Roughly speaking, when we use an object as an rvalue, we use the object's value (its content). When we use an object as lvalue, we use the object's identity (memory location).

Operators differ as to whether they require lvalue or rvalue operands and as to whether they return lvalues or rvalues. The important part is that (with one exception), we can use an lvalue when an rvalue is required, but we cannot use an rvalue when an lvalue is required. When we use an lvalue in place of an rvalue, the object's contents (its value) are used.

- Assignments requires a non-const lvalue as its left-hand operand and yields its left-hand operand as lvalue.
- The address-of operator requires an lvalue operand and returns a pointer to its operand as an rvalue.
- The built-in dereference and subscript operators and the iterator dereference and `string` and `vector` subscript operators, all yield lvalues.
- The built-in and iterator increment and decrement operators require lvalue operands and the prefix versions (which are the ones we have used so far) also yield lvalues.

### Order of evaluation

Precedence specifies how the operands are grouped. It says nothing about the order in which the operands are evaluated. In most cases, the order is largely unspecified. In the following expression:

```cpp
int i = f1() * f2();
```

We know that `f1` and `f2` must be called before the multiplication can be done. After all, it is their result that are multiplied. However, there is no way of knowing whether `f1` will be called before `f2` or vice versa.

For operators that do not specifiy evaluation order, it is an error for an expression to refer to or change the same object. Expressions that do so have undefined behavior. As a simple example, the `<<` operator makes no guarantee about when or how its operands are evaluated. As a result, the following output expression is undefined:

```cpp
int i = 0;
cout << i << " " << ++i << endl; // undefined
```

Because this program is undefined, we cannot draw any conclusions about how it might behave. The compiler might evaluate `++i` first, in which case, the output will be `0 1`. Or the compiler might evaluate `i` first, in which case the output will be `0 1`. Or the compiler might do something else entirely. Because this expression has undefined behavior, the program is in error, regardless of what code the compiler generates.

There are four operators that do guarantee the order in which operands are evaluated. We saw in § 3.2.3 (p. 94) that the logical AND (`&&`) operator guarantees that its left-hand operand is evaluated first. Moreover, we are also guaranteed that the right-hand operand is evaluated only if the left-hand operand is `true`. The only other operators that guarantee the order in which operands are evaluated are the logical OR (`||`) operator (§ 4.3, p. 141), the conditional (`? :`) operator (§ 4.7, p. 151), and the comma (`,`) operator (§ 4.10, p. 157).

### Order of evaluation, precedence, and associtiavity

Order of operand evaluation is independent of precedence and associtiavity. In an expression such as `f() + g() * h() + j()`:

- Precedence guarantees that the results of `g()` and `h()` are multiplied.
- Associativity guarantees that the result of `f()` is added to the product of `g()` and `h()` and the result of that addition is added to the value of `j()`.
- There are no guarantees as to the order in which these function calls are called.

If `f`, `g`, `h`, `j` are indepedent functions that do not affect the state of the same object or perform IO, then the order in which the functions are called is irrelevant. If any of these functions do affect the same object, then the expression is in error and has undefined behavior.