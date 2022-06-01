# Exercise 2.6: What, if any, are the differences between the following definitions:

```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

Decimal integer literals are not allowed to have zero as the first decimal digit in the sequence - it must be nonzero. Whereas, octal integer literals are identified using the zero as the first digit in the octal digit sequence.

Therefore, the first version initializes `month` to the decimal value `9`, and `day` to the decimal value `7`. However, in the second statement, `09` is identified as an octal literal, but `9` is not a valid octal digit, therefore, an error is raised. But, `day` is successfully intialized to the octal/digital value of `7`.