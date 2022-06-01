# Defining our own data structures

At the most basic level, a data structure is a way to group together related data elements and a strategy for using those data. As one example, our `Sales_item` class groups an ISBN, a count of how many copies of that book had been sold, and the revenue associated with those sales. It also provides a set of operations such as `isbn` function and the `>>`, `<<`, `+`, and `+=` operators. In C++ we define our own data types by defining classes. The library types `string`, `istream`, and `ostream` are all defined as classes, as is `Sales_item` type. C++ support for classes is extensive.

## Defining the `Sales_data` type

Although we can't yet write our `Sales_item` class, we can write a more concrete class that groups the same data elements. Our strategy for using this class is that users will be able to access the data elements directly and must implement needed operations for themselves. Because our data structure does not support any operations, we'll name our version `Sales_data` to distinguish it from `Sales_item`. We will define our class as follows:

```cpp
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
```

Our class begins with the keyword `struct`, followed by the name of the class and a possibly empty class body. The class body is surrounded by curly braces and forms a new scope. The names defined inside the class must be unique within the class but can reuse names defined outside the class. The close curly bracket that ends the class body must be followed by a semicolon. The semicolon is needed because we can define variables after the class body:

```cpp
struct Sales_data{ /* ... */ } accum, trans, *salesptr;
// equivalent but better way to define these objects;
struct Sales_data{ /* ... */ };
Sales_data accum, trans, *salesptr;
```

The semicolon marks the end of the usually empty list of declarators. Ordinarily, it is a bad idea to define objects as part of a class definition. Doing so obscures the code by combining the definition of two different entities - the class and variables - in a single statement. Remember, it is often to easy to forget the semicolon at the end of a class definition.

## Class data members

The class body defines the members of the class. Our class has only data members. The data members of a class define the contents of the objects of that class type. Each object has its own copy of the class data members. Modifying the data members of one object does not change the data in any other `Sales_data` object. We define data members the same way we define normal variables: We specify a base type followed by a list of one or more declarators. Our class has three data members: a member of type `std::string` named `bookNo`, an `unsigned` (`unsigned` is alias for `unsigned int`) member names `units_sold`, and a member of type `double` named `revenue`. Each `Sales_data` object will have these three data members.

Under the new standard, we can supply an in-class initializer for data members. When we create objects, the in-class initializers will be used to initialize the data members. Members without an initializer are default-initialized. Thus, when we define `Sales_item` objects, `units_sold` and `revenue` will be initialized to `0`, and `bookNo` will be default-initialized to an empty string.

In-class initializers are restricted as to the form we can use: They must either be enclosed inside curly braces or follow an assignment operator `=` symbol. We may not specify an in-class initializer inside parentheses.

## Using the `Sales_data` class

Unlike `Sales_item` class, our `Sales_data` class does not provide any operators. Users of `Sales_data` have to write whatever operations they need.

## Adding two `Sales_data` objects

Because `Sales_data` provides no operations, we will have to write our own code to do the input, output, and addition operations. We will assume our `Sales_data` class is defined inside header file `Sales_data.h`. Our program needs to include the header `<string>`, because it needs to manage the `bookNo` member, which has type `string` defined in the `<string>` header.

```cpp
#include <iostream>
#include <string>
#include "Sales_data.h"

int main(){
	Sales_data data1, data2;
	// code to read into data1 and data2
	// code to check whether data1 and data2 have the same ISBN
	// and if so print the sum of data1 and data2
	return 0;
}
```

## Reading data into a `Sales_data` object

The `string` type holds a sequence of characters. Its operations include `<<`, `>>`, and `==` to write, read, and compare `string`s.

```cpp
double price = 0;		// price per book, used to calculate total revenue
// read the first transactions: ISBN, number of books sold, price per book
std::cin >> data1.bookNo >> data1.units_sold >> price;
// calculate total revenue from price and units_sold
data1.revenue = data1.units_sold * price;
```

Our transactions contain the price at which each book was sold but our data structure stores the total revenue. We read the transcation data into a `double` named `price`, from which the `revenue` data member is calculated. The program repeats the same code to read data into `data2`.

## Printing the sum of two `Sales_data` objects

Our other task is to check whether the transactions are for the same ISBN. If so, we will print their sum, otherwise, we will print an error message:

```cpp
if(data1.bookNo == data2.bookNo){
	unsigned totalCnt = data1.units_sold + data2.units_sold;
	double totalRevenue = data1.revenue + data2.revenue;
	// print: ISBN, total sold, total revenue, average price per book
	std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
	if(totalCnt != 0) std::cout << totalRevenue/totalCnt << std::endl;
	else std::cout << "(no sales)" << std::endl;
	return 0; // indicate success
}
else{ // transactions were not for the same ISBN
	std::cerr << "Data must refer to the same ISBN" << std::endl;
	return -1; // indicate failure
}
```

## Defining our own header files

Although we can define class inside a function, such classes have limited functionality. As a result, classes ordinarily are not defined inside functions. We can define a class outside of a function, there may be only one definition of that class in any given source file. In addition, if we use a class in several different files, the class' definition must be same in each file. In order to ensure that the class definition is the same in each file, classes are defined in header files. Typically, classes are stored in headers whose name derives from the name of the class.

Headers usually contain entities (such as class definitions and `const` and `constexpr` variables) that can be defined only once in any given file. However, headers often need to use facilities from other headers. For example, our `Sales_data` class has a `string` member, `Sales_data.h` must `#include` the `string` header. However, program that need to use `Sales_data` also need to include the `string` header in order to use the `bookNo` member. As a result, programs that use `Sales_data` will include `string` header twice: once directly and once as a side effect of including `Sales_data.h`. Because header might be included more than once, we need to write our headers in a way that is safe even if the header is included multiple times. Whenever a header is updated, the source file that use that header must be recompiled to get the new or changed declarations.

## A brief introduction to the preprocessor

The most common technique for making it safe to include a header multiple times relies on the **preprocessor**. The preprocessor - which C++ inherits from C - is a program that runs before the compiler and changes the source text of our programs. Our programs rely on the preprocessor facility, `#include` directive, already. When the preprocessor sees a `#include`, it replaces `#include` with the contents of the specified header.

C++ programs also use the preprocessor to define **header guards**. Header guards rely on preprocessor variables. Proprocessor variables have one of two possible states: defined or not defined. The `#define` directive takes a name and defines that name as a preprocessor variable. There are two other directives that test whether a given preprocessor variable has or has not been defined: `#ifdef` is `true` if the variable has been defined, and `#ifndef` is true if the variable has not been defined. If the test is true, then everything following the `#ifdef` or `#ifndef` is processed up to the matching `#endif`. We can use the facilities guard against multiple inclusions as follows:

```cpp
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

#endif
```

The first time `Sales_data.h` is included, the `#ifndef` test will succeed. The preprocessor will process the lines following `#ifndef` up to the `#endif`. As a result, the preprocessor variable `SALES_DATA_H` will be defined and the contents of `Sales_data.h` will be copied into our program. If we include `Sales_data.h` later on in the same file, the `#ifndef` directive will be false. The lines between it and the `#endif` will be ignored. Remember, preprocessor variable names do not respect C++ scoping rules. Preprocessor variables, including names of header guards, must be unique throughout the program. Typically, we ensure uniqueness by basing the guard's name on the name of a class in the header. To avoid name clashes with other entities in our program, preprocessor variables are usually written in all uppercase. Headers should include guards, even if they are not (yet) included by another header. Header guards are trivial to write, and by habitually defining them, you do not need to decide whether they are needed.