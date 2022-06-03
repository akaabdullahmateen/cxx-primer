# The member access operators

The dot and arrow operators provide for member access. The dot operator fetches a member from an object of class type; arrow is defined so that `ptr->mem` is a synonym for `(*ptr).mem`:

```cpp
string s1 = "a string", *p = &s1;
auto n = s1.size();	// call the size member of the string s1
n = (*p).size();	// call size on the object to which p points
n = p->size();		// equivalent to (*p).size()
```

Because dereference has lower precedence than the dot operator, we must parenthesize the dereference subexpression. If we omit the parenthesis, this means to run the `size()` member function on the pointer `p`, and then dereference the result. However, the pointer `p` has no member function named `size()`, and the value returned by `size()` is of type `string::size_type` which should not be dereferenced.

The arrow operator requires a pointer operand and yields an lvalue. The dot operator yields an lvalue if the object from which the member is fetched is an lvalue; otherwise the result is an rvalue.