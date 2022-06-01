# Exercise 2.3: What output will the following code produce?

```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;

int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;

std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

## `std::cout << u2 - u << std::endl`

`u2 - u` evaluates to `42 - 10`, which is `32` and unsigned. Therefore, the standard output simply prints `32`

## `std::cout << u - u2 << std::endl`

`u - u2` evaluates to `10 - 42`, which is `-32`. However, since, the operands of this expression are unsigned, the expression itself must evaluate to an `unsigned int`. To achieve this, C++17 standard specifies that modulo operation be done with 2<sup>N</sup> where *N* is the width of the unsigned type. Since, on my machine, `unsigned int` has a width of 4 bytes = 32 bits. The result is 2<sup>32</sup> - 32 = 4,294,967,264

## `std::cout << i2 - i << std::endl`

`i2 - i` evaluates to `42 - 10`, which is `32`. Since, the expression operands are signed, the expression itself evaluates to be a `signed int`, therefore, standard output simple prints `32`

## `std::cout << i - i2 << std::endl`

`i - i2` evaluates to `10 - 42`, which is `-32`. Since, the expression operands are signed, the expression itself evaluates to be a `signed int`, and since `-32` is a valid `signed int` value, the standard output prints `-32`

## `std::cout << i - u << std::endl`

`i - u` evaluates to `10 - 10`, which is `0`. Since, one of the expression's operands is an `unsigned int`, the expression itself must promote to be an `unsigned int`. As, `0` is a valid `unsigned int`, the standard output, prints `0`

## `std::cout << u - i << std::endl`

`u - i` evaluates to `10 - 10`, which is `0`. Since, one of the expression's operands is an `unsigned int`, the expression itself must promote to be an `unsigned int`. As, `0` is a valid `unsigned int`, the standard output, prints `0`