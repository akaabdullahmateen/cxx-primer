## Exercise 1.6: Explain whether the following program fragment is legal

**std::cout << "The sum of " << v1;
		  << " and " << v2;
		  << " is " << v1 + v2 << std::endl;**

If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?

## First statement

The first statement is legal, as it prints: The sum of *v1*

## Second statement

The second statement is **not** legal, as it begins with the output operator *<<* without any operand of type *ostream* on the left side.
The compiler, *G++ version 11.2.0*, complains with the following error message:

> error: expected primary-expression before "<<" token

## Third statement

Similarly, the third statement is also **not** legal, as it begins with the output operator *<<* without any operand of type *ostream* on the left side.
The compiler, *G++ version 11.2.0*, complains with the following error message:

> error: expected primary-expression before "<<" token