## Indicate which, if any, of the following output statements are legal

```
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

After you’ve predicted what will happen, test your answers by compiling a program
with each of these statements. Correct any errors you encounter.

### First and second statements

The first statement is legal, since the slash and asterisk is considered valid text inside a string

Similarly, the second statement is also legal, since the slash and asterisk is considered valid text inside a string

### Third and fourth statements

This statement is **not** legal, as it contains the string within a comment pair. Since, the compiler does not parse the inner contents of a comment, it thinks that the right hand operand of << operator is missing. To fix it, include the comment pair inside the quotation marks, like so.

```
std::cout << "/* */ */";
std::cout << "/* */ /* /* */";
```