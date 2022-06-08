# Exercise 6.13: Assuming `T` is the name of a type, explain the difference between a function declared as `void f(T)` and `void f(T&)`

- `void f(T)` is passing the parameter of type `T` by value, whereas, `void f(T&)` is passing the parameter by reference.

- The former creates a copy of the original object, whereas, the later uses the same object, and operations of the parameter inside the function `f` is infact, operations on the argument passed.

- Because, both can be called with a variable name as argument, the call of overloaded functions `f` - in case, both are declared - will be ambiguous, hence, illegal.

- Moreover, `void f(T)` creates the copy of the argument passed in the parameter, it is more permissive with the type for its argument - can be type `T` object, `const`-qualified type `T` object, can be literal of type `T`, expression that evaluates to type `T`, or another type `T2` such that a legal conversion exists between the two.

- `void f(T&)` is more restricted in the types of argument. As is the case with variables declared as reference, parameters declared as reference, must be initialized with argument whose type exactly matches type `T` with few exceptions - low-level `const`-qualification can be promoted from non-`const` to `const`, but not vice versa. Also, it needs to be valid objects of type `T`, and not literals, or expressions that evaluate to type `T`.