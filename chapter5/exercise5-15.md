# Exercise 5.15: Explain each of the following loops. Correct any problems you detect.

## Snippet a)
```cpp
for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
if (ix != sz)
	// . . .
```
**Explanation:** Assuming `sz` is the size of some vector, the loop tries to iterate over all elements in that vector. The `for` loop terminates when the index variable is equal to the size of the vector. The statement following the `for` is an `if`, that tries to check for inequality of `ix` and `sz`. However, the variable `ix` is declared in the init-statement of the `for` header, therefore, out of scope for the `if` statement.

**Correction:** Declare `int ix` outside (and before) the `for` loop, so that it is in scope for both the `for` and `if` statements.

## Snippet b)

```cpp
int ix;
for (ix != sz; ++ix) { /* . . . */ }
```
**Explanation:** Similar to the previous code, the intention is to iterate over all elements in some container, till the index is same as the size of this container. However, `for` statement requires an init-statement in its header. Since, `ix` is declared before the `for`, it is meaningless to declare it inside the `for`. But this causes the compiler to think that the expression-statement `ix != sz;` is the init-statement, and `++ix` is the condition. It therefore, expects a semicolon before the closing parentheses in the `for` header. And, the expression is considered to be left empty. This is clearly not what is intended.

**Correction:** Add null statement in place of init-statement, so that the compiler knows that it is left empty, and the condition is the next expression following this semicolon. Thereby, the interpretation of the program logic will be as intended.

## Snippet c)

```cpp
for (int ix = 0; ix != sz; ++ix, ++sz) { /* . . . */ }
```
**Explanation:** Yet again, the intention is to iterate over all elements in some container of size `sz`. However, the expression in the `for` header uses the comma operator to evaluate two sub-expressions: prefix increment on `ix`, and prefix increment on `sz`. Although perfectly legal - provided `sz` is a mutable object - the loop will never terminate, since the very condition requires the index to approach the size of the container. But the size `sz` increments along with `ix` causing the loop to run indefinitely.

**Correction:** The sub-expression that increments `sz` - right-hand operand for the comma operator in the expression - should be removed.
