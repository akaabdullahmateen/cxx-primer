# Functions

A function is a block of code with a name. We execute the code by calling the function. A function may take zero or more arguments and usually yields a result. Functions can be overloaded, meaning the same name can refer to several different functions.

## Function basics

A function definition typically consists of a return type, a name, a list of zero or more parameters, and a body. The parameters are specified in a comma-separated list enclosed in parentheses. The actions that the functions performs are specified in a statement block, referred to as the function body.

We execute the function through the call operator, which is a pair of paretheses. The call operator takes an expression that is a function or points to a function. Inside the parenteses is a comma-separated list of arguments. The arguments are used to initialize the function's parameters. The type of a call expression is the return type of the function.

### Writing a function

As an example, we will write a function to determine the factorial of a given number. The factorial of a number `n` is the product of all numbers from 1 through `n`. The factorial of 5, for example, is 120.

```cpp
int fact(int val){
	int ret = 1;
	while(val > 1){
		ret *= val--;
	}
	return ret;
}
```

Our function is named `fact`. It takes one `int` parameter and returns an `int` value. Inside the `while` loop, we compute the factorial using the postfix decrement operator and compound multiplication-assignment. The `return` statement ends execution of `fact` and returns the value of `ret`.

### Calling a function

To call `fact`, we must supply an `int` value. The result of the call is also an `int`:

```cpp
int main(){
	int j = fact(5);
	cout << "5! = " << j << endl;
	return 0;
}
```

A function call does two things: It initializes the function's parameters from the corresponding arguments, and it transfers control to that function. Execution of the calling function is suspended and execution of the called function begins.

Execution of a function begins with the implicit definition and initialization of its parameters. Thus, when we call `fact`, the first thing that happens is that an `int` variable named `val` is created. This variable is initialized by the argument in the call to `fact`, which is 5.

Execution of a function ends with the `return` statement. Like a function call, the `return` statement does two things: It returns the value (if any) in the `return`, and it transfers control out of the called function back to the calling function. The value returned by the function is used to initialize the result of the call expression. Execution continues with whatever remains of the expression in which the call appeared. Thus, our `fact` call is equivalent to the following:

```cpp
int val = 5;
int ret = 1;
while(val > 1){
	ret *= val--;
}
int j = ret;
```

### Parameters and arguments

Arguments are the initializers for a function's parameters. The first argument initializes the first parameter, the second argument initializes the second parameter, and so on. Although, we know which argument initializes which argument, we have no guarantees about the order in which arguments are evaluated. The compiler is free to evaluate the arguments in whatever order it prefers.

The type of each argument must match the corresponding parameter in the same way that the type of initializer must match the type of object it initializes. We must pass exactly the same number of arguments as the functions parameters. Because every call is guaranteed to pass as many arguments as the function has parameters, parameters are always initialized.

Because `fact` has a single parameter of `int`, every time we call it we must supply a single argument that can be converted to `int`:

```cpp
fact("hello"); 		// error: wrong argument type
fact();				// error: too few arguments
fact(42, 10, 0);	// error: too many arguments
fact(3.14);			// ok: argument is converted to int
```

The first call fails because there is no conversion from `const char *` to `int`. The second and the third call passes wrong number of arguments. The `fact` function must be called with only one argument. The last call is legal because there is a conversion from `double` to `int`. In this case, the argument is implicitly converted to `int` (through truncation). After the conversion, this call is equivalent to:

```cpp
fact(3);
```

### Function parameter list

A function's parameter list can be empty but cannot be omitted. Typically, we define a function with no parameters by writing an empty parameter list. For compatibility with C, we can also use the keyword `void` to indicate that there are no parameters:

```cpp
void f1();
void f2(void);
```

A parameter list typically consists of a comma-separated list of parameters, each of which looks like a declaration with a single declarator. Even when the types of two parameters are the same, the type must be repeated:

```cpp
int f3(int v1, v2){ /* ... */ }    	// error
int f4(int v1, int v2){ /* ... */ } // ok
```

No parameters can have the same name. Moreover, local variables at the outermost scope of the function may not use the same name as any parameter. Parameter names are optional. However, there is no way to use an unnamed parameter. Therefore, parameters ordinarilly have names. Occasionally, a function has a parameter that is not used. Such parameters are left unnamed, to indicate that arenot used. Leaving a parameter unnamed does not change the number of arguments that a call must supply. A call must supply an argument for every parameter, even if that parameter is not used.

### Function return type

Most types can be used as the return type of a function. In particular, the return type can be `void`, which means that the function does not return any value. However, the return type may not be an array type or a function type. However, a function may return a pointer to an array or a function.

## Local objects

In C++, names have scopes, and objects have lifetime. It is important to understand both of these concepts:

- The scope of a name is the part of the program's text in which that name is visible
- The lifetime of an object is the time during the program's execution that the object exists

As we have seen, the body of a function is a statement block. As usual, the block forms a new scope in which we can define varibles. Parameters and variables defined inside a function body are referred to as local variables. They are local to that function and hide declarations of the same name made in an outer scope.