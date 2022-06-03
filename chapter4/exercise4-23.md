# Exercise 4.23: The following expression fails to compile due to operator precedence.

**Using Table 4.12 (p. 166), explain why it fails. How would you fix it?**

```cpp
string s = "word";
string pl = s + s[s.size() - 1] == ’s’ ? "" : "s";

// Below are my personal deductions, not included in the question
//
// pl = s + s[s.size() - 1] == 's' ? "" : "s"
// pl = s + s[s.size() - 1] == 's' ? "" : "s"
// pl = (s + s[s.size() - 1]) == 's' ? "" : "s"
// pl = ((s + s[s.size() - 1]) == 's') ? "" : "s"
// pl = (((s + s[s.size() - 1]) == 's') ? "" : "s")
```

The operator precedence for the operators used in the second statement is described by the table below. *The entries lower down the table have lower precedence.*

| **Operator** | **Function** | **Associativity** |
|:------------:|:------------:|:-----------------:|
| `[]`         | subscript    | L                 |
| `+`          | addition     | L                 |
| `==`         | equality     | L                 |
| `?:`         | conditional  | R                 |
| `=`          | assignment   | R                 |

The statement therefore, groups as shown below:

```cpp
string pl = (((s + (s[s.size() - 1])) == 's') ? "" : "s")
```

- The subscript operator returns the last element in the string `s`.
- This character returned is added to string `s` itself, resulting in `"wordd`.
- This string `"wordd"` is compared for equality against the character `'s'`.
- The equality operator defined for `string` type takes both operands of type `string` (or those that can be converted to `string`).
- The character literal `'s'` has type `char`, and cannot be converted to `string` type.
- The compiler generates the error: `no match for ‘operator==’ (operand types are ‘std::__cxx11::basic_string<char>’ and ‘char’)`
- If somehow, this equality test was allowed, `"wordd"` is definitely not equal to `'s'`.
- Thus, the second expression from the conditional operator will be evaluated.
- This expression is `"s"`, which is returned as the result of the overall expression.
- `string` `pl` is initialized with the `string` literal `"s"`.

The intentions can be reasonably assumed to check whether the last character in the string `s` is `'s'`. If so, `pl` should be initialized with the concatentation of string `s` and an empty string; otherwise, `pl` should be the concatenation of string `s` and string literal `"s"`. The purpose is to add the string literal `"s"` if not already present at the end of the string `"s"`.

The correction would be to enclose the equality operation and the conditional operation inside parenthesis. The operator precedence now accounts for the fact that the right-hand operand of the addition operator must be evaluated before the string conactenation is done.

```cpp
string pl = s + (s[s.size() - 1] == ’s’ ? "" : "s");
```