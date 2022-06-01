## Exercise 1.12: What does the following for loop do? What is the final value of sum?

```
int sum = 0;
for (int i = -100; i <= 100; ++i)
	sum += i;
```

In the header of for loop, there are three expressions:

 - init-statement: `int i = -100`
 - condition: `i <= 100`
 - post-executation expression: `++i`

 This makes the loop run from iterator values from -100 to 100 (inclusive), incrementing on each iteration. The final value of the sum is the sum for all numbers from -100 to 100. Since, the variable type is signed integer, the sum is effectively zero.