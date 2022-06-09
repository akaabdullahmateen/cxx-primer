# Exercise 6.34: What would happen if the stopping condition in `factorial` were `if (val != 0)`

```cpp
int factorial(int val){
	if (val != 0)
		return factorial(val-1) * val;
	return 1;
}
```

The function `factorial` would still return the same value, but now it is slightly less efficient since, it multiplies by 1 as well - which is not necessary.