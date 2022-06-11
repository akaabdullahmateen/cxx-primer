# Exercise 6.50: Given the declarations for f from page 242, list the viable functions, if any for each of the following calls.

**Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.**

```cpp
#include <iostream>

using std::cout;
using std::endl;

void f(){
	#ifndef NDEBUG
		cout << __PRETTY_FUNCTION__ << endl;
	#endif
	return;
}
void f(int){
	#ifndef NDEBUG
		cout << __PRETTY_FUNCTION__ << endl;
	#endif
	return;
}
void f(int, int){
	#ifndef NDEBUG
		cout << __PRETTY_FUNCTION__ << endl;
	#endif
	return;
}
void f(double, double = 3.14){
	#ifndef NDEBUG
		cout << __PRETTY_FUNCTION__ << endl;
	#endif
	return;
}

int main(){
	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);
	return 0;
}
```

## Candidate functions - those whose name matches and are visible at the point of call

```cpp
void f()
void f(int)
void f(int, int)
void f(double, double = 3.14)
```

## Viable functions - which can be legally called because parameter / argument matches or convertible

```cpp
 	f(2.56, 42)
   	f(int, int)
	f(double, double = 3.14)
```

```cpp
	f(42)
	f(int)
	f(double, double = 3.14)
```

```cpp
	f(42, 0)
	f(int, int)
	f(double, double = 3.14)
```

```cpp
	f(2.56, 3.14)
	f(int, int)
	f(double, double = 3.14)
```

## Best match - which provide atleast one argument / parameter match which is better and no worse match for other parameters than any other viable function
 
- *ambiguous call*
- `f(int)`
- `f(int, int)`
- `f(double, double)`