# Exercise 3.26: In the binary search program on page 112, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) /2;`?

**Explanation:** Operator `+` is not defined for iterator operands. Difference operator `-` however, is defined - which evaluates with type `difference_type`. The compiler complains with the error message:

```
error: no match for ‘operator+’ (operand types are ‘__gnu_cxx::__normal_iterator<int*, std::vector<int> >’ and ‘__gnu_cxx::__normal_iterator<int*, std::vector<int> >’)
```