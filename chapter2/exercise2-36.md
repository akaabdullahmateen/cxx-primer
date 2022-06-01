# Exercise 2.36: In the following code, determine the type of each variable and the value each variable has when the code finishes:

```cpp
int a = 3, b = 4; 		// a is int, b is int
decltype(a) c = a;		// c is int
decltype((b)) d = a;	// d is int&
++c;
++d;
```

| **Identifier** | **Type** | **Value** |
|----------------|----------|-----------|
| `a`            | `int`    | 4         |
| `b`            | `int`    | 4         |
| `c`            | `int`    | 4         |
| `d`            | `int&`   | 4         |