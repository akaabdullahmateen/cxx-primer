# Exercise 4.18: What would happen if the `while` loop on page 148 that prints the elements from a `vector` used the prefix increment operator?

```cpp
auto pbeg = v.begin();
// print elements up to the first negative value
while (pbeg != v.end() && *beg >= 0)
	cout << *pbeg++ << endl; // print the current value and advance pbeg
```

If prefix increment operator were used instead of the postfix operator, the effects would be disastrous. The pointer value will be incremented before the dereference operation is performed. Therefore, on the first iteration, the pointer would point to the second element, rather than the first, thus, skipping the first element. On the last iteration, the pointer will point to the element that will cause the condition to be evaluated `false`. This unallowed value of element will be printed on the last iteration. If the condition were to evaluate `false`, because of reaching the end of the `vector`, the prefix expression effectively tries to dereference an out-of-range element, whose results are undefined, and can cause the program to crash or print gibberish values.