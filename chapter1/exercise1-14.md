## Exercise 1.14: Compare and contrast the loops that used a for loop with those using a while loop

**Are there advantages or disadvantages to using either form?**


### Pragmatic

 - Use `for` loop when the number of iterations are well-known.
 - Use `while` loop when number of iterations are not known.

### Implications of using `continue` keyword in loops

 - In a `while` loop, `continue` will move the executation to the next iteration **without** incrementing the counter *if* the incrementing expression was written after the `continue` keyword.
 - Whereas, in `for` loop, the post-execution expression which usually contains the incremental expression is evaluated, when `continue` keyword is encountered anywhere in the loop block.

### Performace

Compiler translations of both `for` and `while` loop are almost equally efficient.