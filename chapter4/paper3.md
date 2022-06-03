# Increment and decrement operators

The increment (`++`), and decrement (`--`) operators provide a convenient notational shorthand for adding or subtracting 1 from an object. This notation rises above mere convenience when we use these operators with iterators, because many iterators do not support arithmetic.

There are two forms of these operators: prefix and postfix. So far, we have used only the prefix form. This form increments (or decrements) its operand and yields the changed object as its result. The postfix operators increment (or decrement) the operand but yield the copy of the original unchanged value as its result:

```cpp
int i = 0, j;
j = ++i;		// j = 1; i = 1
j = i++;		// j = 1; i = 2
```

These operators require the lvalue operand. The prefix operators return the object itself as an lvalue. The postfix operators return a copy of the object's original value as rvalue.

## Use postfix operators only when necessary

Readers from a C background might be surprised that we use the prefix increment in the programs we’ve written. The reason is simple: The prefix version avoids unnecessary work. It increments the value and returns the incremented version. The postfix operator must store the original value so that it can return the unincremented value as its result. If we don’t need the unincremented value, there’s no need for the extra work done by the postfix operator. For ints and pointers, the compiler can optimize away this extra work. For more complicated iterator types, this extra work potentially might be more costly. By habitually using the prefix versions, we do not have to worry about whether the performance difference matters. Moreover — and perhaps more importantly — we can express the intent of our programs more directly.

## Combining dereference and increment in a single expression

The postfix versions of `++` and `--` are used when we want to use the current value of a variable and increment it in a single compound expression. As an example, we can use the postfix increment operator to write a loop to print the values in a `vector` upto but not including the first negative value:

```cpp
auto *pbeg = vec.begin();
while(pbeg != vec.end() && *pbeg >= 0){
	cout << *pbeg++ << endl;
}
```

The precedence of the postfix increment operator is higher than the dereference operator, therefore, the `*pbeg++` is grouped as `*(pbeg++)`. The subexpression `pbeg++` increments `pbeg` and yields the copy of the previous (unmodified) value of `pbeg`. Accordingly, the dereference operator's operand is the unincremented value of `pbeg`. Thus, the statement prints the element to which `pbeg` originally pointed and increments `pbeg`.

This usage relies on the fact that postfix returns a copy of the original, unincremented operand. If it returned the incremented value, we' dereference the incremented value, with disastrous results. We had skipped the first element. Worse still, if the sequence had no negative values, we would be attempting to dereference an out-of-range element.

## Brevity can be virtue

Expressions such as `*pbeg++` can be bewildering at first. However, it is a useful and widely used idiom. Once the notation is familiar, writing:

```cpp
cout << *iter++ << endl;
```

is easier and less error-prone than the more verbrose equivalent:

```cpp
cout << *iter << endl;
++iter;
```

It is worthwhile to study examples of such code until their meanings are immediately clear. Most C++ programs use succinct expressions rather than more verbose equiva lents. Therefore, C++ programmers must be comfortable with such usages. Moreover, once these expressions are familiar, you will find them less error-prone.

## Remember that operands can be evaluated in any order

Most operators give no guarantee as to the order in which the operands will be evaluated. This lack of guaranteed order often does not matter. The case where it does matter are when one subexpression changes the value of an operand in another subexpression. Because the increment and decrement operators change their operand, it is easy to misuse theses operators in compound expressions.

To illustrate the problem, we’ll rewrite the loop from § 3.4.1 (p. 108) that capitalizes the first word in the input. That example used a `for` loop:

```cpp
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it){
	*it = toupper(*it);
}
```

Which allowed us to separate the statement that dereferenced `it` and the one that incremented it. Replacing the `for` loop with the seamingly equaivalent `while` loop:

```cpp
// the behavior of the following loop is undefined
while(beg != s.end() && !isspace(*beg)){
	*beg = toupper(*beg++); // error: this assignment is undefined, because it tries to modify a common operand when the order of evaluation is undefined
}
```

This results in an undefined behavior. The problem is that both the left and right hand operands use the object `beg`, which is modified in the right-hand side subexpression. There can be many interpretations, depending on the implementation: Either the left-hand side is evaluated first, in which case, reference to the element pointed to by `beg` is yielded on the left-hand side, and then, the right-hand side evaluates - first, increment the value of `beg` pointer to point to the next element, while returning the original (unmodified / pre-incremented) value of `beg` to yet again yield a reference to the element pointed to by `beg` by derefercing it, then finally, calling the free-standing library function `toupper` to assign the left-hand side operand (reference to the element pointed to by `beg` before incrementing) with the value of the uppercase equivalent; Or the right-hand subexpression can be evaluated first. Whereby, `beg` is incremented, but returns the unmodified value to this right-hand side subexpression. This pointer value is dereferenced and converted to uppercase equivalent. The left-hand side is then evaluated, but because the right-hand side incremented the value of `beg`, the dereference yields the next element, which is then assigned the value of the uppercase equivalent of the previous character - clearly, not what is intended. Since, either of the two possibilities can happen (or even something totally different), trying to modify a common operand in an expression results in undefined behavior, and the program is ill-formed.
