# Exercise 6.28: In the second version of `error_msg` that has an `ErrCode` parameter, what is the type of `elem` in the `for` loop?

```cpp
void error_msg(ErrCode e, initializer_list<string> il){
	cout << e.msg() << ": ";
	for (const auto &elem : il)
		cout << elem << " " ;
	cout << endl;
}
```

`il` is an `initializer_list` with `string` elements declared as reference to `const` in the range `for` loop. Thus, the type of `elem` is `const string &`.