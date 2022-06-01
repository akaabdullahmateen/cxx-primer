## Pointers and arrays

In C++, pointers and arrays are closely intertwined. In particular, when we use an array, the compiler ordinarily converts the array to a pointer. Normally, we obtain a pointer to an object by using the address-of operator. Generally speaking, the address-of operator can be applied to any object. The elements in an array are objects. When we subscript an array, the result is the object at that location in the array. As with any other object, we can obtain a pointer to an array element by taking the address of that element:

```cpp
string nums[] = {"one", "two", "three"};    // array of strings
string *p = &nums[0];                      // p points to the first element in nums
```

However, arrays have special properties - in most places, when we use an array, the compiler automatically substitutes a pointer to the first element:

```cpp
string *p2 = nums; // equivalent to &nums[0]
```

*In most cases, when we use an object of array type, we are really using pointers to the first element in that array.*

There are various implications of the fact that operations on arrays are often really operations on pointers. One such implication is that when we use an array as an initializer for a variable defined using `auto`, the deduced type is a pointer, not an array:

```cpp
int ia[] {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
auto ia2(ia);                   // ia2 is an int* that points to the first element in ia
ia2 = 42;                       // error: ia2 is a pointer, and we cannot assign an int to a pointer
```

Although, `ia` is an array of ten `int`, when we use `ia` as an initializer, the compiler treats the initialization as if we had written:

```cpp
auto ia2(&ia[0]);   // now it's clear that ia2 has type int*
```

It is worth noting that this conversion does not happen when we use `decltype`. The type returned by `decltype(ia)` is an array of ten `int`:

```cpp
decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9};   // ia3 is an array of ten ints
ia3 = p;                                    // error: cannot assign an int* to an array
ia3[4] = i;                                 // ok: assigns the value of i to the fifth element in ia3
```

## Pointers are iterators

Pointers that address elements in an array have additional operations. In particular, pointers to array elements support same operations as iterators on `vector` and `string`. For example, we can use the increment operator to move from one element in an array to the next:

```cpp
int arr[] = {0,1,2,3,4,5,6,7,8,9};
int *p = arr;                       // points to the first element in arr
++p;                                // points to the second element in arr
```

Just as we can use iterators to traverse the elements in a `vector`, we can use pointers to traverse the elements in an array. Of course, to do so, we need to obtain the pointer to first element in an array, by using the array itself as initializer for the pointer, or by taking the address-of operator on the first element. We can take the address of non existent element one past the last element of an array:

```cpp
int *e = &arr[10]; // pointer just past the last element in arr
```

Here we used the subscript operator to index a nonexistent element; `arr` has ten elements, so the last element in `arr` is at index position 9. The only thing we can do with this element is take its address, which we do to initialize `e`. Like an off-the-end iterator, an off-the-end pointer does not point to an element. As a result, we may not dereference or increment an off-the-end pointer. Using pointers, we can write a loop to print the elements in `arr` as follows:

```cpp
for(int *p = arr; p != e; ++p){
    cout << *p << endl;
}
```

## The library `begin` and `end` functions

Although we can compute an off-the-end pointer, doing so is error-prone. To make it easier and safer to use pointers, the new library includes two functions, named `begin` and `end`. These functions act like the similarly named container members. However, arrays are not class type, so these functions are not member functions. Instead, they take an argument that is an array.

```cpp
int ia[] = {0,1,2,3,4,5,6,7,8,9};
int *beg = begin(ia);
int *end = end(ia);
```

`begin` returns a pointer to the first, and `end` returns the pointer one past the last element in the given array. These functions are defined in the `iterator` header. Using `begin` and `end`, it is easy to write a loop to process the elements in an array. For example, assuming `arr` is an array that holds `int` values, we might find the first negative value in `arr` as follows:

```cpp
int *pbegin = begin(arr);
int *end = end(arr);
while(pbegin != end && *pbegin >= 0){
    ++pbegin;
}
```

We start by defining two `int` pointers named `pbeging` and `pend`. We position `pbegin` to denote the first element and `pend` to point one past the last element in `arr`. The `while` condition uses `pend` to know whether it is safe to dereference `pbegin`. If `pbegin` does point at an element, we dereference and check whether the underlying element is negative. If so, the condition fails and we exit the loop. If not, we increment the pointer to look at the next element.

A pointer “one past” the end of a built-in array behaves the same way as the iterator returned by the end operation of a vector. In particular, we may not dereference or increment an off-the-end pointer.

## Pointer arithmetic

Pointers that address array elements can use all the iterator operations listed in tables earlier. These opeartions - dereference, incremenet, decrement, addition of an integral value, subtraction of two pointers - have the same meaning when applied to pointers that point at elements in a built-in array as they do when applied to iterators. When we add (or subtract) an integral value to (or from) a pointer, the result is a new pointer. That new pointer points to the element the given number ahead or behind the original value:

```cpp
constexpr size_t sz = 5;    // array dimension needs to be evaluated at compile-time
int arr[sz] = {1,2,3,4,5};  // array of five int
int *ip = arr;              // points to the first element in arr; &arr[0]
int *ip2 = ip + 4;          // points to the last element in arr; &arr[4]
```
    
The result of adding 4 to `ip` is a pointer that points to the element four elements further on in the array from the one to which `ip` points currently. The result of adding an integral value to a pointer must be a pointer to an element in the same array, or one past the last element in that array.

```cpp
int *p = arr + sz;  // ok: off-the-end pointer; use caution - do not dereference
int *p2 = arr + 10; // error: arr has only 5 elements, p2 has undefined value, and undefined behavior on dereferencing
```

When we add `sz` to `arr`, the compiler converts `arr` to a pointer to the first element in `arr`. When we add `sz` to that pointer, we get a pointer that points `sz` positions (i.e., 5 positions) past the first one. That is, it points one past the last element in `arr`. Computing a pointer more than one past the last element is an error, although the compiler is unlikely to detect such errors.

As with iterators, subtracting two pointers gives us the distance between those pointers. The pointers must point to elements in the same array:

```cpp
auto n = end(arr) - begin(arr); // n is 5, the number of elements in arr
```

The result of subtracting two pointers is a library type named `ptrdiff_t`. Like `size_t`, the `ptrdiff_t` type is a machine-specific type and is defined in the `cstddef` header. Because subtraction might yield a negative distance, `ptrdiff_t` is a signed integral type.

We can use the relational operators to compare pointers that point to elements of an array, or one past the last element in that array. For example, we can traverse the elements in `arr` as follows:

```cpp
int *b = arr, *e = arr + sz;
while (b < e) {
// use *b
++b;
}
```

We cannot use the relational operators on pointers to two unrelated objects:

```cpp
int i = 0, sz = 42;
int *p = &i, *e = &sz;
// undefined: p and e are unrelated; comparison is meaningless!
while (p < e)
```

Although the utility may be obscure at this point, it is worth noting that pointer arithmetic is also valid for null pointers (§ 2.3.2, p. 53) and for pointers that point to an object that is not an array. In the latter case, the pointers must point to the same object, or one past that object. If `p` is a null pointer, we can add or subtract an integral constant expression (§ 2.4.4, p. 65) whose value is 0 to `p`. We can also subtract two null pointers from one another, in which case the result is 0.


## Interaction between dereference and pointer arithmetic

The result of adding an integral value to a pointer is itself a pointer. Assuming the resulting pointer points to an element, we can dereference the resulting pointer:

```cpp
int ia[] = {0,2,4,6,8}; // array with 5 elements of type int
int last = *(ia + 4); 	// ok: initializes last to 8, the value of ia[4]
```

The expression `*(ia + 4)` calculates the address four elements past `ia` and dereferences the resulting pointer. This expression is equivalent to writing `ia[4]`. Recall that in § 3.4.1 (p. 109) we noted that parentheses are required in expressions that contain dereference and dot operators. Similarly, the parentheses around this pointer addition are essential. Writing:

```cpp
last = *ia + 4; // ok: last = 4, equivalent to ia[0] + 4
```

Means dereference `ia` and add 4 to the dereferenced value. We’ll cover the reasons for this behavior in § 4.1.2 (p. 136).

## Subscripts and pointers

As we’ve seen, in most places when we use the name of an array, we are really using a pointer to the first element in that array. One place where the compiler does this transformation is when we subscript an array. Given:

```cpp
int ia[] = {0,2,4,6,8}; // array with 5 elements of type int
```

If we write `ia[0]`, that is an expression that uses the name of an array. When we subscript an array, we are really subscripting a pointer to an element in that array:

```cpp
int i = ia[2];	// ia is converted to a pointer to the first element in ia
				// ia[2] fetches the element to which (ia + 2) points
int *p = ia;	// p points to the first element in ia
i = *(p + 2);	// equivalent to i = ia[2]
```

We can use the subscript operator on any pointer, as long as that pointer points to an element (or one past the last element) in an array:

```cpp
int *p = &ia[2];	// p points to the element indexed by 2
int j = p[1];		// p[1] is equivalent to *(p + 1),
					// p[1] is the same element as ia[3]
int k = p[-2];		// p[-2] is the same element as ia[0]
```

This last example points out an important difference between arrays and library types such as `vector` and `string` that have subscript operators. The library types force the index used with a subscript to be an unsigned value. The built-in subscript operator does not. The index used with the built-in subscript operator can be a negative value. Of course, the resulting address must point to an element in (or one past the end of) the array to which the original pointer points. Unlike subscripts for `vector` and `string`, the index of the built-in subscript operator is not an unsigned type.

## C-style character strings

Although C++ supports C-style strings, they should not be used by C++ programs. C-style strings are a surprisingly rich source of bugs and are the root cause of many security problems. They’re also harder to use!
