# Exercise 2.13: What is the value of `j` in the following program?

```cpp
int i = 42;
int main(){
	int i = 100;
	int j = i;
}
```

Since, the name `i` is defined in both *global scope* and the *block scope* of the `main` function, inside the `main` function, the local name `i` has scope precedence. Therefore, the value of `i` when accessed elsewhere inside the `main` function from the point of definition of this local variable `i` till the end of block scope (indicated by closing curly brace `}`), is `100`.

The second definition is that for the local integer variable `j`, which is being initialized to the value of `i`. This statement resolves the value of `i` as `100`, and the statement, therefore, becomes: `int j = 100;`. This means, that the value of the local variable `j` will be `100` after this init-definition, till the end of the `main` function.