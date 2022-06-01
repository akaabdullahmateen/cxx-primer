# Exercise 2.17: What does the following code print?

```cpp
int i, &ri = i;
i = 5;
ri = 10;
std::cout << i << " " << ri << std::endl;
```

**Output:** `10 10`

**Explanation:** The first statement defines the integer variable `i`, but does not initialize it; and defines integer reference `ri`, and initializes to the object `i`. Since, the type matches, the initialization is successful. However, since the integer variable `i` is not initialized or assigned any value, its value is undefined. As a result of which, the reference `ri` is bound to an uninitialized object `i` with undefined value. The next statement assigns the value `5` to `i`. Now, the reference `ri` - which was bound to `i` - points to this value `5`. The third statement assigns `10` to the reference `ri`. Because, `ri` is just a reference to `i`, the assignment is infact done to `i`. The fourth statement which prints to standard output, prints the value of `i` which is `10`, and `ri` which is also `10`, since its value is that of its bound object's.