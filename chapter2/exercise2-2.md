# Exercise 2.2: To calculate a mortgage payment, what types would you use for the rate, principal, and payment?

**Explain why you selected each type**

## Mortgage principal

The initial loan amount is referred to as the *mortgage principal*. Since, principal is amount in currency, and currency is non-fractional, it is best to use an integral type for mortgage principal - as floating-point numbers have rounding and truncation errorsm, due to precision loss. From, the integral types, we choose `unsigned long long`, since mortgage principal can not be negative, and `long long` is large enough to represent billions of dollars or cents. We avoid `unsigned int` because, although on modern machines, an `unsigned int` is 32 bit wide, C++ standard does guarantee only 16 bits - which can represent a maximum principal of $65,536 only. And because, `unsigned long` is often has the same width as an `unsigned int`, we do not use that either.


## Interest rate

The interest rate is essentially the fee that bank charges you to borrow money, expressed as a percentage. Because, interest rate is in percentage, we have to use floating-point numbers. Since, money is concerned we need to provide maximum precision without much performance cost. As such, we choose `double` (double-precision floating-point type; referred to as binary64 in IEEE 754 Floating Point Standard). `double` has 53 bits for precision (52 bits for trailing significand field), and 11 bits for exponent; making it capable of representing interest rates accurately. Because, interest rates are often small percentages, and floating-point numbers, in general, are precise of small real numbers in range: 0 .. 1; it makes perfect sense to use `double`.  

## Monthly payments

Monthly payment is the amount you return to the bank, which includes a portion of the mortgage principal, compounded with some interest rate. Similar, to mortgage principal, monthly payments are cash amount paid in currency money. Since, money can not be in percentages or fractions, nor can be negative, but needs to be large enough to represent huge payments for an expensive house, we choose `unsigned long long` to represent monthly payments.