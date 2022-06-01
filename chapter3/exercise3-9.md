# What does the following program do? Is it valid? If not, why?

```cpp
string s;
cout << s[0] << endl;
```

## Subscript operator

```cpp
constexpr reference operator[](size_type pos);
```

Using subscript operator `[]` to access element from a string puts a precondition that `pos <= size()`. If  `pos < size()`, it returns `*(begin() + pos)`; otherwise it returns a reference to an object of type `charT` with value `charT()`, where modifying the object to any value other than `charT()` leads to undefined behavior. This operator, however, throws no exception.

## `at()` method

```cpp
constexpr reference at(size_type pos);
```

The `at()` method returns `operator[](pos)`, therefore, it is just a wrapper around the subscript operator. However, it does throw out-of-range exception if `pos >= size()`.

## Validity

Since, the string `s` is not explicitly initialized, it is default-initialized to an empty string. An empty string has `size()` equal zero. The index passed to the subscript operator in the code snippet qualifies for the condition: `pos <= size()`, therefore, the code snippet is legal. However, since `pos >= size()`, it returns a reference to an object of type `charT` - which is `char` for `std::string` - with value `charT` - which is undefined. Modifying this object to any value other than `charT()` leads to undefined behavior. Thereby, no exceptions are thrown.

## Implementation defined behavior

- The `charT` type object returned when accessing element at index `0` for an empty string is the null character. This is because Unix systems zero-initialize the BSS section. The code above therefore, prints the null character (with no visual representation) to the standard output.
- GCC 11.2.0 reserves considerable space in memory (16 zero-initialized bytes) for empty string. This is done to avoid frequent inefficient memory allocation. The `string` object is required to have the null terminator character. Therefore, trying to assign a value to `s[0]` other than `charT()`, will cause this null terminator character to be overwritten. 
- The string object has allocation of 16 bytes, which can be modified. But, to print these bytes need address locations which can be yielded through the subscript notation. Because of which, printing `s[0]` after modifying `s[0]` with some arbitrary character will cause it to be printed successfully to the standard output. This applies to indexes `0` through `15` (inclusive).
- However, assigning other indexes greater than `s.capacity()` will cause undefined behavior. But because, the string `s` is allocated on stack, the results would not be catastrophic for small indexes - as the future programs who will get assigned memory to these higher locations in stack will initialize and manage the memory on their own.

## Behavior for `at()` method

If the code snippet is modified to use the `at()` method for element access:

```cpp
string s;
cout << s.at(0) << endl;
```

The compiler will still not complain about any illegal access to out-of-range indices - as they are not required by the standard to do so. However, on execution the program will throw the following exception:

```bash
terminate called after throwing an instance of 'std::out_of_range'
  what():  basic_string::at: __n (which is 0) >= this->size() (which is 0)
[1]    XXXX IOT instruction (core dumped)  ./program_executable
```

This is the behavior specified by the C++17 Standard which requires `at()` method to throw exception for out-of-range access.