# Exercise 4.24: Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative.

**Describe how that operator would be evaluated if the operator were left associative.**

```cpp
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```

## Right association

```cpp
finalgrade = (grade > 90) ? "high pass" : ((grade < 60) ? "fail" : "pass");
```

## Left association

```cpp
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```

- If `grade` is greater than 90, the condition evaluates to `true`, and the left-most conditional operation would evaluate itself to `"high pass"`.
- This string literal `"high pass"` is then, used as the condition for the right-most conditional operator.
- Because, string literal `"high pass"` converts to the `bool` value `true`, the right-most conditional operation evalutes evaluates itself to `"fail"`.
- Therefore, if `grade` is greater than 90, `finalgrade` is `"fail"`.
- Otherwise, if `grade` is less than or equal to 90, the condition evalutes to `false`, and the left-most conditional operation evaluates itself to `(grade < 60)`.
- This comparison returns `1` or `0` depending on whether `grade` is less than 60 or not.
- Depending on the comparison's value, the right-most conditional operation would result in `"fail"` or `"pass"`.
- The problem can now be clearly seen, that the effect of the expression evaluation is not what is intended.