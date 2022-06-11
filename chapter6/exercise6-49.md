# Exercise 6.49: What is a candidate function? What is a viable function?

A candidate function is a function with the same name as the called function and whose declaration is visible at the point of call.

A viable function is a function which has the same number of parameters as there are arguments in the call, and the type of each argument must match or be convertible to the type of its corresponding parameter. A viable function is one that can be legally called by the calling operator.

A best match is the function whose corresponding parameter is the best match for the given arguments. There is an overall best match if there is one and only one function for which:

- The match for each argument is no worse than the match required by any other viable function
- There is atleast one argument for which the match is better than the match provided by any other viable function

If there is no single function that is preferable, the call is in error. The compiler complains about ambiguous call.

Casts should not be needed to call an overloaded function. The need for a cast suggests that the parameter sets are designed poorly.