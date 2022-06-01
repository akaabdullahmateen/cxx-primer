# Exercise 3.33: What would happen if we did not initialize the `scores` array in the program on page 116?

```cpp
// count the number of grades by clusters of ten: 0--9, 10--19, . . . 90--99, 100
unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
unsigned grade;
while (cin >> grade) {
	if (grade <= 100)
		++scores[grade/10]; // increment the counter for the current cluster
}
```

If `scores` array was not value initialized, all eleven elements inside it will have undefined values. As a consequence, the result of incrementing these elements will be undefined. Therefore, the output of the program will be garbage.