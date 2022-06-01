# Exercise 2.7: What do there literals represent? What type does each have?

## a) "Who goes with F\145rgus?\012"

**Type:** array of **n** `const char`
**Kind:** ordinary string literal
**Value:** *Who goes with Fergus?* (newline)

## b) 3.14e1L

**Type:** `long double`
**Kind:** extended-precision decimal floating-point literal expressed using fractional-part and exponent-part
**Value:** *31.4*

## c) 1024f

**Type:** `float`
**Kind:** single-precision decimal floating-point literal which is ill-formed; incomplete fractional-part without decimal point
**Value:** *Error: unable to find numeric literal operator ‘operator""f’* (1024.0 otherwise)

## d) 3.14L

**Type:** `long double`
**Kind:** extended-precision decimal floating-point literal
**Value:** *3.14*