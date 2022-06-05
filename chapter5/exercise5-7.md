# Exercise 5.7: Correct the errors in each of the following code fragments

```cpp
if (ival1 != ival2)
	ival1 = ival2 // missing semi-colons
else ival1 = ival2 = 0;
```

```cpp
if (ival < minval)
	minval = ival;
	occurs = 1; // this statement runs unconditionally; should be enclosed in block
```

```cpp
if (int ival = get_value())
	cout << "ival = " << ival << endl;
if (!ival) // ival is out of scope
	cout << "ival = 0\n";
```

```cpp
if (ival = 0) // should have been equality operator instead of assignment
	ival = get_value();
```
