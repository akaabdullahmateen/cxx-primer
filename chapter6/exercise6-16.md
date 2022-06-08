# Exercise 6.16: The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:

```cpp
bool is_empty(string& s) {
	return s.empty();
}
```

Since, we are not modifying the value of `s`, it is recommended to be declared as reference to `const`, rather than being a plain reference. This is because, plain references cannot be initialized with string literals or expressions that evaluate with type `string`. Also, `const` qualified strings cannot be passed to this function.

```cpp
bool is_empty(const string& s) {
	return s.empty();
}
```