# Compound types

A **compound type** is a type that is defined in terms of another type. C++ has several compound types, two of which - references and pointers - will be covered later. Generally, a declaration is a **base type** followed by a list of **declarators**. Each declarator names a variable and gives the variable a type that is related to the base type. More complicated declarators specify variables with compound types that are built from the base type of the declaration.

## References

> The new standard introduced a new kind of reference: an "rvalue reference". These references are primarily intended for use inside classes. Technically speaking, when we use the term *reference*, we mean "lvalue reference".
> ~ C++ Primer 5th Edition

A **reference** defines an alternate name for an object. A reference type "refers to" another type. We define a reference type by writing a declarator of the form `&d`, where `d` is the name being declared:

```cpp
int ival = 1024;
int &refVal = ival; // refVal refers to (is another name of) ival
int &refVal2; // error: a reference must be initialized
```

Ordinarily, when we initialize a variable, the value of the intializer is copied into the object we are creating. When we define a refernce, instead of copying the initializer's value, we **bind** the reference to its initializer. Once initialized, a reference remains bound to its initial object. There is no way to rebind a reference to refer to a different object. Because there is no way to rebind a reference, references must be initialized.

> A reference is not an object. Instead, a reference is just another name for an already existing object.
> ~ C++ Primer 5th Edition

After a reference has been defined, all operations on the reference are actually operations on the object to which the reference is bound:

```cpp
refVal = 2; // assigns 2 to the object to which refVal refers; i.e., to ival
int ii = refVal; // same as ii = ival
```

When we assign to a reference, we are assigning to the object to which the reference is bound. When we fetch the value of a reference, we are really fetching the value of the object to which the reference is bound. Similarily, when we use a reference as an initializer, we are really using the object to which the reference is bound:

```cpp
int &refVal3 = refVal; // ok; refVal3 is bound to the object to which refVal is bound, i.e., to ival
int i = refVal; // initializes i from the value of the object to which refVal is bound; ok: initializes i to the same value as ival
```

Because references are not objects, we may not define a reference to a reference.

## Reference definition

We can define multiple references in a single definition. Each identifier that is a reference must be preceded by the ampersand `&` symbol:

```cpp
int i = 1024, i2 = 2048; // i and i2 are both ints
int &r = i; r2 = i2; // r is a reference bound to i; r2 is an int
int i3 = 1024, &ri = i3; // i3 is an int; ri is a reference bound to i3
int &r3 = i3, &r4 = i2; // both r3 and r4 are references
```

With two exceptions that will be covered later, the type of reference and the object to which the reference refers must match exactly. Moreover, a reference may be bound only to an object, not to literal or the result of a more general expression:

```cpp
int &refVal4 = 10; // error: initializer must be an object
double dval = 3.14;
int &refVal5 = dval; // error: initializer must be an int object
```