# String, Vectors, and Arrays

In addition to the built-in types, C++ defines a rich library of abstract data types. Among the most important library types are `string`, which support variable-length character strings, and `vector`, which support variable-size collections. Associated with `string` and `vector` are companion types known as iterators, which are used to access the characters of `string` or the element in a `vector`. The `string` and `vector` types defined by the library are abstractions of the more primitive built-in array type. The built-in types are defined directly by the C++ language. These types represent facilities present in most computer hardware, such as numbers or characters. The standard library defines a number of additional types of a higher-level nature that computer hardware usually does not implement directly.

A `string` is a variable-length sequence of characters. A `vector` holds a variable-length sequence of objects of given type. Like other built-in types, arrays represent facilities of the hardware. As a result, arrays are less convenient to use than the library `string` and `vector` types.

## Namespace `using` declarations

Up to now, our programs have explicitly indicated that each library name we use is in the `std` namespace. For example, to read from the standard input, we write `std::cin`. These names use the scope operator (`::`), which says that the compiler should look in the scope of the left-hand operand for the name of the right-hand operand. Thus, `std::cin` says that we want to use the name `cin` from the `std` namespace. Referring the library names in this notation is cumbersome. Fortunately, there are easier ways to use namespace members. The safest way is a `using` declaration. A `using` declaration let us use a name from a namespace without qualifying the name with a `namespace_name::` prefix. A `using` declaration has the form:

```cpp
using namespace::name;
```

Once the `using` declaration has been made, we can access `name` directly:

```cpp
#include <iostream>

// using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;

int main(){
	int i;
	cin >> i;				// ok: cin is a synonym for std::cin
	cout << i;				// error: no using declaration, we must explicitly qualify each cout name with the `std::` prefix
	std::cout << i;			// ok: explicitly use cout from the namespace std
	return 0;
}
```

### A separate `using` declaration is required for each name

Each `using` declaration introduces a single namespace member. This behavior lets us be specific about which names we are using. As an example:

```cpp
#include <iostream>

// using declarations for names from the standard library
using std::cin;
using std::cout;
using std::endl;

int main(){
	cout << "Enter two numbers:" << endl;
	int v1, v2;
	cin >> v1 >> v2;
	cout <<  "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;
	return 0;
}
```

The `using` declarations for `cin`, `cout`, `endl` mean that we can use those naems without the `std::` prefix. C++ programs are free-form so it is allowed to put each `using` declaration on its own line, or combine several onto a single line. The important part is that there must be a `using` declaration for each name we use, and each declaration must end in a semicolon.

### Headers should not include `using` namespace

Code inside headers ordinarily should not use `using` declarations. The reason is that the contents of a header are copied into the including program's text. If a header has some `using` declaration then every program that includes that header gets that same `using` declaration. As a result, a program that did not intend to use the specified library name might encounter unexpected name conflicts.

### A note to the reader

From this point on, our examples will assume that `using` declarations have been made for the names we use from the standard library. Thus, we will refer to `cin` not `std::cin`, in the text and in code examples. Moreover, to keep the code examples short, we won't show the `using` declarations, nor will we show the necessary `#include` directives.

## Library `string` type

A `string` is a variable-length sequence of characters. To use the `string` type, we must include the `string` header. Because it is part of the library, `string` is defined in the `std` namespace. In addition to specifying the operations that the library type provide, the standard also imposes efficiency requirements on implementors. As a result, library types are efficient enough for general use. Our examples assume the following code:

```cpp
#include <string>
using std::string;
```

## Defining and initializing `string`s

Each class defines how objects of its type can be initialized. A class may define many different ways to initialize objects of its type. Each way must be distinguished from the others by the numbers of initializers that we supply, or by the types of those initializers. Table below lists the ways to initialize a `string`.

| **Form**              | **Note**                                                          |
| --------------------- | ----------------------------------------------------------------- |
| `string s1`           | Default initialization, `s1` is the empty string                  |
| `string s2(s1)`       | `s2` is a copy of `s1`                                            |
| `string s2 = s1`      | Equivalent to `s2(s1)`, `s2` is a copy of `s1`                    |
| `string s3("value")`  | `s3` is a copy of the string literal, not including the null      |
| `string s3 = "value"` | Equivalent to `s3("value")`, `s3` is a copy of the string literal |
| `string s4(n, 'c')`   | Initialize `s4` with `n` copies of the character `'c'`            |

We can default initialize a `string`, which creates an empty `string`; that is `string` with no characters - but has the terminating null character (`0`). When we supply a string literal, the characters from that literal - upto but not including the null character at the end of the literal - are copied into the newly created `string`. When we supply a count and a character literal, the `string` contains that many copies of the given character.

### Direct and copy forms of initialization

When we initialize a variable using `=`, we are asking the compiler to **copy initialize** the object by copying the rvalue initializer into the object being created (lvalue). Otherwise when we emit the `=`, we use **direct initialization**. When we have a single initializer, we can use either the direct or copy form of initialization. When we initialize a variable from more than one value, such as the initialization of `s4` above, we must use the direct form of initialization:

```cpp
string s5 = "hiya"; // copy initialization
string s6("hiya");  // direct initialization
string s7(10, ’c’); // direct initialization; s7 is cccccccccc
```

When we want to use several values, we can indirectly use the copy form of initialization by explicitly creating a (temporary) object to copy:

```cpp
string s8 = string(10, 'c'); // copy initialization; s8 is cccccccccc
```

The initializer of `s8` - `string(10, 'c')` - creates a `string` of the given size and character value and then copies that value into `s8`. It is as if we had written:

```cpp
string temp(10, ’c’); 	// direct initialization; temp is cccccccccc
string s8 = temp;		// copy initialization; s8 is also cccccccccc
```

Although the code used to initialize `s8` is legal, it is less readable and offers no compensating advantage over the way we initialized `s7`.

### Operations on `string`s

Along with defining how objects are created and initialized, a class also defines the operations that objects of the class type can perform. A class can define operations that are called by name, such as `isbn` function of our `Sales_item` class. A class can also define what various operator symbols, such as `>>` or `+` mean when applied to objects of the class' type. Table overleaf below lists the most common `string` operations.

| **Operation**        | **Explanation**                                                                  |
| -------------------- | -------------------------------------------------------------------------------- |
| `os << s`            | Writes `s` onto output stream `os` and returns `os`                              |
| `is >> s`            | Reads whitespace-separated string from `is` into `s` and returns `is`            |
| `getline(is, s)`     | Reads a line of input from `is` into `s` and returns `is`                        |
| `s.empty()`          | Returns `true` if `s` is empty; otherwise returns `false`                        |
| `s.size()`           | Returns the number of characters in `s`                                          |
| `s[n]`               | Returns a reference to the `char` at position `n` in `s`; positions start at `0` |
| `s1 + s2`            | Returns a `string` that is the concatenation of `s1` and `s2`                    |
| `s1 = s2`            | Replaces characters in `s1` with copied characters from `s2`                     |
| `s1 == s2`           | The `string`s `s1` and `s2` are equal if they contain the same characters.       |
| `s1 != s2`           | Equivality is case-sensitive                                                     |
| `<`, `<=`, `>`, `>=` | Comparisons are case-sensitive and use dictionary ordering                       |

#### Reading and writing `string`s

We use the `iostream` library to read and write values of built-in types such as `int`, `double`, and so on. We use the same IO operators to read and write `string`s.

```cpp
// Note: #include and using declarations must be added to compile this code
int main(){
	string s; 				// empty string
	cin >> s;				// read a whitespace-separated string into s
	cout << s << endl;      // write s to the standard output
	return 0;
}
```

This program begins by defining an empty `string` named `s`. The next line reads the standard input, storing what is read in `s`. The `string` input operator reads and discards any leading whitespaces (e.g., spaces, newlines, tabs). It then reads characters until the next whitespace character is encountered. So if the input of this program is `Hello, World!` (note leading and trailing whitespaces), then the output will be `Hello,` with no extra spaces.

Like the input and output operations on the built-in types, the `string` operators return their left-hand operand as their result. Thus, we can chain together multiple reads or writes:

```cpp
string s1, s2;
cin >> s1 >> s2;			// read first input into s1, second into s2
cout << s1 << s2 << endl;	// write both strings
```

#### Reading an unknown number of `string`s

```cpp
int main(){
	string word;
	while(cin >> word){			// read until end-of-file
		cout << word << endl;	// write each word followed by a newline
	}
	return 0;
}
```

The condition tests the stream after the read completes. If the stream is valid - it has not hit the end-of-file or encountered an invalid input - then the body of the `while` loop is executed. The body prints the value we read on the standard output. Once we hit the end-of-file (or invalid input), we fall out of the `while` loop.

#### Using `getline` to read an entire line

Sometimes we do not want to ignore whitespace in our input. In such cases, we can use the `getline` function instead of the `>>` operator. The `getline` function takes an input stream and a `string`. This function reads the given stream up to and including the first newline and stores what it reads - not including the newline - in the `string` argument. After `getline` sees a newline, even if it is the first character in the input, it stops and returns. If the first character in the input is a newline, then the resulting `string` is the empty `string`.

Like the input operator, `getline` returns its `istream` argument. As a result, we can use `getline` as a condition just as we can use the input operator as a condition. For example, we can rewrite the previous program that wrote one word per line, to write a line at a time instead:

```cpp
int main(){
	string line;
	// read input a line at a time until end-of-file
	while(getline(cin, line)){
		cout << line << endl;
	}
	return 0;
}
```

Because `line` does not contain the newline, we must write our own, using `endl`. As usual, we use `endl` to end the current line and flush the buffer. The newline that causes `getline` to return is discarded; it is not stored in the `string`.

#### The `string` `empty` and `size` operations

The `empty` function does what one would expect: It returns `bool` indicating whether the `string` is empty. Like the `isbn` member of the `Sales_item`, `empty` is a member function of `string`. To call this function, we use the dot operator to specify the object on which we want to run the `empty` function. We can revise the previous program to only print lines that are not empty:

```cpp
int main(){
	string line;
	// read input, a line at a time, and discard empty lines
	while(getline(cin, line)){
		if(!line.empty()){
			cout << line << endl;
		}
	}
	return 0;
}
```

The condition uses the logical NOT operator (`!` symbol). This operators returns the inverse of `bool` value of its operand. In this case, the condition is `true` if `line` is not empty.

The `size` member returns the length of a `string` (i.e., the number of characters in it). We can use `size` to print only lines longer than 80 characters:

```cpp
while(getline(cin, line)){
	if(line.size() > 80){
		cout << line << endl;
	}
}
```

#### The `string::size_type` type

It might be logical to expect that `size` returns an `int` or, an `unsigned`. Instead, `size` returns `string::size_type` value. This type requires a bit of explanation. The `string` class - and most other library types - defines several companion types. These companion types make it possible to use the library types in a machine-independent manner. The type `size_type` is one of those companion types. To use the `size_type` defined by the `string`, we use the scope operator to say that the name `size_type` is defined in the `string` class.

Although, we do not know the precise type of `string::size_type`, we do know that it is an unsigned type, big enough to hold the size of any `string`. Any variable used to store the result from the `string` `size` operation should be of type `string::size_type`. Admittedly, it can be tedious to type `string::size_type`. Under the new standard, we can ask the compiler to provide the appropriate type by using the `auto` or `decltype` type deduction facilities:

```cpp
auto len = line.size(); // len has type string::size_type
```

Because `size` returns an unsigned type, it is essential to remember that expressions that mix signed and unsigned data can have surprising results. For example, if `n` is an `int` that holds a negative value, then `s.size() < n` will almost surely evaluate as `true`. It yields `true` because negative value in `n` will convert to a large unsigned value. You can avoid problems due to conversion between `unsigned` and `int` by not using `int`s in expressions that use `size()`.

#### Comparing `string`s

The `string` class defines several operators that compare `string`s. These operators work by comparing the characters of the `string`s. The comparisons are case-sensitive. The equality operators (`==` and `!=`) test whether two `string`s are equal or not. Two `string`s are equal if they are the same length and contain the same characters. The relational operators `<`, `<=`, `>`, `>=` test whether one `string` is less than, less than or equal to, greater than, or greater than or equal to another. These operators use the same strategy as a case-sensitive dictionary:

- If two `string`s have different lengths, and if every character in the shorter `string` is equal to the corresponding character of the longer `string`, then the shorter `string` is less than the longer one.
- If any character at corresponding positions in the two `string`s differ, then the result of the `string` comparison is the result of comparing the first character at which the `string`s differ.

As an example, consider the following `string`s:

```cpp
string str = "Hello";
string phrase = "Hello World";
string slang = "Hiya";
```

Using rule 1, we see that `str` is less than `phrase`. By applying rule 2, we that `slang` is greater than both `str` and `phrase`.

#### Assignment for `string`s

In general, the library types strive to make it as easy to use a library type as it is to use a built-in type. To this end, most of the library types support assignment. In case of `string`s, we can assign one `string` object to another:

```cpp
string st1(10, 'c'), st2; 	// st1 is cccccccccc; st2 is an empty string
st1 = st2;					// both st1 and st2 are now the empty string
```

#### Adding two `string`s

Adding two `string`s yield a new `string` that is the concatenation of the left-hand operand `string` followed by the right-hand operand. That is, when we use the plus operator (`+`) on `string`s, the result is a new `string` whose characters are a copy of those in the left-hand operand followed by those from the right-hand operand. The compound assignment operator (`+=`) appends the right-hand operand to the left-hand `string`:

```cpp
string s1 = "hello, ", s2 = "world\n";
string s3 = s1 + s2;					// s3 is "hello, world\n"
s1 += s2;								// s1 is "hello, world\n"; equivalent to s1 = s1 + s2
```

#### Adding literals and `string`s

We can use some type where another type is expected if there is a conversion from the given type to the expected type. The `string` library lets us convert both character literals and character string literals to `string`s. Because we can use these literals where a `string` is expected, we can rewrite the previous program as:

```cpp
string s1 = "hello", s2 = "world";
string s3 = s1 + ", " + s2 + '\n';
```

When we mix `string`s and string or character literals, atleast one operand to each `+` operator must be of `string` type.

```cpp
string s4 = s1 + ", ";				// ok: adding a string and a literal
string s5 = "hello" + ", ";			// error: no string operand
string s6 =  s1 + ", " + "world"; 	// ok: each + has a string operand
string s7 = "hello" + ", " + s2; 	// error: can't add string literals
```

The initializations of `s4` and `s5` involve only a single operation each, so it is easy to whether the initialization is legal. The initialization of `s6` may appear suprising, but it works in much the same way as when we chain together input or output expressions. Thus initialization groups as:

```cpp
string s6 = (s1 + ", ") + "world";
```

The subexpression `s1 + ", "` returns a `string`, which forms the left-hand operand of the second `+` operator. It is as if we had written:

```cpp
string tmp = s1 + ", ";			// ok: + has a string operand
string s6 = tmp + "world";		// ok: + has a string operand
```

On the other hand, the initialization of `s7` is illegal, which we can see if we parenthesized the expression:

```cpp
string s7 = ("hello" + ", ") + s2;		// error: cannot add string literals
```

Now it should be easy to see that the first subexpression adds two string literals. There is no way to do so, and therefore, the statement is ill-formed. For historical reasons, and for compatibility with C, string literals are not the standard library `string`s. It is important to remember that these types differ when you use string literals and library `string`s.

### Dealing with characters in a `string`

Often we need to deal with individual characters in a `string`. We might want to check whether a `string` contains any whitespaces, or to change the characters to lowercase, or to see whether a given character is present, and so on. One part of this kind of processing involves how we gain access to the characters themselves. Sometimes we need to process every character. Other times we need to process only specific character, or we can stop processing once some condition is met. It turns out that the best way to deal with these cases involves different language and library facilities. The other part of processing characters is knowing and/or changing the characteristics of a character. This part of the job is handled by a set of library functions, described in the overleaf table. These functions are defined in the `cctype` header.

| **Function**  | **Details**                                         |
| ------------- | --------------------------------------------------- |
| `isalnum(c)`  | `true` if `c` is a letter or a digit.               |
| `isalpha(c)`  | `true` if `c` is a letter.                          |
| `iscntrl(c)`  | `true` if `c` is a control character.               |
| `isdigit(c)`  | `true` if `c` is a digit.                           |
| `isgraph(c)`  | `true` if `c` is not a space but is printable.      |
| `islower(c)`  | `true` if `c` is a lowercase letter.                |
| `isprint(c)`  | `true` if `c` is a printable character.             |
| `ispunct(c)`  | `true` if `c` is a punctuation character.           |
| `isspace(c)`  | `true` if `c` is whitespace.                        |
| `isupper(c)`  | `true` if `c` is an uppercase letter.               |
| `isxdigit(c)` | `true` if `c` is a hexadecimal digit.               |
| `tolower(c)`  | Returns lowercase equivalent of `c` if not already. |
| `toupper(c)`  | Returns uppercase equivalent of `c` if not already. |

In addition to facilities defined specifically for C++, the C++ library incorporates the C library. Headers in C have names of the form `name.h`. The C++ versions of these headers are named `cname` - they remove the `.h` suffix and precede the _name_ with the letter `c`. The `c` indicates that the header is part of the C library. Hence, `cctype` has the same contents as `ctype.h`, but in a form that is appropriate for C++ programs. In particular, the names defined in the `cname` headers are defined inside the `std` namespace, whereas those defined in the `.h` versions are not. Ordinarily, C++ programs should use the `cname` versions of the headers and not the `name.h` versions. That way names from the standard library are consistently found in the `std` namespace. Using the `.h` headers puts the burden on the programmer to remember which library names are inherited from C and which are unique to C++.

#### Processing every character? Use range-based `for`

If we want to do something to every character in a `string`, by far the best approach is to use a statement introduced by the new standard: the **range** `for` statement. This statement iterates through the elements in a given sequence and performs some operations on each value in that sequence. The syntactical form is:

```cpp
for (declaration : expression)
	statement
```

where `expression` is an object of a type that represents a sequence, and `declaration` defines the variable that is used to access the underlying elements in the sequence. On each iteration, the variable in `declaration` is initialized from the value of the next element in `expression`. A `string` represents a sequence of characters, so it can be as the `expression` in a range `for`.

```cpp
string str("some string");
// for every char in str
for(auto c : str){
	cout << c << endl;
}
```

The `for` loop associates the variable `c` with `str`. We define the loop control variable the usual way. In this case, we use the `auto` keyword to let the compiler determine the type of `c` - which will be `char`. On each iteration, the next character in `str` will be copied into `c`. Thus, we can read this loop as: "for every character `c` in the string `str`", do something. The _something_ in this case is to print the character followed by a newline.

```cpp
string s("Hello World!!!");
decltype(s.size()) count = 0;
for(auto c : s){
	if(c.ispunct()) ++count;
}
cout << count << endl;
```

Here we use `decltype` to declare the counter `count`. Its type is the type returned by calling `s.size()`, which is `std::string::size_type`. We use a range `for` to process each character in the `string`. This time we check whether each character is a punctuation. If so, we use the increment operator to add `1` to the counter. When the range `for` loop completes, we print the counter.

_Important note: The postfix increment operator (`i++`) needs to create a temporary copy of itself, and return the temporary copy while incrementing the current object's value. Whereas, the prefix increment operator (`++i`) only increments itself and returns itself. As a result, prefix increment operator is, in most cases, more performant/faster than the postfix increment operator. Consider the following example:_

```cpp
Foo& Foo::operator++()   // called for ++i
{
    this->data += 1;
    return *this;
}

Foo Foo::operator++(int ignored_dummy_value)   // called for i++
{
    Foo tmp(*this);   // variable "tmp" cannot be optimized away by the compiler
    ++(*this);
    return tmp;
}
```

#### Using a range `for` to change the characters in a `string`

If we want to change the value of the characters in a `string`, we must the define the loop variable as a reference type. When we use a reference as our control variable, that variable is bound to each element in the sequence in turn. Using the reference, we can change the characters to which the reference is bound.

```cpp
string s("Hello World!!!");
for(char &c : s){
	c = toupper(c);
}
cout << s << endl;
```

On each iteration, `c` refers to the next character in `s`. When we assign to `c`, we are changing the underlying character in `s`. So when this loop completes, all the characters in `s` will be uppercase.

#### Processing only some characters

A range `for` works well when we need to process every character. However, sometimes we need to access only a single character or to access characters until some condition is reached. For example, we might want to capitalize only the first letter or the first word in `string`. There are two ways to access individual characters in a `string`: We can use a subscript or an iterator.

The subscript operator (`[]` operator) takes a `string::size_type` value that denotes the position of the character we want to access. The operator returns a reference to the character at the given position. Subscripts for `string`s start at zero; the last character is in `s[s.size() - 1]`. These subscript values must be in the range [0, `s.size()`). The result of using an out-of-range index is undefined. By implication, subscripting an empty string is undefined. The value in the subscript is referred to as the index (or even simply, subscript). The index we supply can be any expression that yields an integral value. However, if the index has a signed type, that value can be converted to the unsigned type that `string::size_type` represents. The following example uses the subscript operator to print the first character in a string:

```cpp
if(!s.empty()){
	cout << s[0] << endl;
}
```

Before accessing the character, we check that `s` is not an empty string. Any time we use a subscript we must ensure that there is a value at that location. If `s` is empty, `s[0]` is undefined. So as long as `string` is not `const`, we can assign a new value to the character that the subscript operator returns.

```cpp
string s("some string");
if(!s.empty()){
	s[0] = toupper(s[0]);
}
```

#### Using a subscript for iteration

As another example, we will change the first word in `s` to all uppercase:

```cpp
string s("some string");
for(decltype(s.size()) itr = 0; itr != s.size() && !isspace(s[itr]); ++itr){
	s[itr] = toupper(s[itr]);
}
```

The condition in the `for` statement uses the logical AND (`&&` operator) which yields `true` only if both the operands are `true` and `false` otherwise. The important part about this operator is that we are guaranted that it evaluates the right-hand operand only if the left-hand operand is `true`. It is therefore, safe to use the `itr` as index in subscript operator for `s` because it must be in range to be evaluated. Because, `itr` is never incremented beyond the value of `s.size()` (and never equal to `s.size()` itself), it is known that `itr` will always be less than `s.size()`.

One way to simplify code that uses the subscripts is to _always_ use an index variable of type `string::size_type`. Because that type is unsigned, we ensure that the subscript is cannot be less than zero. Therefore, all needed to be done is to check whether index is less than `str.size()`. The library is not required to check the value of subscript, so the result of out-of-range subscript is undefined.

#### Using a subscript for random access

As an example, let’s assume we have a number between 0 and 15 and we want to generate the hexadecimal representation of that number. We can do so using a `string` that is initialized to hold the 16 hexadecimal “digits”:

```cpp
const string hexdigits = "0123456789ABCDEF";
string result;
string::size_type n = 0;

cout << "Enter a series of numbers between 0 and 15 (inclusive)\n"
		"separated by spaces. Hit ENTER when finished" << endl;

while(cin >> n){
	if (n < hexdigits.size()){
		result += hexdigits[n];
	}
}

cout << "Your hex number is: " << result << endl;
```

We start by initializing `hexdigits` to hold the hexadecimal digits `0` through `F`. We make that `string` `const` because we do not want these values to change. Inside the loop we use the input value `n` to subscript `hexdigits`. The value of `hexdigits[n]` is the `char` that appears at position `n` in hexdigits. For example, if `n` is `15`, then the result is `F`; if it’s `12`, the result is `C`; and so on. We append that digit to `result`, which we print once we have read all the input. Whenever we use a subscript, we should think about how we know that it is in range. In this program, our subscript, `n`, is a `string::size_type`, which as we know is an unsigned type. As a result, we know that `n` is guaranteed to be greater than or equal to `0`. Before we use `n` to subscript `hexdigits`, we verify that it is less than the size of `hexdigits`.

## Library `vector` type

A `vector` is a collection of objects all of which have the same type. Every object in the collection has an associated index, which gives access to that object. A `vector` is often referred to as a **container** because it _contains_ other objects. To use a `vector`, the following include directive must be made: `#include <vector>`; and since, `vector` is provided by the standard library, it is defined in the `std` namespace: `std::vector`. A `vector` is a **class template**. C++ has both class and function templates.

Templates are not themselves functions or classes. Instead, they can be though of as instructions to the compiler for generating classes or functions. The process that the compiler uses to create classes or functions is called _instantiation_. When we use a template, we specify what kind of class or function we want the compiler to instantiate.

For a class template, we specify which class to instantiate by supplying additional information, the nature of which depends on the template. How we specify this information is always the same: We supply it inside a pair of angle brackets following the template's name. In the case of `vector`, the additional information is the type of the objects the `vector` can hold:

```cpp
std::vector<int> ivec;						// ivec holds objects of type int
std::vector<Sales_item> Sales_vec;			// holds Sales_item objects
std::vector<std::vector<std::string>> file;	// vector whose elements are vectors
```

`vector` is a template, not a type. Types generated from `vector` must include the element type, for example, `vector<int>`. We can define vectors to hold objects of almost any type. Because references are not objects, we cannot have vectors of references. However, we can have vectors of most other (non-reference) built-in types and most class types. In particular, we can have vectors whose elements are themselves vectors.

It is worth noting that earlier versions of C++ used a slightly different syntax to define a `vector` whose elements are themselves `vector` (or another template type). In the past, we had to supply a space between the closing angle bracket of the out `vector` and its element type - `vector<vector<int> >` rather than `vector<vector<int>>`. Some compilers may still require the old-style declarations for a vector of vectors.

### Defining and initializing `vector`

As with any class type, the `vector` template controls how we define and initialize `vector`. The table below lists the most common ways to define `vector`:

| **Declaration**         | **Note**                                          |
| ----------------------- | ------------------------------------------------- |
| `vector<T> v1`          | Empty `vector` that holds objects of type T.      |
| `vector<T> v2(v1)`      | `v2` has a copy of each element in `v1`           |
| `vector<T> v2 = v1`     | Equivalent to `v2(v1)`                            |
| `vector<T> v3(n, val)`  | `v3` has `n` elements of value `val`              |
| `vector<T> v4(n)`       | `v4` has `n` copies of a value-initialized object |
| `vector<T> v5 {a,b,c}`  | `v5` elements are corresponding initializers.     |
| `vector<T>v5 = {a,b,c}` | Equivalent to `v5{a,b,c}`                         |

We can default initialize a `vector` which creates an empty `vector` of the specified type:

```cpp
std::vector<std::string> svec; // default initialization; svec has no elements
```

It might seem that an empty vector would be of little use. However, we can efficiently add elements to a `vector` at runtime. Indeed, the most common way of using `vector` is to define an initially empty `vector` to which elements are added as their values become known at runtime.

We can also supply initial values for the elements when we define a `vector`. For example, we can copy elements from another `vector`. When we copy a `vector`, each element is the new `vector` is a copy of the corresponding element in the original `vector`. The two `vector`s however, must be the same type:

```cpp
vector<int> ivec;			// initially empty
vector<int> ivec2(ivec);	// copy elements of ivec into ivec2
vector<int> ivec3 = ivec;	// copy elements of ivec into ivec3
vector<string> svec(ivec2);	// error: svec holds string not int
```

#### List initializing a `vector`

Another way to provide element values, is that under the new standard, we can list initialize a `vector` from a list of zero or more initial element values enclosed in curly braces:

```cpp
vector<string> articles = {"a", "an", "the"};
```

The resulting `vector` `articles` has three elements: the first holds the `string` `"a"`, the second holds `"b"`, and the last is `"the"`.
