# Exercise 2.10: What are the initial values, if any, of each of the following variables?

```cpp
std::string global_str;
int global_int;

int main(){
	int local_int;
	std::string local_str;
}
```

| **variable** | **initial value** |
|--------------|-------------------|
| `global_str` | ""                |
| `global_int` | 0                 |
| `local_int`  | undefined         |
| `local_str`  | ""                |

## Explanation

`global` and `static` variables are stored in the Data Segment (DS) when initialized and block start by symbol (BSS) when uninitialized. These variables have a fixed memory location, and memory is allocated at compile time. Therefore, initializing them to a default value (numeric zero for `int`) does not incur a runtime cost.

Whereas, `auto` variables are stored on the stack, and thus, they do not have a fixed memory location. Memory is allocated to `auto` variables at runtime, therefore, `auto` variables have thier default value as garbage. This is because they can have different addresses for different calls and would have to be initialized at runtime each time the function is called, incurring a runtime cost that may not be needed.

The strings `global_int` and `local_str` are of class `std::string` type, and therefore, the `std::string` class controls the default initialization value for both of these variables regardless of where they are defined, which is an empty string.

The C++ 17 Standard Specification points out this behavior for default initialization:

 - If type *T* is a (possibly cv-qualified) class type, constructors are considered. The applicable constructors are enumerated and the best one for the initializer () is chosen through overload resolution. The constructor thus selected, is called with an empty argument list, to initialize the object.
 - If type *T* is an array type, each element is default-initialized.
 - Otherwise, no initialization is performed.

To zero-initialize an object or reference of type *T* means:

 - If *T* is a scalar type, the object is initialized to the value obtained by converting the integer literal 0 (zero) to *T*;
 - If *T* is a (possibly cv-qualifed) non-union class type, its padding bits are initialized to zero bits and each non-static data member, each non-virtual base class subobject, and if the object is not a base class subobject, each virtual base class subobject is zero-initialized;
 - If *T* is a (possibly cv-qualified) union type, its padding bits are initialized to zero bits, and the object's first non-static named data member is zero-initialized;
 - If *T* is an array type, each element is zero-initialized;
 - If *T* is a reference type, no initialization is performed.