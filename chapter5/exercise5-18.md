# Exercise 5.18: Explain each of the following loops. Correct any problems you detect.

## Snippet a)

```cpp
do
	int v1, v2;
	cout << "Please enter two numbers to sum:" ;
	if (cin >> v1 >> v2)
		cout << "Sum is: " << v1 + v2 << endl;
while (cin);
```

**Explanation:** The intent is to ask user for two integers, read it, and print its sum. Then, check whether the `cin` state is valid; if it is, re-iterate, otherwise, terminate. However, since more than one statement needs to be executed in the body of `do`, but no curly braces are enclosing those compound statements; the compiler expects `while` before the statement which prompts using `cout`.

**Correction:** Enclose the body of `do` with curly braces to group those statements as block.

## Snippet b)

```cpp
do {
	// . . .
} while (int ival = get_response());
```

**Explanation:** The variable `ival` is defined inside the `while` condition, which is illegal. Only expressions are allowed inside `while` condition of `do`.

**Correction:** Define `ival` outside (before) the body of `do-while` loop.

## Snippet c)

```cpp
do {
	int ival = get_response();
} while (ival);
```

**Explanation:** The variable `ival` is defined in the scope of the body of `do`. It is hence, out of scope for the `while` condition.

**Correction:** Define `ival` or declare it outside (and before) the `do-while` loop.