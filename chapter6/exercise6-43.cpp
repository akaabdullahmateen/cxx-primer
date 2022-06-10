// Exercise 6.43: Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.

// inline functions go in header files, because,
// they can be used in a lot of places
// compiler needs to find its definition - not just declaration
// putting its defination in each source file can cause mismatching definitions
// therefore, it is best to put them in header files

inline bool eq(const BigInt&, const BigInt&) {...}

// declarations of functions go in header files

void putValues(int *arr, int size);