# Exercise 6.20: When should reference parameters be references to `const`? What happens if we make a parameter a plain reference when it could be a reference to `const`?

## Reference parameters need to be reference to `const` when the following is required

- Arguments can be literals, expressions, or of convertible type.
- No modification of the value of the underlying object.
- `const`-qualified arguments are passed.