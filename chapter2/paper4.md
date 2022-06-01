# Pointers

A **pointer** is a compound type that "points to" another type. Like references, pointers are used for indirect access to other objects. Unlike references, a pointer is an object in its own right. Pointers can be assigned and copied; a single pointer can point to several different objects over its lifetime. Unlike a reference, a pointer need not to be initialized at the time it is defined. Like other built-in types, pointers defined at block scope have undefined value if they are not initialized.

A pointer is defined by writing the declarator of the form `*d` where `d` is the identifier name being defined. The `*` must be repeated for each pointer variable:

```cpp
int *ip1, *ip2; 	// both ip1 and ip2 are pointers to int
double dp, *dp2; 	// dp2 is a pointer to double; dp is a double
```

## Taking the address of an object

A pointer holds the address of another object. To access the address of an object, the **address-of** operator (`&`) is used:

```cpp
int ival = 42;
int *p = &ival;		// p holds the address of ival; p is a pointer to ival
```

The second statement defines `p` as a pointer to `int` and initializes `p` to point to the `int` object named `ival`. Because references are not objects, they do not have addresses. Hence, we may not have a pointer to a reference. With two exceptions, the type of the pointer and the object which it points to must match:

```cpp
double dval;
double *pd = &dval; // ok: initializer is the address of a double
double *pd2 = pd; // ok: initializer is a pointer to double

int *pi = pd; // error: types of pi and pd differ
pi = &dval; // error: assigning address of a double to a pointer to int
```

The types must match because the type of the pointer is used to infer the type of the object to which the pointer points. If a pointer addressed an object of another type, operations performed on the underlying object would fail.

## Pointer value

The value (address) stored in a pointer can be in one of four states:

 - It can point to an object
 - It can point to the location just immediately past the end of an object
 - It can be a null pointer, indicating that it is not bound to any object
 - It can be invalid; values other than the preceding three are invalid

It is an error to copy or otherwise try to access the value of an invalid pointer. As when we use an uninitialized variable, this error is one that the compiler to unlikely to detect. The result of accessing an invalid pointer is undefined. Therefore, we must always know whether a pointer is valid. Although pointers in case 2 and 3 are valid, there are limits on what can be done with such pointers. Because these pointers do not point to any object, we may not use them to access the (supposed) object to which the pointer points. If we do attempt to access an object through such pointers, the behavior is undefined.

## Using pointers to access an object

When a pointer points to an object, we can use the dereference operator (`*`) to access that object:

```cpp
int ival = 42;
int *p = &ival; // p holds the address of ival; p is a pointer to ival
cout << *p; 	// yields the object to which p points; prints 42
```

Dereferecing the pointer yields the object to which the pointer points. We can assign to that object by assigning to the result of the dereference operator:

```cpp
*p = 0;			// * yields the object; we assign a new value to ival through p
cout << *p;		// prints 0
```

When we assign to `*p` we are assigning to the object to which `p` points. We may dereference only a valid pointer that points to an object.

## Some symbols have multiple meanings

Some symbols such as `&` and `*` are used both as an operator in an expression and as part of a declaration. The context in which a symbol is used determines what the symbol means:

```cpp
int i = 42;
int &r = i;		// & follows a type and is part of a declaration; r is a reference
int *p;			// * follows a type and is part of a declaration; p is a pointer
p = &i;			// & is used in an expression as the address-of operator
*p = i;			// * is used in an expression as the dereference operator
int &r2 = *p;	// & is part of a declaration; * is the deference operator
```

In declarations, `&` and `*` are used to form compound types. In expressions, theses same symbols are used to denote an operator. Because the same symbol is used with very different meanings, it can be helpful to ignore appearances and think of them as if they were different symbols.

## Null pointers

A **null pointer** does not point to any object. Code can check whether a pointer is null before attempting to use it. There are several ways to obtain a null pointer:

```cpp
int *p1 = nullptr; 		// equivalent to int *p1 = 0;
int *p2 = 0;			// directly initializes p2 from the literal constant 0
int *p3 = NULL;			// equivalent to int *p3 = 0; must #include <cstdlib>
```

The most direct approach is to initialize the pointer using the literal **nullptr**, which was introduced by the new standard. `nullptr` is a literal that has a special type that can be converted to any pointer type. Alternatively, we can initialize a pointer to literal 0, as we do in the definition of `p2`. Older programs sometimes use a preprocessor variable named `NULL`, which the `cstdlib` header defines as `0`. The preprocessor is a program that runs before the compiler. Preprocessor variables are managed by the preprocessor, and are not part of the `std` namespace. As a result, we refer to them directly without the `std::` prefix. When we use a preprocessor variable, the preprocessor automatically replaces the variable by its value. Hence, initializing a pointer to `NULL` is equivalent to initializing it to `0`. Modern C++ generally avoid using `NULL` and use `nullptr` instead. It is illegal to assign an `int` variable to a pointer, even if the variable's value happens to be `0`.

```cpp
int zero = 0;
pi = zero;			// error: can not assign an int to a pointer
```