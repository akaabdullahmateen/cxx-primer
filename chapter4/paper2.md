## Assignment

If the left-hand operand is of built-in type, the initializer list may contain at most one value, and that value must not require a narrowing conversion. For class types, what happens depends on the details of the class. In the case of `vector`, the template defines its own version of an assignment operator that can take an initializer list. This operator replaces the elements of the left-hand side with the elements from the list in right-hand side.

Regardless of the type of the left-hand operand, the initializer list may be empty. In this case, the compiler generates a value-initialized temporary and assigns that value to the left-hand operand.

## Assignment is right associative

Unlike many binary operators, assignment is right associative:

```cpp
int ival, jval;
ival = jval = 0; // ok: each assigned to 0
```

Because assignment is right associative, the right-most assignment, `jval = 0`, is the right-hand operator of the left-most assignment operator. Because assignment returns its left-hand operand, the result of the right-most assignment is assigned to the left-most operand. (`ival = jval`);

Each object in a multiple assignment must have the same type as its right-hand neighbour or a type to which that neighbour can be converted:

```cpp
int ival, *pval;	// ival is an int, pval is a pointer to int
ival = pval = 0;	// error: cannot assign the value of a pointer to an int
string s1, s2;
s1 = s2 = "OK";		// string literal "OK" converted to string and assigned to both s1 and s2
```

The first assignment is illegal, because `ival` and `pval` have different types, and there is no conversion from the type of `pval` to the type of `ival`. It is illegal even though zero is a value that can be assigned to either object.

 On the other hand, the second assignment is legal. The string literal is converted to a `string`, and that `string` is assigned to `s2`. The result of that assignment is `s2`, which is then assigned to `s1`, and has the same type as `s1`.

 ## Assignment has low precedence

 Assignments often occur in conditions. Because assignments have relatively lower precedence, we usually must parentheszie the assignment for the condition to work properly. To see why assignment in a condition is useful, consider the following loop. We want to call a function until it returns the desired value - say 42:

 ```cpp
// a verbrose and therefore more error-prone way to write this loop
int i = get_value();	// get first value
while(i != 42){
	// do something
	i = get_value(); 	// get remaining values
}
```

Here we started by calling `get_value` followed by a loop whose condition uses the value returned by that call. The last statement in this loop makes another call to `get_value` and the loop repeats. We can write this code more directly as:

```cpp
int i;
while((i  = get_value()) != 42){
	// do something
}
```

The condition now more clearly expresses our intent: We want to continue until `get_value` returns 42. The condition executes by assigning the result returned by `get_value` to `i` and then compares the result of that assignment with 42.

Without parenthesis, the operands of the inequality operator `!=` would be the value returned from `get_value` call and 42. The `true` or `false` result of this test would be assigned to `i` by promoting them to `1` or `0` in `int` type - something we did not intend to do.

## Beware of confusing equality and assignment operators

The fact that we can use assignment in a condition can have surprising effects:

```cpp
if (i = j){
	// do something
}
```

The condition in this `if` statement assigns the value of `j` to `i`, and then tests the result of the assignment. If `j` is nonzero, the condition will be `true`. The author of this code almost surely intended to test whether `i` has the same value as `j`.

```cpp
// the correct condition
if(i == j){
	// do something
}
```

## Compound assignment operator

We often apply an operator to an object, and then assign the result back to the same object. As an example, consider the following sum program:

```cpp
int sum = 0;
// sum values from 1 through 10 (inclusive)
for(int i = 1; i <= 10; ++i){
	sum = sum + i; // short-hand equivalent would be: sum += i;
}
```

This kind of operation is not just common for the addition operator, but also for other arithmetic operators and the bitwise operators. There are compound assignments for each of these operators: `+=`, `-=`, `*=`, `/=`, `%=`, `<<=`, `>>=`, `&=`, `^=`, `|=`.

Each compound operator is essentially equivalent to: `a = a op b;` with the exception that, when we use the compound assignment, the left-hand operand is evaluated only once. If we use an ordinary assignment, that operand is evaluated twice: once in the expression on the right-hand side, and again as the operand on the left-hand side. In many, perhaps most, contexts this difference is immaterial aside from the possible performance consequences.