# Exercise 4.7: What does overflow mean? Show three expressions that will overflow.

## Definition

Integer overflow occurs when an arithmetic operation attempts to create a numeric value that is outside of the range that can be represented with a given integral type - either higher than the maximum representable value or lower than the minimum representable value.

The C++ standard states that for unsigned integral types, modulo wrapping is the defined behavior, and thereby, the term *overflow* never applies. For signed integral types, however, the behavior is undefined.

On most systems, the effect is incrementing bits that overflow to change the sign bit, and because data is stored in 2's complemenet, result in a large negative value.

## Examples

- Assuming `short` has size of 2 bytes on an implementation / machine, the maximum positive value representable will be `32767`. Attempt to increment this value further, will cause overflow:

```cpp
short i = 32767;	// ok: i = 32767
++i;				// overflow: i = -32768
```

- Assuming `int` has size of 4 bytes on an implementation / machine, the maximum positive value representable will be `2147483647`. Attempt to increment this value further, will cause overflow:

```cpp
int i = 2147483647;		// ok: i = 2147483647
++i;					// overflow: i = -2147483648
```

- Extreme value computation can result in expression evaluating to be overflowed. The compiler will complain with the warning message: `integer overflow in expression of type ‘long int’ results in ‘-5977608291240415834’`:

```cpp
cout << 6234567891234567891 + 6234567891234567891 << endl; // overflow: expression evaluation = -5977608291240415834
```
