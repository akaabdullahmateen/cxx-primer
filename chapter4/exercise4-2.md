# Exercise 4.2: Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:

```cpp
* vec.begin()
* vec.begin() + 1
```

## a) `* vec.begin()`

The member selector `.` has the same precedence as the function call `()`, but both have left associativity. Therefore, member selector is performed before the function call. The dereference operator `*` has lower precedence than both member selector and function call, thus, it is the last to be performed.

```cpp
(	*	(	(	vec.begin 	)	()	)	)
```

## b) `* vec.begin() + 1`

The member selector `.` has the same precedence as the function call `()`, but both have left associativity. Therefore, member selector is performed before the function call. The dereference operator `*` has lower precedence than both member selector and function call, thus, it is performed on `vec.begin()`. The addition operator `+` has the lowest operator of all, hence, it is the last one to be performed.

```cpp
(	(	*	(	(	vec.begin 	)	()	)	)	+	1 	)
```