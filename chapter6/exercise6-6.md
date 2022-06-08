# Exercise 6.6: Explain the differences between a parameter, a local variable, and a local `static` variable. Give an example of a function in which each might be useful.

A parameter is an object created on function start, are initialized by corresponding argument passed to the function, are in scope through-out the execution of the function, and are destroyed when the function terminates.

A local variable is an object that is created inside the outermost scope of a function, or blocks within. They are created when the control flows through their definition, and are destroyed when the defining block is exited. Local variables of built-in types are called automatic variables, and they are in scope within its defining block, and have a lifetime similar to this block - they exist only while a block is executed.

Local `static` variables have scope limited to their defining block, but their lifetime continues across calls to the function. They are created and initialized (probably value-initialized) before the execution control passes through their definition, and are not destroyed until the program terminates.