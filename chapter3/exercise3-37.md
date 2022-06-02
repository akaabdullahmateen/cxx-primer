# Exercise 3.37: What does the following program do?

```cpp
// C-style character strings using array of const char
// note: there is no null terminator (0) at the end of initializer list
const char ca[] = {’h’, ’e’, ’l’, ’l’, ’o’};
// array ca decays to pointer to const char, which is defined as cp
const char *cp = ca;
// loop while the value pointed to by cp is 0 (or falsy)
// this will only occur when cp eventually points to the null terminator
// but there was no null terminator in the initializer list
// therefore, this loop continues dangerously to process addresses
// till it either finds a random 0 byte in memory
// or the program crashes due to buffer overflow or segmentation fault
while (*cp) {
	// print the value pointed to by cp to the standard output followed by a newline
	cout << *cp << endl;
	// increment the cp pointer to point to the next element
	// this dereferencing is undefined after cp hits off-the-end of the array
	++cp;
}
```