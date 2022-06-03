# Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal.

**Explain the behavior of the legal expressions and why those that aren’t legal are in error.**

```cpp
*iter++;
iter->empty();
(*iter)++;
++*iter;
*iter.empty()
iter++->empty();
```

## `*iter++`

**Validity:** Legal

**Explantion:** The expression yields the `string` pointed to by the iterator (as it currently is) and then increments the iterator `iter`.

## `iter->empty()`

**Validity:** Legal

**Explantion:** The expression calls the member function `empty()` on the `string` pointed to by `iter`.

## `(*iter)++`

**Validity:** Illegal

**Explantion:** The expression dereferences the `string` pointed to by the iterator `iter`, and increments it using the postfix increment operator. However, increment operators are not defined for `string` objects.

**Compiler message:** `error: no ‘operator++(int)’ declared for postfix ‘++’`

## `++*iter`

**Validity:** Illegal

**Explantion:** Since, the dereference and postfix increment operators have same precedence, but they both have right associativity, the dereference operation is performed first. The dereference yields the `string` pointed, and then tries to increment it, however, `++` operator is not defined for objects of type `string`.

**Compiler message:** `error: no match for ‘operator++’ (operand type is ‘std::__cxx11::basic_string<char>’)`

## `*iter.empty()`

**Validity:** Illegal

**Explantion:** Since, dot operator has a higher precedence than the dereference operator, the effect is to call the `empty()` function on iterator `iter`. However, the iterator of type `vector<string>::iterator` has no member named `empty()`.

**Compiler message:** `error: ‘using iterator = std::vector<std::__cxx11::basic_string<char> >::iterator’ {aka ‘std::vector<std::__cxx11::basic_string<char> >::iterator’} has no member named ‘empty'`

## `iter++->empty()`

**Validity:** Legal

**Explantion:** The arrow member access operator has higher precedence than the increment operator. Thus, the effect is to call the `empty()` function on the `string` object pointed to by the iterator `iter`, and then perform the postfix incrementation.