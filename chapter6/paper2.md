## Reference returns are lvalues

Whether a function call is an lvalue depends on the return type of the function. Calls to functions that return references are lvalues; other return types yield rvalues. A call to a function that returns a reference can be used in the same ways as other lvalues. In particular, we can assign to the result of a function that returns a reference to non-`const`:

```cpp
char &get_val(string &str1, string::size_type ix){
	return str1[ix]; 		// assumes that the given index is valid
}
int main(){
	string s("a value");
	cout << s << endl; 		// prints "a value"
	get_val(s, 0) = 'A'; 	// changes s[0] to 'A'
	cout << s << endl; 		// prints "A value"
	return 0;
}
```

It may be surprising to see a function call on the left-hand side of an assignment. However, nothing is special. The return value is a reference, so the call yields an lvalue. Like any other lvalue, it may appear as the left-hand operand of an assignment operator. If the return type is a reference to `const`, then (as usual) we may not assign to the result of the call:

```cpp
shorterString("hi", "bye") = "X"; // error: return value is const
```

## List initializing the return value

Under the new standard, functions can return a braced list of values. As in any other return, the list is used to initialize a temporary at the call site - that represents the function's return. If the list is empty, that temporary is value initialized. Otherwise, the value of the return is depends on the function's return type.

As an example, recall the `error_msg` function. That function took a varying number of `string` arguments, and printed the error message composed from the given strings. Rather than calling `error_msg`, in this function we will return a `vector` that holds the error-message strings:

```cpp
vector<string> process(){
	// ...
	// expected and actual are strings
	if(expected.empty()){
		return {}; // return an empty vector
	}
	else if(expected == actual){
		return {"functionX", "okay"}; // return list-initialized vector
	}
	else {
		return {"functionX", expected, actual}; // return list-initialized vector
	}
}
```

In the first return statement, we return an empty list. In this case, the vector that `process` will return will be empty. Otherwise, we return a `vector` initialized with two or three elements depending on whether `expected` and `actual` are equal.

In a function that returns a built-in type (primitive), a braced list may contain at most one value, and that value must not require a narrowing conversion. If the function returns a class type, then the class itself defines how the initializers are used.

## Return from `main`

There is one exception to the rule that a function with a return type other than `void` must return a value: The `main` function is allowed to to terminate without a `return`. If control reaches the end of `main` and there is no explicit `return`, then the compiler implicitly inserts a return of 0.

The value returned from `main` is treated as a status indicator. A zero return indicates success; most other values indicate failure. A nonzero value has a machine-dependent meaning. To make return values machine independent, the `cstdlib` header defines two preprocessor variables that we can use to indicate success or failure:

```cpp
int main(){
	if (some_failure){
		return EXIT_FAILURE;
	}
	else{
		return EXIT_SUCCESS;
	}
}
```

Because these are preprocessor variables, we must not precede them with `std::`, nor may we mention them in `using` declarations.

## Recursion

A function that calls itself, either directly or indirectly, is a recursive function. As an example, we can write our factorial function to use recursion:

```cpp
int factorial(int val){
	if(val > 1){
		return factorial(val - 1) * val;
	}
	return 1;
}
```

In this implementation, we recursively call `factorial` to compute the factorial of the numbers counting down from the original value in `val`. Once, we have reduced `val` to 1, we stop the recursion by returning 1.

There must always be a path through a recursive function that does not involve a recursive call; otherwise, the function will recurse forever, meaning that the function will continue to call itself until the program stack is exhausted. Such, functions are sometimes described as containing a recursion loop. In the case of `factorial`, the stopping condition occurs when `val` is 1. The `main` function however, may not call itself.