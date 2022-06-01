# Exercise 2.5: Determine the type of each of the following literals.

**Explain the difference among the literals in each of the four examples**

## a) ’a’, L’a’, "a", L"a"

| **literal** | **Type**                     | **Kind**                   | **Note**                         |
|-------------|------------------------------|----------------------------|----------------------------------|
| 'a'         | `char`                       | ordinary character literal | only the character *a*           |
| L'a'        | `wchar_t`                    | wide character literal     | only the character *a*           |
| "a"         | array of *n* `const char`    | ordinary string literal    | character *a* and null character |
| L"a"        | array of *n* `const wchar_t` | wide string literal        | character *a* and null character |

## b) 10, 10u, 10L, 10uL, 012, 0xC

| **literal** | **Type**                     | **Kind**                              | **Note**                                        |
|-------------|------------------------------|---------------------------------------|-------------------------------------------------|
| 10          | `int`                        | signed decimal integer literal        | signed kind of the below                        |
| 10u         | `unsigned int`               | unsigned decimal integer literal      | unsigned kind of the above                      |
| 10L         | `long`                       | signed long decimal integer literal   | signed and long kind of the above               |
| 10uL        | `unsigned long`              | unsigned long decimal integer literal | unsigned kind of the above                      |
| 012         | `int`                        | signed octal integer literal          | signed, plain int, and octal kind of the above  |
| 0xC         | `int`                        | signed hexadecimal integer literal    | changed value and hexadecimal kind of the above |

## c) 3.14, 3.14f, 3.14L

| **literal** | **Type**                     | **Kind**                                  | **Note**                                    |
|-------------|------------------------------|-------------------------------------------|---------------------------------------------|
| 3.14        | `double`                     | double-precision floating-point literal   | default behavior to choose double precision |    
| 3.14f       | `float`                      | single-precsion floating-point literal    | single-precision kind of the above          |
| 3.14L       | `long double`                | extended-precision floating-point literal | extended-precision kind of the above        |

## d) 10, 10u, 10., 10e-2

| **literal** | **Type**                     | **Kind**                                        | **Note**                                             |
|-------------|------------------------------|-------------------------------------------------|------------------------------------------------------|
| 10          | `int`                        | signed decimal integer literal                  | signed kind of the below                             |
| 10u         | `unsigned int`               | unsigned decimal integer literal                | unsigned kind of the above                           |
| 10.         | `double`                     | double-precision decimal floating-point literal | decimal point at the end of fractional part is valid |
| 10e-2       | `double`                     | double-precision decimal floating-point literal | floating-point written using exponent part           |