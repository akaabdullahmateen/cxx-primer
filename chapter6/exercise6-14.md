# Exercise 6.14: Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

- Since, passing by reference does not create a separate copy of the passed object, it can be useful when the passed object is a large class type, or a huge container.

- References are bound to the passed argument, so in case, argument itself needs to be modified, references are one safe way to do that. (The other being declaring parameter as pointers, but pointers are inheritently, dangerous to use and slight mistakes can cause fatal crash)

- Some types decay to other types, and therefore, to pass them exactly, requires the use of reference.

- However, primitive built-in type objects (`int`, `char`, `float`) are more efficient if passed by value than by reference, since compiler needs to handle meta information about references.