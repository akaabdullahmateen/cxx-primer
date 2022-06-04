# Exercise 4.32: Explain the following loop.

```cpp
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr){
	/* . . . */
}
```

- Object of type `int` with name `size` is init-defined as `constexpr` with integer literal `5` as initializer.
- Array with element type `int` is init-defined with size `size` (this is legal because `size` is `constexpr`, thus known at compile time).
- The array with name `ia` is list-initialized with five integer literals.
- Since, length of list matches the size of array, `ia` equals `{1, 2, 3, 4, 5}`
- In the `for` loop, the init-expression init-defines pointer to int, named `ptr` with the array `ia` as initializer.
- Since, arrays decay to pointers, this is legal. (`ptr` points to the first element in `ia`)
- This init-expression uses the comma operator to also assign the integer literal `0` to `ix`.
- Since, `ix` is not defined or declared in the code snippet, it is assumed to be of type `size_t`.
- The condition of the `for` loop checks if `ix` is not equal to `size` AND `ptr` is not equal to `ia + size`.
- The post-execution expression in the `for` loop uses comma operator to increment both `ix` and `ptr`.
- Thus, the `for` loop starts with pointer `ptr` pointing to the first element in array `ia`, and subscript index `ix` with value `0`.
- The condition checks that both `ptr` and `ix` are not referring to off-the-end of array.
- After each iteration, both `ix` and `ptr` are incremented.