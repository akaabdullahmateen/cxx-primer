# Exercise 4.30: Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:

```cpp
sizeof x + y;
sizeof a < b;
sizeof p->mem[i];
sizeof f();
```

## Solution: `+` and `<` have lower operator precedence than `sizeof`

```cpp
sizeof (x + y);
sizeof (a < b);
sizeof p->mem[i];
sizeof f();
```