# Exception handling and `try` blocks

Exceptions are run-time anomalies - such as losing connection to database or encountering unexpected input - that exist outside the normal functionality of a program. Dealing with anomalous behavior can be one of the most difficult parts of designing any system.

Exception handling is normally used when one part of a program detects a problem that it cannot resolve and problem is such that the detecting part of the program cannot continue. In such cases, detecting part needs to signal that something happened and that it cannot continue. The detecting part needs to signal the problem without knowing which part what part of the program will deal with the exceptional condition. Having signaled what happened, the detecting part stops processing.

A program that contain code that might raise an exception (usually) has another part to handle whatever happened. For example, if the problem is invalid input, the handling part might ask the user to provide correct input. If the database was lost, the handling part might alert an operator. Exception handling supports this cooperation between detecting and handling parts of the program. In C++, exception handling involves:

- `throw` expressions, which the detecting part uses to indicate that it encountered something it cannot handle. We can say that a throw raises an exception.
- `try` blocks, which the handling part uses to deal with an exception. A `try` block starts with the keyword `try` and ends with one or more `catch` clauses. Exceptions thrown from code executed inside a `try` block are usually handled by one of the `catch` clauses. Because, they handle the exception, `catch` clauses are also known as exception handlers.
- A set of exception classes that are used to pass information about what happened between a `throw` and an associated `catch`.

## A `throw` exception

The detecting part of the program uses a `throw` expression to raise an exception. A `throw` consists of the keyword `throw` followed by an expression. The type of the expression determines what kind of exception is thrown. A `throw` expression is usually followed by a semicolon, making it into an expression statement.