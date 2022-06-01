## Compound types, `const` and `auto`

The type that the compiler infers for `auto` is not always exactly the same as the initializer's type. Instead, the compiler adjusts the type to conform to normal initialization rules. When we are using reference as an initializer, the initializer is the corresponding object. The compiler uses the object's type for `auto`'s  type deduction:

```cpp
int i = 0, &r = i;
auto a = r;			// a is an int (r is an alias for i, which has type int)
```

Second, `auto` originally ignores top-level `const`s. As usual in initializations, low-level `const`s, such as when an initializer is a pointer to `const`, are kept:

```cpp
const int ci = i, &cr = ci;
auto b = ci; // b is an int (top-level const in ci is dropped)
auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
auto d = &i; // d is an int* (& of an int object is int*)
auto e = &ci; // e is const int* (& of a const object is low-level const)
```

If we want the deduced type to have a top-level `const`, we must say so explicitly:

```cpp
const auto f = ci; // deduced type of ci is int; f has type const int
```

We can also specify that we want a reference to the `auto`-deduced type. Normal initialization rules still apply:

```cpp
auto &g = ci;		// g is a const int& that is bound to ci
auto &h = 42;		// error: we can’t bind a plain reference to a literal
const auto &j = 42; // ok: we can bind a const reference to a literal
```

When we ask for a reference to an `auto`-deduced type, top-level `const`s in the initializer are not ignored. As usual, `const`s are not top-level when we bind a reference to an initializer. When we define several variables in the same statement, it is important to remember that a reference or a pointer is part of a particular declarator and not part of the base type of the declaration. As usual, the initializers must provide consistent `auto`-deduced types:

```cpp
auto k = ci, &l = i;	// k is int; l is int&
auto &m = ci, *p = &ci; // m is a const int&; p is a pointer to const int
auto &n = i, *p2 = &ci;	// error: type deduced from i is int; type deduced from &ci is const int // should not type of &ci be const int* ?
```

## The `decltype` type specifier

Sometimes we want to define a variable with a type that the compiler deduces from an expression but do not want to use that expression to initialize the variable. For such cases, the new standard introduced a second type specifier `decltype` which returns the type of its operand. The compiler analyzes the expression to determine its type but does not evaluate the expression:

```cpp
decltype(f()) sum = x; // sum has whatever type f returns
```

Here, the compiler does not call `f` but it uses the type that such a call would return as the type for `sum`. That is, the compiler gives `sum` the same type as the type that would be returned if we were to call `f`. The way `decltype` handles top-level `const` and references differs subtly from the way `auto` does. When the expresiion to which we apply `decltype` is a variable, `decltype` returns the type of that variable, including top-level `const` and references:

```cpp
const int ci = 0, &cr = ci;
decltype(ci) x = 0; 		// x has type const int
decltype(cr) y = x; 		// y has type const int& and is bound to x
decltype(cr) z;				// error: z is a reference and must be initialized
```

It is worth noting that `decltype` is the only context in which a variable defined as a reference is not treated as a synonym for the object to which it refers.

## `decltype` and references

When we apply `decltype` to an expression that is not a variable, we get the type that the expression yields. Some expressions will cause `decltype` to yield a reference type. Generally speaking, `decltype` returns a reference type for expressions that yeild objects that can be lvalues.

```cpp
// decltype of an expression can be a reference type
int i = 42, *p = &i, &r = i;
decltype(r + 0) b; 			// ok: addition yields an int; b is an (uninitialized) int
decltype(*p) c;				// error: c is int& and must be initialized
```

Here `r` is a reference, so `decltype(r)` is a reference type. If we want the type to which `r` refers, we can use `r` in an expression, such as `r + 0`, which is an expression that yields a value that has a nonreference type. On the other hand, the dereference operator is an example of an expression for which `decltype` returns a reference. When we dereference a pointer, we get the object to which the pointer points. Moreover, we can assign to that object. Thus, the type deduced by `decltype(*p)` is `int&` and not plain `int`. Another important difference between `decltype` and `auto` is that the deduction done by `decltype` depends on the form of its given expression. What can be confusing is that enclosing the name of a variable in parentheses affects the type returned by `decltype`. When we apply `decltyp` to a variable without any parentheses, we get the type of that variable. If we wrap the variable's name in one or more set of parentheses, the compiler will evaluate the operand as expression. A variable is an expression that can be lvalue. As a result, `decltype` on such an expression yields a reference:

```cpp
// decltype of a parenthesized variable is always a reference
decltype((i)) d;	// error: d is int& and must be initialized
decltype(i) e;		// ok: e is an (uninitialized) int
```