# Variables

A variable provides named storage that programs can manipulate. Each variable in C++ has a type. The type determines the size and layout of the variable's memory, the range of values that can be stored within the memory, and the set of operations that can be applied to the variable.

## Variable definitions

A simple variable definition consists of a type specifier, followed by a list of one ore more variable names separated by commas, and ends with a colon. Each name in the list has the type defined by the type specifier. A definition may optionally provide an initial value for one or more of the names it defines:

```cpp
int sum = 0, value, units_sold = 0; // sum, value, and units_sold have type int; sum and units_sold have an initial value 0
Sales_item item; // item has type Sales_item
std::string book("0-201-78345-X"); // book initialized from string literal; string is a library type, representing a variable-length sequence of characters 
```

The definition of `book` uses `std::string` library type. Like `iostream`, `string` is defined in namespace `std`. A string is a type that represents a variable-length sequence of characters. The `string` library provides several ways to initialize `string` objects. One of these ways is as a copy of a string literal. Thus, `book` is initialized to hold the character sequence "0-201-78345-X".

> Most generally, an object is a region of memory that can contain data and has a type. Some use the term *object* to refer to variables or values of class type. Others distinguish between named and unnamed objects, using the term *variable* to refer to named objects. Still others distinguish between objects and values, using the term *object* for data that can be changed by the program and the term *value* for data that are read-only.
> ~ C++ Primer 5th Edition

## Initializers

An object that is **initialized** gets the specified value at the moment it is created. The values used to initialize a variable can be arbitrarily complicated expressions. When a definition defines two or more variables, the name of each object becomes visible immediately. Thus, it is possible to initialize a variable to the value of one defined earlier in the same definition.

```cpp
// ok; price is defined and initialized before it is used to initialize discount
double price = 109.99, discount = price * 0.16;
// ok; call applyDiscount and use the return value to intialize salePrice
double salePrice = applyDiscount(price, discount)
```

It is tempting to think of initialization as a form of assignment, but initialization and assignment are different operations in C++. Initialization is not assignment. Initialization happens when a variable is given a value when it is created. Assignment obliterates an object's current value and replaces that value with a new one.

## List initialization

The language defines several different forms of initialization. For example, we can use any of the following four ways to define an `int` variable named `units_sold` and initialize it to `0`:

```cpp
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);
```

The generalized use of curly braces for initialization was introduced as part of the new standard. This form of initialization previously has been allowed only in more restricted ways. This form of initialization is known as **list initialization**. Braced lists of initializers can now be used whenever we initialize an object and in some cases when we assign a new value to an object.

When used with variables of built-in type, this form of initialization has one important property: The compiler does not allow list-initialization for variables of built-in types if the initialization might lead to the loss of information:

```cpp
long double ld = 3.1415926536;
int a{ld}, b = {ld}; // error: narrowing conversion required
int c(ld), d = ld; // ok; but value will be truncated
```

The compiler rejects the initialization of `a` and `b` because using a `long double` to initialize an `int` is likely to lose data. At a minimum, the fractional part of `ld` will be truncated. In addition, the integer part in `ld` might be too large to fit in an `int`.

## Default initialization

When a variable is defined without an initialization, the variable is default initialized. Such variables are given a *default* value. What exactly is the default value, depends on the type of the variable and may also depend on where the variable is defined.

The value of an object of built-in type that is not explicitly initialized depends on where it is defined. Variables defined outside any function body are initialized to zero. With one exception which will be covered later, variables of built-in type defined inside a function are uninitialized. The value of an uninitialized variable of built-in type is undefined. It is an error to copy or otherwise try to access the value of variable whose value is undefined.

Each class controls how we initialize objects of that class type. In particular, it is up to the class whether we can define objects of that type without an initializer. If we can, the class determines what values the resulting objects will have.

Most classes let us define objects without explicit initializers. Such classes supply an appropriate default value. For example, the library `string` class says that if we do not supply an initializer, then the resulting `string` is an empty string:

```cpp
std::string empty; // empty: implicitly initialized to the empty string
Sales_item item; // default-initialized Sales_item object
```

Some class require that every object be explicitly initialized. The compiler will complain if we try to create an object of such a class with no initializer.

> Uninitialzed objects of built-in type defined inside a function body have undefined value. Objects of class type that we do not explicitly initialize, have a value that is defined by the class
> ~ C++ Primer 5th Edition

## Variable declarations and definitions

To allow program to be written in logical parts, C++ supports separate compilation, which allows program to be split into several files, each of which can be compiled independently. However, this requires a way to share code across files. For example, code defined in one file may need to use a variable defined in another file. As a concrete example, consider `std::cout` and `std::cin`. These are objects defined somewhere in the standard library, yet out programs can use these objects. To support separate compilation, C++ distinguishes between declarations and definitions. A declaration makes a name known to the program. A file that wants to use a name defined elsewhere includes a declaration for that name. A definition creates the associated entry.

A variable declaration specifies the type and name of a variable. A variable definition is a declaration. In addition to specifying the name and type, a definition also allocates storage and may provide the variable with an initial value.

To obtain a declaration that is not also a definition, we add the `extern` keyword, and may not provide an explicit initializer:

```cpp
extern int i; // declares but does not define i
int j; // declares and defines j
```

Any declaration that includes an explicit initiazlizer is a definition. We can provide an initializer on a variable defined as `extern`, but doing so overrides the `extern`. An `extern` that has an initializer is a definition:

```cpp
extern double pi = 3.1416; // definition
```

It is an error to provide an initializer on an `extern` inside a function. Variables must be defined exactly once, but can be declared many times. To use a variable in more than one file requires declarations that are separate from the variable's definition. To use the same variable in multiple files, that variable must be defined in one and only one file. Other files that use that variable must declare but not define that variable.

## Uninitialized variables

An uninitialized variable has an indeterminate value. Trying to use the value of an uninitialized variable is an error, that is often hard to debug. Morever, the compiler is not required to detect such errors, although, most will warn about atleast some uses of uninitialized variables. What happens when we use an uninitialized variable is undefined. Sometimes, the program crashes as soon as the object is accessed. Other times, the program goes on to execute normally, but produces erroneous results. Even worse, the results may appear correct on some program runs, but fail on subsequent runs. Moreover, adding code to the program in an unrelated location can cause what we thought was a correct program to start producing correct results. It is therefore, recommended to initialize every object of built-in type. It is not always necessary, but it is easier and safer to provide an initializer until you can be certain it is safe to omit the initializer.

## Static typing

C++ is a *statically typed* language, which means that types are checked at compile time. The process by which types are checked is referred to as *type checking* - verifying and enforcing the constraints of types. The type of an object constraints the operations that the object can perform. Dynamically typed programming languages do type checking at run-time as opposed to compile-time. All scripting languages are dynamically typed, since there is no compiler to do compile-time type checking.

In C++, the compiler checks whether the operations we write are supported by the types we use. If we try tp do things that the type does not support, the compiler generates an error message, and does not produce an executable file. However, a consequence of static type checking is that the type of every entity must be known to the compiler - i.e., the type of the variable or object must be declared before using that variable in an expression or statement.

## Identifiers

Identifiers in C++ can be composed of letters, digits, and the underscore character. The language imposes no limit on name length. Indenitifiers must begin with either a letter or an underscore. Identifiers are case-sensitive; uppercase and lowercase letters are distinct:

```cpp
int somename, someName, SomeName, SOMENAME; // defines four different int variables
```

The language reserves a set of names as listed in table below, for its own use. These names, called keywords, can not be used as identifiers. The standard also reserves a set of names for use in the standard library. The identifiers we define in our own programs may not contain two consecutive underscores, nor can an identifier begin with an underscore followed immediately by an uppercase letter. In addition, identifiers defined outside a function may not begin with an underscore.

 - identifier:
 	- identifier-start
 	- identifier identifier-continue
 - identifier-start:
 	- nondigit
 	- an element of the translation character set of class XID_Start
 - idenitifer-continue:
 	- digit
 	- nondigit
 	- an element of the translation character set of class XID_Continue
 - nondigit: *one of*
 	- a b c d e f g h i j k l m<br>n o p q r s t u v w x y z<br>A B C D E F G H I J K L M<br>N O P Q R S T U V W X Y Z _
 - digit: *one of*
 	- 0 1 2 3 4 5 6 7 8 9

The character class XID_Start and XID_Continue are Derived Core Principles as described by UAX #44. The program is ill-formed if an identifier does not conform to Normalization Form C as specified in ISO / IEC 10646. The identifiers are case-sensitive. In addition, some identifiers are reserved for use by C++ implementations and shall not be used otherwise; no diagnostic is required:

 - Each identifier that contains a double underscore `__` or begins with an underscore followed by an uppercase letter is reserved to the implementation for any use.
 - Each identifier that begins with an underscore is reserved to the implementation for use as a name in the gloabl namespace.

|   			|   			| **Keywords** 	|   				|   		|
|---------------|---------------|---------------|-------------------|-----------|
| alignas		| continue		| friend		| register			| true 		|
| alignof		| decltype		| goto			| reinterpret_cast	| try 		|
| asm			| default		| if			| return			| typedef 	|
| auto			| delete		| inline		| short				| typeid 	|
| bool			| do			| int			| signed			| typename 	|
| break			| double		| long			| sizeof			| union 	|
| case			| dynamic_cast	| mutable		| static			| unsigned 	|
| catch			| else			| namespace		| static_assert		| using 	|
| char			| enum			| new			| static_cast		| virtual 	|
| char16_t		| explicit		| noexcept		| struct			| void 		|
| char32_t		| export		| nullptr		| switch			| volatile 	|
| class			| extern		| operator		| template			| wchar_t 	|
| const			| false			| private		| this				| while 	|
| constexpr		| float			| protected		| thread_local		|   		|
| const_cast	| for			| public		| throw				|   		|


***Alternative representative for operator names***

|			|			|			|			|			|			|
|-----------|-----------|-----------|-----------|-----------|-----------|
| and 		| bitand    | compl     | not_eq    | or_eq     | xor_eq	|
| and_eq    | bitor     | not       | or        | xor       |			|

## Conventions for variable names

There are a number of generally accepted conventions for naming variables. Following these conventions can improve the readability of a program:

 - An identifer should give some indication of its meaning.
 - Variable names are lowercase - for example, `index`, and not `Index` or `INDEX`.
 - Classes we define usually begin with an uppercase letter - for example, `Sales_item`
 - Identifiers with multiple words should visually distinguish each word, through camelCase or under_score styles.

## Scope of a name

At any particular point in a program, each name that is in use refers to a specific entity - a variable, function, type and so on. However, a given name can be reused to refer to different entities at different points in the program. A scope is a part of the program in which a name has a particular meaning. Most scopes in C++ are delimited by curly braces. The same name can refer to different entities in different scopes. Names are visible from the point where they are declared until the end of the scope in which the declaration appears. As an example, consider the following program:

```cpp
#include <iostream>

int main(){
	int sum = 0;
	// sum values from 1 through 10 inclusive
	for(int val = 1; val <= 10; ++val){
		sum += val; // equivalent to sum = sum + val
	}
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	return 0;
}
```

This program defines three names: `main`, `sum`, and `val`; and uses the namespace `std`, along with two names from that namespace: `cout` and `endl`. The name `main` - like most names defined outside a function - has global scope. Once, declared, names at the global scope are accessible throughout the program. The `sum` is defined within the scope of the block that is the body of the `main` function. It is accessible from its point of declaration throughout the rest of the `main` function, but not outside it. The variable `sum` has block scope. The name `val` is defined in the scope of the `for` statement. It can be used in that statement, but not elsewhere in `main`.

It is usually a good idea to define an object near the point at which the object is first used. Doing so improves readability by making it easy to find the definition of the variable. More importantly, it is often easier to give the variable a useful initial value when the variable is defined close to where it is first used.

## Nested scopes

Scopes can contain other scopes. The contained (nested) scope is referred to as an inner scope, the containing scope is the outer scope. Once a name has been declared in a scope, that name can by used by scopes nested inside that scope. Names declared in the outer scope can also be redefined in an inner scope:

```cpp
#include <iostream>
// Program for illustration purposes only: It is bad style for a function to use a global variable and also define a local variable with the same name
int reused = 42; // reused has global scope
int main(){
	int unique = 0; // unique has block scope
	// output#1: uses global reused; prints 42 0
	std::cout << reused << " " << unique << std::endl;
	int reused = 0; // new, local object named reused hides global reused
	// output#2: uses local reused; prins 0 0
	std::cout << reused << " " << unique << std::end;
	// output#3: explicitly requests the global reused; prints 42 0
	std::cout << ::reused << " " << unique << std::endl;
	return 0;
}
```

Output #1 appears before the local definition of `reused`. Therefore, this output statement uses the name `reused` defined in the global scope, and prints `42 0`. Output #2 occurs after the local definition of `reused`. The local `reused` is not in **scope**. Thus, the second output statement uses the local object named `reused` rather than the global one, and prints `0 0`. Output #3 uses the scope operator to override the default scoping rules. The global scope has no name. Hence, when the scope operator has an empty left-hand side, it is a request to fetch the name on the right-hand side from the global scope. Thus, the expression uses the global `reused` and prints `42 0`.

*As said before, it is almost always a bad idea to define a local variable with the same name as a global variable that the function uses or might use.*