# Exercise 4.26: In our grading example in this section, what would happen if we used `unsigned int` as the type for quiz1?

```cpp
unsigned long quiz1 = 0;
quiz1 |= 1UL << 27;
quiz1 &= ~(1UL << 27);
bool status = quiz1 & (1UL << 27);
```

`unsigned int` is guaranteed to have a width of 16 bits, whereas, `unsigned long` is guaranteed to have a width of 32 bits. Since, we need to track 30 students, 16 bit `unsigned int` cannot guarantee the portability of our program, even if `int` has widt of 32 bits on most (but ofcourse not all) systems.

In a system, where `int` has only 16 bits (the minimum guaranteed by the standard), the expression `1UL << 27` will result in all zeroes - since the set bit will be shifted off the left end and discarded. `quiz1 |= 1UL << 27` will effectively be `quiz1 |= 0`, which is basically `quiz1`, so that statement will achieve nothing. The second statement, `quiz1 &= ~(1UL << 27)` will effectively be `quiz1 &= ~(0)`, which is basically the same as `quiz1`, so this statement will also not achieve anything. The third expression `quiz1 & (1UL << 27)` will effectively be `quiz1 & 0`, which will result in `status` being `0` for every possibility. Thus the program logic is rendered meaningless.