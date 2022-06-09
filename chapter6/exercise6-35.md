# Exercise 6.35: In the call to `factorial`, why did we pass `val - 1` rather than `val--`?

Since, multiplication operator does not define order of evaluation, any of the two operands: `factorial(val--)` or `val`, could be evaluated first. If `factorial(val--)` is evaluated first, the call stack would look like the following infinite stack:

```cpp
factorial(5) * 4;
factorial(5) * 4;
factorial(5) * 4;
factorial(5) * 4;
// ...
```

If however, `val` was evaluated first, the call stack would like the infinite stack below:

```cpp
factorial(5) * 5;
factorial(5) * 5;
factorial(5) * 5;
factorial(5) * 5;
// ...
```

In both these cases, we assumed we initially explicitly called `factorial(5)`. This is clearly not a desired behavior. It would keep recursively calling until the segmentation fault occurs - the program stack is exhausted.