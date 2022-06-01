# Exercise 2.16: Which, if any, of the following assignments are invalid? If they are valid, explain what they do.

```cpp
int i = 0, &r1 = i;
double d = 0, &r2 = d;

r2 = 3.14159;
r2 = r1;
i = r2;
r1 = d;
```

## a) `r2 = 3.14159;`

**Validity:** Legal

**Action:** `d` is assigned the value `3.14159`

**Explanation:** Since `r2` is a reference to the double-precision floating-point variable `d`, the expression evaluates to: `d = 3.14159;`. Therefore, `d` is assigned the value `3.14159`.

## b) `r2 = r1;`

**Validity:** Legal

**Action:** `d` is assigned the value `0`

**Explanation:** Reference `r2` is bound to floating-point `d`, and reference `r1` is bound to integer `i`. The expression, hence, evaluates to: `d = i;`. The value in `i` is promoted to double-precision floating-point type, and assigned to `d`.

## c) `i = r2;`

**Validity:** Legal

**Action:** `i` is assigned the value `0`

**Explanation:** Since, `r2` is a reference to the double-precision floating-point variable `d` with value `0`, the expression results in the integer `i` being assigned the type promoted value from `d` to `i`.

## d) `r1 = d;`

**Validity:** Legal

**Action:** `i` is assigned the value `0`

**Explanation:** Reference `r1` is bound to integer `i`, as a result of which, the expression evaluates to: `i = d;`. The value of floating-point `d` is type promoted and assigned to integer `i`.