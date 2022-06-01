# Exercise 2.27: Which of the following initializations are legal? Explain why?

```cpp
int i = -1, &r = 0;				// error: cannot bind non-const lvalue reference of type `int&` to an rvalue of type `int`
const int i2 = i, &r2 = i;		// ok: can bind const qualified lvalue reference of type `const int&` to non-const qualified rvalue of type `int`
const int *p1 = &i2;			// ok: low-level const qualified pointer can point to top-level const qualified object
int *const p2 = &i2;			// error: invalid conversion from `const int*` to `int*`
const int i3 = -1, &r3 = 0;		// ok: can bind const qualified lvalue reference of type `const int&` to an rvalue of type `int`
const int *const p3 = &i2;		// ok: low-level const qualified pointer can point to top-level const qualified object
const int &const r4;			// error: `const` qualifiers cannot be applied to `const int&`; declared as reference but not initialized
```