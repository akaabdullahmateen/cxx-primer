# Exercise 6.2: Indicate which of the following functions are in error and why. Suggest how you might correct the problems.

## Snippet a)

```cpp
int f() {
	string s;
	// . . .
	return s;
}
```

**Error:** The function is declared to return `int`, but the `return` statement is infact returning a `string`. Moreover, there is no conversion from `string` to `int`.

**Correction:** Change the return type from `int` to `string`.

## Snippet b)

```cpp
f2(int i) { /* . . . */ }
```

**Error:** No return type declared for the function `f2`. ISO C++ forbids declaration of functions without a type.

**Correction:** Since the program logic does not need to return anything, set the return type to `void`.

## Snippet c)

```cpp
int calc(int v1, int v1) /* . . . */ }
```

**Error:** Expecting opening curly braces after parameter list. Also, two parameters cannot have the same identifier name.

**Correction:** Add opening curly brace symbol after parameter list, and rename the second parameter to `v2` (or something other than `v1`).

## Snippet d)

```cpp
double square(double x) return x * x;
```

**Error:** Functions needs to enclose statement list in a block.

**Correction:** Enclose the `return` statement in curly braces.