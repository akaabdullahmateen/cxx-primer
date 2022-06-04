# Exercise 4.38: Explain the following expression:

```cpp
double slope = static_cast<double>(j/i);
```

The explicit cast leverages the `static_cast` to convert the result of integer division of `j` and `i`. The `int` result is casted to type `double`, and used to initialize `slope` with type `double`. This expression achieves nothing with the explicit cast, since, compiler would have implicit casted `int` result to `double` for initialization as well.