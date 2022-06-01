# Exercise 2.19: Explain the key differences between pointers and references.

 - Pointers are objects with an address and value, whereas references are not objects, they are merely aliases to the object they are bound to.
 - The object to which a pointer points can be changed many times, whereas, a reference can only remain bound to one object.
 - Pointers need not to be initialized at the time of definition / declaration, whereas, references must be initialized at the time of definition / declaration.
 - Pointers can have an invalid state - although trying to access the supposed object at this value will cause the program to misbehave - whereas, references can only point to valid objects.
 - Pointers can have null value: `nullptr`, `NULL`, `0`, whereas, references can not.