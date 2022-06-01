# Literals

> The term "literal" generally designates, in this document, those tokens that are called "constants" in ISO C
> ~ C++ 17 Standard Specification

## Kind of literals

Thera are several kinds of literals:

 - integer-literal
 - character-literal
 - floating-point-literal
 - string-literal
 - boolean-literal
 - pointer-literal
 - user-defined-literal

## Integer literals

 - integer-literal:
 	- binary-literal integer-suffix<sub>opt</sub>
 	- octal-literal integer-suffix<sub>opt</sub>
 	- decimal-literal integer-suffix<sub>opt</sub>
 	- hexadecimal-literal integer-suffix<sub>opt</sub>
 - binary-literal:
 	- 0b binary-digit
 	- 0B binary-digit
 	- binary-literal' <sub>opt</sub> binary digit
 - octal-literal:
 	- 0
 	- octal-literal' <sub>opt</sub> octal-digit
 - decimal-literal:
 	- nonzero-digit
 	- decimal-literal' <sub>opt</sub> digit
 - hexadecimal-literal:
 	- hexadecimal-prefix hexadecimal-digit-sequence
 - binary-digit: *one of*
 	- 0 1
 - octal-digit: *one of*
 	- 0 1 2 3 4 5 6 7
 - nonzero-digit: *one of*
 	- 1 2 3 4 5 6 7 8 9
 - hexadecimal-prefix: *one of*
 	- 0x 0X
 - hexadecimal-digit-sequence:
 	- hexadecimal-digit
 	- hexadecimal-digit-sequence' <sub>opt</sub> hexadecimal-digit
 - hexadecimal-digit: *one of*
 	- 0 1 2 3 4 5 6 7 8 9
 	- a b c d e f
 	- A B C D E F
 - integer-suffix:
 	- unsigned-suffix long-suffix<sub>opt</sub>
 	- unsigned-suffix long-long-suffix<sub>opt</sub>
 	- unsigned-suffix size-suffix<sub>opt</sub>
 	- long-suffix unsigned-suffix<sub>opt</sub>
 	- long-long-suffix unsigned-suffix<sub>opt</sub>
 	- size-suffix unsigned-suffix<sub>opt</sub>
 - unsigned-suffix: *one of*
 	- u U
 - long-suffix: *one of*
 	- l L
 - long-long-suffix: *one of*
 	- ll LL
 - size-suffix: *one-of*
 	- z Z

In an integer literal, the sequence of binary-digits, octal-digits, digits, or hexadecimal-digits is interpreted as a base N integer as shown in table below; the lexically first digit of the sequence of digits is the most significant.

| **Kind of integer-literal** | **base N** |
|-----------------------------|-----------:|
| binary-literal              | 2          |
| octal-literal               | 8          |
| decimal-literal             | 10         |
| hexadecimal-literal         | 16         |

The hexadecimal-digits *a* through *f* and *A* through *F* have decimal values ten through fifteen.

*Example 1: The number twelve can be written 0b1100, 014, 12, or 0xC. The integer-literals 1048576, 1'048'576, 0x100000, 0x10'0000, and 0'004'000'000 all have the same value.*

The type of an integer-literal is the first type in the list in the table below; corresponding to its optional integer-suffix in which its value can be represented. An integer literal is a prvalue (pure rvalue, also, pure right-hand-side value).

| **integer-suffix**                  | **decimal-literal**                                               | **integer-literal other than decimal-literal** |
|-------------------------------------|-------------------------------------------------------------------|------------------------------------------------|
| none                                | `int`<br>`long int`<br>`long long int`                            | `int`<br>`unsigned int`<br>`long int`<br>`unsigned long int`<br>`long long int`<br>`unsigned long long int` |
| *u* or *U*                          | `unsigned int`<br>`unsigned long int`<br>`unsigned long long int` | `unsigned int`<br>`unsigned long int`<br>`unsigned long long int`
| *l* or *L*                          | `long int`<br>`long long int`                                     | `long int`<br>`unsigned long int`<br>`long long int`<br>`unsigned long long int` |
| Both *u* or *U*<br>and *l* or *L*   | `unsigned long int`<br>`unsigned long long int`                   | `unsigned long int`<br>`unsigned long long int` |
| *ll* or *LL*                        | `long long int`                                                   | `long long int<br>unsigned long long int`       |
| Both *u* or *U*<br>and *ll* or *LL* | `unsigned long long int`                                          | `unsigned long long int`                        |
| *z* or *Z*                          | `signed std::size_t`                                              | `signed std::size_t`<br>`std::size_t`           |
| Both *u* or *U* and *z* or *Z*      | `std::size_t`                                                     | `std::size_t`                                   |

If an integer-literal cannot be represented by any type in its list and an extended integer type (such as `__int128`) can represent its value, it may have that extended integer type. If all of the types in the list for the integer-literal are signed, the extended integer type shall be signed. If all the types in the list for the integer-literal are unsigned, the extended integer type shall be unsigned. If the list contains both signed and unsigned types, the extended integer type may be signed or unsigned. A program is ill-formed if one of its translation units contains an integer-literal that can not be represented by any of the allowed types.

> Integer literals has the smallest type of its list (the first type in its list) in which the literal's value fits
> ~ C++ Primer 5th Edition

> There are no literals of type `short`
> ~ C++ Primer 5th Edition

> Although, integer literals may be stored in signed types, technically speaking, the value of a decimal literal is never a negative value. The minus sign is the unary negation operator that negates the value of its (literal) operand.
> ~ C++ Primer 5th Edition

## Floating-point literals

 - floating-point-literal:
 	- decimal-floating-point-literal
 	- hexadecimal-floating-point-literal
 - decimal-floating-point-literal:
 	- fractional-constant exponent-part<sub>opt</sub> floating-point-suffix<sub>opt</sub>
 	- digit-sequence exponent-part floating-point-suffix<sub>opt</sub>
 - hexadecimal-floating-point-literal:
 	- hexadecimal-prefix hexadecimal-fractional-constant binary-exponent-part floating-point-suffix<sub>opt</sub>
 	- hexadecimal-prefix hexadecimal-digit-sequence binary-exponent-part floating-point-suffix<sub>opt</sub>
 - fractional-constant:
 	- digit-sequence<sub>opt</sub> . digit-sequence
 	- digit-sequence .
 - hexadecimal-fractional-constant:
 	- hexadecimal-digit-sequence<sub>opt</sub> . hexadecimal-digit-sequence
 	- hexadecimal-digit-sequence .
 - exponent-part:
 	- e sign<sub>opt</sub> digit-sequence
 	- E sign<sub>opt</sub> digit-sequence
 - binary-exponent-part:
 	- p sign<sub>opt</sub> digit-sequence
 	- P sign<sub>opt</sub> digit-sequence
 - sign: *one of*
 	- + -
 - digit-sequence:
 	- digit
 	- digit-sequence' <sub>opt</sub> digit
 - floating-point-suffix: *one of*
 	- f l F L

The type of floating-point-literal is determined by its floating-point-suffix as specified in the table belew:

| **floating-point-suffix** | **type**      |
|---------------------------|---------------|
| none                      | `double`      |
| *f* or *F*                | `float`       |
| *l* or *L*                | `long double` |

The significand of the floating-point-literal is the fractional-constant or digit-sequence of a decimal-floating-point-literal or the hexadecimal-fractional-constant or hexadecimal-digit-sequence of a hexadecimal-floating-point-literal. In the significand, the sequence of digits or hexadecimal-digits and optional period are interpreted as base N real number *s*, where N is 10 for decimal-floating-point-literal and 16 for hexadecimal-floating-point-literal.

If an exponent-part of binary-exponent-part is present, the exponent *e* of the floating-point-literal is the result of interpreting the sequence of an optional sign and the digits as a base 10 integer. Otherwise the exponent is 0. The scaled value of the literal is s x 10<sup>e</sup> for a decimal-floating-point-literal and s x 2<sup>e</sup> for a hexadecimal-floating-point-literal.

*Example 1: The floating-point-literals 49.625 and 0xC.68p+2 have the same value. The floating-point-literals 1.602’176’565e-19 and 1.602176565e-19 have the same value.*

If the scaled value is not in the range of representable value of its type, the program is ill-formed. Otherwise, the value of a floating-point-literal is the scaled-value if representable, else the larger or smaller representable value nearest the scaled value, chosen in an implementation-defined manner.

> By default, floating-point-literals have type `double`. We can override the default using a suffix from the table above.
> ~ C++ Primer 5th Edition

## Character literals

 - character-literal:
 	- encoding-prefix<sub>opt</sub> ' c-char-sequence '
 - encoding-prefix: *one of*
 	- u8 u U L
 - c-char-sequence:
 	- c-char
 	- c-char-sequence c-char
 - c-char:
 	- basic-c-char
 	- escape-sequence
 	- universal-character-name
 - basic-c-char:
 	- *any member of the translation character set except the U+0027 APOSTROPHE, U+005C REVERSE SOLIDUS, or new-line character*
 - escape-sequence:
 	- simple-escape-sequence
 	- numeric-escape-sequence
 	- conditional-escape-sequence
 - simple-escape-sequence:
 	- \ simple-escape-sequence-char
 - simple-escape-sequence-char: *one of*
 	- ' " ? \ a b f n r t v
 - numeric-escape-sequence:
 	- octal-escape-sequence
 	- hexadecimal-escape-sequence
 - octal-escape-sequence:
 	- \ octal-digit
 	- \ octal-digit octal-digit
 	- \ octal-digit octal-digit octal-digit
 - hexadecimal-escape-sequence:
 	- \x hexadecimal-digit
 	- hexadecimal-escape-sequence hexadecimal-digit
 - conditional-escape-sequence:
 	- \ conditional-escape-sequence-char
 - conditional-escape-sequence-char:
 	- *any member of the basic character set that is not an octal-digit, a simple-escape-sequence-char, or the characters **u**, **U**, or **x***

A non-encodable character literal is a character-literal whose c-char-sequence consists of a single c-char that is not a numeric-escape-sequence and that specifies a character that lacks represention in the literal's associated character encoding or that can not be encoded as a single code unit. A multicharacter literal is a character-literal whose c-char-sequence consists of more than one c-char. The encoding-prefix of a non-encodable character literal or a multicharacter literal shall be absent or *L*. Such character literals are conditionally-supported.

The kind of a character-literal, its type, and its associated character encoding are determined by its encoding-prefix and its c-char-sequence as defined in the table below. The special cases for non-encodable character literals and multicharacter literals take precedence over their respective base kinds.

| **Encoding prefix** | **Kind**                                 | **Type**   | **Associated character encoding** | **Example**   |
|---------------------|------------------------------------------|------------|-----------------------------------|---------------|
| none                | ordinary character literal               | `char`     | ordinary                          | 'v'           |
| none                | non-encodable ordinary character literal | `int`      | literal                           | '\U0001F525'  |
| none                | ordinary multicharacter literal          | `int`      | encoding                          | 'abcd'        |
| *L*                 | wide character literal                   | `wchar_t`  | wide                              | L'w'          |
| *L*                 | non-encodable wide character literal     | `wchar_t`  | literal                           | L'\U0001F32A' |
| *L*                 | wide multicharacter literal              | `wchar_t`  | encoding                          | L'abcd'       |
| *u8*                | UTF-8 character literal                  | `char8_t`  | UTF-8                             | u8'x'         |
| *u*                 | UTF-16 character literal                 | `char16_t` | UTF-16                            | u'y'          |
| *U*                 | UTF-32 character literal                 | `char32_t` | UTF-32                            | U'z'          |

A character enclosed within single quotes is a literal of type `char`. Zero or more characters enclosed in double quotation marks is a string literal:

```cpp
'a' // character literal
"Hello, World!" // string literal
```

The type of a string literal is array of constant `char`s. The compiler appends a null character `\0` to every string literal. Thus, the actual size of a string literal is one more than its apparent size. For example, the character literal 'A' represents the single character *A*, whereas the string literal "A" represents an array of two characters: *A* and the null character.

Two string literals that appear adjacent to one another and that are separated only by spaces, tabs, or newlines are concatenated into a single literal. We use this form of literal when we need to write a literal that would otherwise be too large to fit comfortably on a single line:

```cpp
std::cout << "a really, really long string literal"
			 "that spans two lines" << std::endl;
```

### Escape sequences

Some characters, such as backspace or control characters, have no visible image. Such characters are non-printable. Other characters (single and double quotation marks, question mark, and backslash) have special meaning in the language. Programs cannot use any of these characters directly. Instead, they must use escape sequence to represent such characters. An escape sequence begins with a backslash (or, reverse solidus). The language defines several escape sequences:

| **character**             | **escape-sequence** |
|---------------------------|---------------------|
| line feed                 | `\n`                |
| character tabulation      | `\t`                |
| line tabulation           | `\v`                |
| backspace                 | `\b`                |
| carriage return           | `\r`                |
| form feed                 | `\f`                |
| alert                     | `\a`                |
| reverse solidus           | `\\`                |
| question mark             | `\?`                |
| apostrophe                | `\’`                |
| quotation mark            | `\"`                |

> The double quotation mark `"` and the question mark `?` can be represented as themselves, or by the escape sequences `\"` and `\?` respectively, but the single quotation mark `'` and the backslash (or, reverse solidus) `\` shall be represented by the escape sequences `\'` and `\\` respectively. If the character following the backslash is not one of those specified, the behavior is undefined. An escape sequence specifies a single character.
> ~ C++11 Standard Specification

We can also write a generalized escape sequence, which is `\x` followed by one or more hexadecimal digits or a `\` followed by one, two, or three octal digits. The value represents the numerical value of the character. Some examples, assuming the Latin-1 character set:

 - \7 (bell)
 - \12 (newline)
 - \40 (blank)
 - \0 (null)
 - \115 ('M')
 - \x4d ('M')

As with an escape sequence defined by the langauge, we use these numeric escape sequences as we would do with any character:

```cpp
std::cout << "Hi \x4dO\115!\n"; // prints Hi MOM! followed by a newline
std::cout << '\115' << '\n'; // prints M followed by a newline
```

Note that if a backslash (or, reverse solidus) is followed by more than three octal digits, only the first three are associated with the `\`. For example, "\1234" represents two characters: the character represented by the octal value 123, and the character *4*. In contrast, `\x` uses up all the hexadecimal digits following it; "\x1234" represents a single, 16-bit character composed from the bits corresponding to these four hexadecimal digits. Because most machines have 8-bit chars, such values are unlikely to be useful. Ordinarily, hexadecimal characters with more than 8 bits are used with extended character sets using one of the prefixes from the table above.

### Specifying the type of a literal

We can override the default of an integer, floating-point, or character-literal by supplying a suffix or prefix as listed in the table below:

```cpp
L'a' // wide character literal, type is wchar_t
u8"hi!" // utf-8 string literal, utf-8 encodes a Unicode character in 8-bits
42ULL // unsigned integer literal, type is unsigned long long
1E-3F // single-precision floating-point literal, type is float
3.14159L // extended-precision floating-point literal, type is long double
```

*When you want a `long` or `long long` or `long double` literal, use the uppercase `L`; the lowercase `l` letter is too easily mistaken for the digit `1`.

| **Prefix** | **Meaning**                           | **Type**   |
|------------|---------------------------------------|------------|
| u8         | UTF-8 encoding (string literals only) | `char`     |
| u          | UTF-16 encoding                       | `char16_t` |
| U          | UTF-32 character                      | `char32_t` |
| L          | wide character                        | `wchar_t`  |

| **Suffix**   | **Minimum Type** |
|--------------|------------------|
| `u` or `U`   | `unsigned int`   |
| `l` or `L`   | `long`           |
| `ll` or `LL` | `long long`      |

| **Suffix** | **Type**      |
|------------|---------------|
| `f` or `F` | `float`       |
| `l` or `L` | `long double` |

We can independently specify the signedness and size of an integral literal. If the suffix contains a *U*, then the literal has an unsigned type, so a decimal, octal, or hexadecimal literal with *U* suffix has the smallest type of `unsigned int`, `unsigned long` `unsigned long long`, in which the literal's value fits. If the suffix contains an *L*, then the literal's type will be at least `long`; if the suffix contains *LL*, then the literal's type will either `long long` or `unsigned long long`. We can also combine the signedness and size suffixes; i.e., *UL* will be `unsigned long` or `unsigned long long`, depending on whether the literal's value fits into the `unsigned long` first.

## Boolean and pointer literals

The words `true` and `false` are literals of type `bool`:

```cpp
bool test = false;
```

The word `nullptr` is a pointer-literal. We will discuss pointer literals later.