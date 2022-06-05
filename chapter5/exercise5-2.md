# Exercise 5.2: What is a block? When might you might use a block?

A block is a compound statement. It is a (possibly empty) sequence of statements and declarations surrounded by a pair of curly braces:

```cpp
{
	/*statement-list*/
}
```

A block is not terminated by semi-colons. Semi-colons at the end of block are treated as null statements following the block. A block can be empty - it has no statements. An empty block is equivalent to null statement - though, more readable and hence less error-prone.

Compound statements or block, are used when language requires a single statement, but the program logic requires multiple. For example, the body of `for`, `while` loops, and `if` statements all must be a single statement. But rarely does one single statement suffice. Therefore, blocks are used in place of statements, by enclosing the list of statements in a curly braces.

A block is a scope. Since, block can contain both statements and declarations, names declared inside block are only accessible inside the block (and nested blocks) from the point of declaration till the end of the immediately enclosing block.