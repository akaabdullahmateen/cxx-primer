# Exercise 2.14: Is the following program legal? If so, what values are printed?

```cpp
int i = 100, sum = 0;

for (int i = 0; i != 10; ++i)
sum += i;
std::cout << i << " " << sum << std::endl;
```

## Assumptions

 - Since, every program in C++ starts its executation from the `main` function, and `main` function is not defined, we assume the written inside the `main` function.
 - Also, the program uses the standard output stream `cout` from the standard namespace `std`, which is defined in the standard library, whose header `iostream`; but `#include <iostream>` is not included in the program. We therefore assume, that the said directive was added at the top of the program.

## Program execution

The complete program will look something like this following:

```cpp
#include <iostream>

int main(){
	int i = 100, sum = 0;

	for (int i = 0; i != 10; ++i)
	sum += i;
	std::cout << i << " " << sum << std::endl;

	return 0;
}
```

 - The first line statement inside the `main` function: `int i = 100, sum = 0` defines two local variables with block scope of `main function`: `i` and `sum`.
 - The second statement: `for(int i = 0; i != 10; ++i)` defines another definition for the name `i` which has the block scope of the `for` statement. In this nested scope of the `for` statement, their is name clash for `i`. The block scope `i` defined in the `for` statement takes precedence; hence, the initial value for `i` inside the `for` statement is `0`.
 - The third statement: `sum += i` is in the inner scope of the `for` statement - since, without curly braces the next statement after the for loop header is considered the body of the loop = and uses the `sum` name defined in the outer scope of `main` function, with an initial value of `0`. The variable name `i` is the `i` defined inside the `for` statement with an initial value of `0`. This statement is executed ten times, for `i` values: 0 1 2 3 4 5 6 7 8 9, compound assigning the result of addition to the variable `sum`.
 - The fourth statement: `std::cout << i << " " << sum << std::endl;` executes after the `for` loop terminates. The value of `sum` has been increased to `45`, however, the value of `i` is `100`; since, this statement is outside the scope of the `for` statement and uses the `i` name defined in the block scope of the `main` function - outside (before) the `for` statement.

**Validity:** Legal

**Output:** `100 45` (followed by a newline)