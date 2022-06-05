# Exercise 5.1: What is a null statement? When might you use a null statement?

A null statement is an empty statement. It is the simplest statement which has only a semi-colon:

```cpp
; // <- null statement
```

A null statement is useful when the language requires a statement but the program logic does not. Such usage is most common in the headers of `for` loops - when we do not need to write an init-declaration for the loop control variable, or do not need the post-iteration statement - or, in body of `for` and `while` loops - when we are only concerned in looping till a condition and do not need the loop's body.

```cpp
int i = 0; // this will be our loop control variable
for(; i < 10; ++i){ // we used null statement for the init-declaration of control variable
	cout << i << endl;
}
```

```cpp
while(cin >> n && n != target)
	; // we only need loop to continue asking user for input till target is found (or invalid input)
```