# Exercise 2.1: What are the differences between `int`, `long`, `long long`, and `short`

**Between an unsigned and a signed type? Between a `float` and a `double`?**

## Integer types

## Standard integer types

C++17 standard specification defines five standard signed integer types: 

 - `signed char`
 - `short int`
 - `int`
 - `long int`
 - `long long int`

And five standard unsigned integer types:

 - `unsigned char`
 - `unsigned short int`
 - `unsigned int`
 - `unsigned long int`
 - `unsigned long long int`

Other fixed-size integer types:

 - `int8_t`
 - `int16_t`
 - `int32_t`
 - `int64_t`

 - `int_fast8_t`
 - `int_fast16_t`
 - `int_fast32_t`
 - `int_fast64_t`

 - `int_least8_t`
 - `int_least16_t`
 - `int_least32_t`
 - `int_least64_t`

 - `uint_fast8_t`
 - `uint_fast16_t`
 - `uint_fast32_t`
 - `uint_fast64_t`

 - `uint_least8_t`
 - `uint_least16_t`
 - `uint_least32_t`
 - `uint_least64_t`

The fixed-size and extended integer types also have signed and unsigned variants, but since they are implementation defined, C++17 standard specification does not say anything about their characteristics. Also, GNU Compiler Collection manual points out that:

> GCC does not support any extended integer types

### Range of representable values in signed and unsigned integer types

The range of representable values for signed and unsigned integer types varies, since, signed integer types have to accomodate one bit for representing the sign on the value. For an N-bit integer type, *where N is called the width of the type*:

 - An unsigned variant can represent values in range: 0 to 2<sup>N</sup> - 1
 - A signed variant can represent values in range: -2<sup>N - 1</sup> to 2<sup>N - 1</sup> - 1

### Overflow in signed and unsigned integer types

 - Overflow in unsigned integer types is handled using modulo 2<sup>N</sup>. Therefore, if `x` is greater than or equal to 2<sup>N</sup>, `x = x % 2^N`
 - Overflow in signed integer types in undefined. Because of which, the compiler often assumes that it can not happen, and removes overflow specific branches in optimization

### Widths for standard integer types

According to C++17 standard specifications, each types in the list must provide *atleast* as much storage as the one preceding it.

| **Type**        | **Minimum width *N*** |
|-----------------|-----------------------|
| `signed char`   | 8                     |
| `short int`     | 16                    |
| `int`           | 16                    |
| `long int`      | 32                    |
| `long long int` | 64                    |

| **Type**        | **Implementation width *N*** |
|-----------------|------------------------------|
| `signed char`   | 8                            |
| `short int`     | 16                           |
| `int`           | 32                           |
| `long int`      | 64                           |
| `long long int` | 64                           |


## Character types

The types `char`, `wchar_t`, `char8_t`, `char16_t`, and `char32_t` are collectively called *character types*. The `char` is a distinct type that has an implementation-defined choice of `signed char` or `unsigned char`. The three types `char`, `unsigned char`, and `signed char` are collectively called *ordinary character types*. The ordinary character type and `char8_t` are collectively called *narrow character types*.

A `char` is guaranteed to be big enough to hold numeric values corresponding to the characters in the machine's basic character set. That is, a `char` is the same size as a machine byte. The basic character set is defined in § 5.3 in C++17 standard specification:

| **code point**   | **character**                | **glyph**                                           |
|------------------|------------------------------|-----------------------------------------------------|
| U+0000           | null                         |                                                     |
| U+0007           | alert			              |                                                     |
| U+0008           | backspace			          |                                                     |
| U+0009           | character tabulation         |                                                     |
| U+000B           | line tabulation			  |                                                     |
| U+000C           | form feed			          |                                                     |
| U+000D           | carriage return              |                                                     |
| U+0020           | space			              |                                                     |
| U+000A           | line feed			          | new-line                                            |
| U+0021           | exclamation mark			  | !                                                   |
| U+0022           | quotation mark			      | "                                                   |
| U+0023           | number sign			      | #                                                   |
| U+0025           | percent sign			      | %                                                   |
| U+0026           | ampersand			          | &                                                   |
| U+0027           | apostrophe			          | ’                                                   |
| U+0028           | left parenthesis			  | (                                                   |
| U+0029           | right parenthesis			  | )                                                   |
| U+002A           | asterisk			          | *                                                   |
| U+002B           | plus sign			          | +                                                   |
| U+002C           | comma			              | ,                                                   |
| U+002D           | hyphen-minus			      | -                                                   |
| U+002E           | full stop			          | .                                                   |
| U+002F           | solidus			          | /                                                   |
| U+0030 .. U+0039 | digit zero .. nine			  | 0 1 2 3 4 5 6 7 8 9                                 |
| U+003A           | colon			              | :                                                   |
| U+003B           | semicolon			          | ;                                                   |
| U+003C           | less-than sign			      | <                                                   |
| U+003D           | equals sign			      | =                                                   |
| U+003E           | greater-than sign			  | >                                                   |
| U+003F           | question mark			      | ?                                                   |
| U+0041 .. U+005A | latin capital letter A .. Z  | A B C D E F G H I J K L M N O P Q R S T U V W X Y Z	|
| U+005B           | left square bracket          | [                                                   |
| U+005C           | reverse solidus              | \                                                   |
| U+005D           | right square bracket         | ]                                                   |
| U+005E           | circumflex accent            | ^                                                   |
| U+005F           | low line                     | _                                                   |
| U+0061 .. U+007A | latin small letter a .. z    | a b c d e f g h i j k l m n o p q r s t u v w x y z |
| U+007b           | left curly bracket           | {                                                   |
| U+007c           | vertical line                | |                                                   |
| U+007d           | right curly bracket          | }                                                   |
| U+007e           | tilde                        | ~                                                   |

The `wchar_t` is a distinct type that has an implementation-defined signed or unsigned integer types as its underlying type. The values of type `wchar_t` can represent distinct codes for all of the largest extended character set specified among the supported locales. The *translation character set* consists of the following elements:

 - Each character named by ISO / IEC 10646, as identified by its unique UCS scalar value, and
 - A distinct character for each USC scalar value where no named character is defined

> ISO / IEC 10646 code points are integers in the range [0, 10FFFF] (hecadecimal). A surrogate code point is a value in the range [D800, DFFF] (hexadecimal). A USC scalar value is any code point that is not a surrogate code
> ~ <cite>C++17 Standard Specification</cite>

### Surrogate pairs

#### Need for surrogate pairs

Most applications used UTF-16 to represent Unicode character data. The use of 16 bits allows direct representation of 65,536 unique characters, but this Basic Multilingual Plane (BMP) is not nearly enough to cover all the symbols used in human languages. Unicode version 4.1 includes over 97,000 characters, with over 70,000 characters for Chinese alone.

The Unicode standard has established 16 additional planes of characters, each the same size as the BMP. Naturally, most code poins beyond the BMP do not yet have the characters assigned to them, but definition of the plane gives Unicode the potential to define 1,114,112 (2<sup>16</sup> * 17) characters within the code point range U+0000 to U+10FFF. For UTF-16 to represent this larger set of characters, the Unicode Standard defines "supplementary characters".

A supplementary character is a character located beyond the BMP, and a "surrogate" is a UTF-16 code value. For UTF-16, a "surrogate pair" is required to represent a single supplementary character. The first (high) (also, leading) surrogate is a 16-bit code value in the range U+D800 to U+DBFF. The second (low) (also, trailing) surrogate is a 16-bit code value in the range U+DC00 to U+DFFF. Using the surrogate mechanism, UTF-16 can support all 1,114,112 potential Unicode characters.

Although most supplementary characters (expressed with surrogate pairs in UTF-16) are not too common. However, that does not mean that characters should be neglected. Among them are a number of individual characters that are very popular, as well as many sets important to East Asian procurement specifications. Among the notable supplementary characters are:

 - Many popular emoji and emoticons
 - Symbols used for interoperating with Wingdings and Webdings
 - Numberous small sets of CJK characters important for procurement, including personal and place names
 - Variation selectors used for all ideographic variation sequences
 - Numerous minority scripts important for some user communities
 - Some highly salient historic scripts, such as Egyptian hieroglyphics 


#### UTF-16 specifications for surrogate pairs

Unicode 14.0.0 Standard explains that, in a well-formed UTF-16, a trailing surrogate can be preceded only by a leading surrogate, and not by:

 - Another trailing surrogate
 - A non-surrogate, or
 - The start of text

A leading surrogate, thereby, can be followed only by a trailing surrogate, and not by:

 - Another leading-surrogate
 - A non-surrogate
 - The end of text

Therefore, not following the above conditions in a well-formed UTF-16 is merely an error, and should be addressed appropriately. Leading surrogates and trailing surrogates are assigned disjoint ranges of code units. In UTF-16, non-surrogate code points can never be represented with code unit values in those ranges. Because theses ranges are disjoint, each code unit in well-formed UTF-16 must meet one and only one of the only three possible conditions:

 - A single non-surrogate code unit, representing a code point in either of the two ranges: U+0000 to U+D7FF or U+E000 to U+FFFF
 - A leading surrogate code unit, representing the first part of a surrogate pair, in the range: U+D800 to U+DBFF
 - A trailing surrogate code unit, representing the second (last) part of a surrogate pair, in the range: U+DC00 to U+DFFF


#### Handling surrogate pairs

By accessing at most two code units, a process using the UTF-16 encoding form can therefore, interpret any Unicode character. Determining character boundaries requires at most scanning one preceding or one following code unit without regard to any other context.

As long as an implementation does not remove either of a pair of surrogate code units or incorrectly insert another character between them, the integrity of the data is maintained. Moreover, even if the data becomes corrupted, the corruption remains localized, unlike with some other multibyte encodings such as Shift-JYS or EUC. Corrupting a single UTF-16 code unit affects only a single character. Because of non-overlap, this kind of error does not propagate throughout the rest of the text.

UTF-16 enjoys a beneficial frequency distribution in that, for the majority of all text data, surrogate pairs will be very rare; non-surrogate code points, by contrast, will be very common. Not only does this help to limit the performance penalty incurred when handling a variable width encoding, but it also allows many processes either to take no specific action for surrogates or to handle surrogate pairs with existing mechanisms that are already needed to handle character sequences.

Implementations should fully support surrogate pairs in processing UTF-16 text. Without surrogate support, an implementation would not interpret any supplementary characters or guaranteee the integrity of surrogate pairs. Support for supplementary characters is important because a significant number of them are relevant to modern use, despite their low frequency.

The individual components of implementations may have different levels of support for surrogates, as long as those components are assembled and communicated correctly. Low level string processing, where a Unicode string is not interpreted but is handled simply by an array of code units, may ignore surrogate pairs. Width such strings, for example, a truncation operation with an arbitrary offset might break a surrogate pair. For performance in string operations, such behavior is reasonable at a low level, but it requires higher level processes to ensure that offsets are on character boundaries so as to guarantee the integrity of surrogate pairs.

#### Strategies for surrogate pair support

Many implementations that handle advanced features of the Unicode Standard can easily be modified to support surrogate pairs in UTF-16. For example:
 
 - Text collation can be handled by treating those surrogate pairs as "grouped characters" such as is done for "ij" in Dutch or "ch" in Slovak
 - Text entry can be handled by having the keyboard generate two Unicode code points with a single keypress, much as ENTER key can generate CRLF (*carriage return* and *line feed*) or an Arabic keyboard can have "lam-alef" key that generates a sequence of two characters, *lam* and *alef*. 
 - Truncation can be handled with the same mechanism as used to keep combining marks with the base characters. 

 Users are prevented from damaging the text if a text editor keeps insertion points (carets) on character boundaries.

 Implementations using UTF-8 and Unicode 8-bit strings necessitate similar considerations. The main difference from handling UTF-16 is that in the UTF-8 case the only characters that are represented with single code units (single bytes) in UTF-8 are the ASCII characters, U+0000 .. U+007F. Characters represented by multiple byte sequences are very common in UTF-8, unlike surrogate pairs in UTF-16, which are rather uncommon. This difference in frequency may result in different strategies for handling the multibyte sequences in UTF-8.

#### Differences between UTF encoding

The conversions between all of the UTF encodings (UTF-8, UTF-16, UTF-32) are algorithmitically based, fast, and lossless. This makes it easy to support data input and output, while using a particular UTF encoding for internal storage or processing. Frequency distribution based on usage is given below:

 - UTF-8 is most common on the web
 - UTF-16 is used by Java and Windows
 - UTF-8 and UTF-32 are used by Linux and various UNIX systems

The following table summarizes some of the properties of each of the UTF encodings (*In the table, <BOM> indicates that the byte order is determined by a byte order mark, if present at the beginning of data stream, otherwise it is big-endian*):

| **name**                   | **UTF-8** | **UTF-16** | **UTF-16BE** | **UTF-16LE**  | **UTF-32** | **UTF-32BE** | **UTF-32LE**  |
|----------------------------|-----------|------------|--------------|---------------|------------|--------------|---------------|
| Smallest code point 	     | 0000 	 | 0000 	  | 0000 	     | 0000          | 0000       | 0000         | 0000          |
| Largest code point 	     | 10FFFF 	 | 10FFFF 	  | 10FFFF 	     | 10FFFF 	     | 10FFFF 	  | 10FFFF 	     | 10FFFF        |
| Code unit size 	         | 8 bits 	 | 16 bits 	  | 16 bits 	 | 16 bits 	     | 32 bits 	  | 32 bits 	 | 32 bits       |
| Byte order 	             | N/A 	     | <BOM> 	  | big-endian 	 | little-endian | <BOM> 	  | big-endian 	 | little-endian |
| Fewest bytes per character | 1 	     | 2 	      | 2 	         | 2 	         | 4 	      | 4 	         | 4             |
| Most bytes per character 	 | 4 	     | 4 	      | 4 	         | 4 	         | 4 	      | 4 	         | 4             |

Since, IS0 / IEC 10646 defines translation character sets as code points in the range: U+0000 to U+10FFFF, it requires 21-bits to encode. For performance reasons, instead of three bytes, four are used to represent them. Therefore, for UTF-8 to represent all characters of the translation character set, it needs 4 bytes, and so do all other UTF encodings. However, since UTF-8 was specified before BMP and translation character set, it supports the ASCII character set with 8 bits. Similarly, UTF-16 was specified before surrogate pairs and extra lingual planes were needed, therefore, they support the Basic Multilingual Plane, with 16 bites.

UTF-16 and UTF-32 uses code units that are two and four bytes respectively. For these encodings, there are three sub-flavors: unmarked, BE (big-endian), and, LE (little-endian).

#### Packaging Unicode characters into 8-bit ASCII stream

 - Use UTF-8. This preserves ASCII, but not Latin-1, because the characters with code points above 7F (hexadecimal) (127, in base-10) are different from Latin-1. UTF-8 uses the bytes in the ASCII specification only for ASCII characters. Therefore, it works well in any environment where ASCII characters have a significance as syntax characters, e.g. file name syntaxes, markup languages, etc., but where all other characters may use arbitrary bytes.
 - Use Java or C style escapes, of the form: \uXXXXX or \xXXXXX. This format is not standard for text files, but well-defined in the framework of the languages in question
 - Use numeric character escapes, of the form: &#xXXXX or $#DDDDD, as in HTML and XML. Again, these are not standard for plain text files, but well-defined in the frameworks of these markup languages

#### Algorithm for conversion from UTF-16 to character codes

Using the following type definitions:

```cpp
typedef unsigned int16 UTF16;
typedef unsigned int32 UTF32;

```

The first snippet calculates the high (leading) surrogate from a character code in C:

```cpp
const UTF16 HI_SURROGATE_START = 0xD800;
UTF16 X = (UTF16) C;
UTF32 U = (C >> 16) & ((1 << 5) - 1);
UTF16 W = (UTF16) U - 1;
UTF16 HiSurrogate = HI_SURROGATE_START | (W << 6) | X >> 10; 
```

Where, `X`, `U`, and `W` correspond to the labels used in Table 3-5 UTF-16 Bit Distribution. The next snippet does the same for the low snippet:

```cpp
const UTF16 LO_SURROGATE_START = 0xDC00;
UTF16 X = (UTF16) C;
UTF16 LoSurrogate = (UTF16) (LO_SURROGATE_START | X & ((1 << 10) - 1));
```

Finally, the reverse, where `hi` and `lo` are the high and low surrogates, and `C` is the resulting character:

```cpp
UTF32 X = (hi & ((1 << 6) - 1)) << 10 | lo & ((1 << 10) - 1);
UTF32 W = (hi >> 6) & ((1 << 5) - 1);
UTF32 U = W + 1;
UTF32 C = U << 16 | X;
```

## Boolean type

The `bool` is a distinct type that has the same object representation, value representation, and alignment requirements as an implementation-defined unsigned integer type. The values of `bool` are `true` and `false`. The character types, boolean types, the signed and unsigned integer types, and cv-qualified versions thereof, are collectively termed *integral types*, or *integer types*. The boolean literals are the keywords `false` and `true`. Such literals are prvalues and have type `bool`.

> There are no `signed bool`, `unsigned bool`, `short bool`, or `long bool` types or values
> ~ C++17 Standard Specification

The standard states that boolean types behave like integral types. Unless space is a constraint, almost all implementations store a standalone boolean values in a byte, since data must be addressable, and the smallest boundary on conventional architectures is a byte. However, it should be noted that there are some exceptions to this generalization. Especially, `std::vector<bool>` is specialized to allow individual elements to be stored as bits, rather than bytes. This will save space by sacrificing some functionality (for example, `std::search` may not work).

### Boolean conversions


Certain language constructs require that an expression be converted to a Boolean value. An expression *E* appearing in such context is said to be *contextually converted to `bool`*, and is well-formed if and only if the declaration `bool t(E);` is well-formed, for some invented temporary variable `t`. Such standard conversion takes place when an expression is used as a condition in an `if` statement or an iteration statement. The destination type is `bool`.

A prvalue of type `bool` can be converted to a prvalue of type `int`, with `false` becoming zero, and `true` becoming one. This is an example of an integral promotion. If however, the destination of an integral promotion is a `bool`, a prvalue of arithmetic, unscoped enumeration, pointer, or pointer-to-member type can be converted to a prvalue of type `bool`. A zero value, null pointer, or null member pointer value is converted to `false`; any other value is converted to `true`.

The operand of the logical negation operator ! is contextually converted to `bool`; its value is `true` if the converted operand is `false`, and `false` otherwise. The type of the result is `bool`.

## Floating point types

The three distinct types: `float`, `double`, and `long double` can represent floating-point numbers. The type `double` provides atleast as much precision as `float`, and `long double` provides atleast as much precision as `double`. The set of values of the type `float` is a subset of the values of type `double`, which are in turn, subset of values of type `long double`. The types `float`, `double`, `long double`, and cv-qualified versions thereof, are collectively termed *floating-point types*. Integral and floating point types are collectively called `arithmetic types`.

Unlike integers, a floating-point value is intended to represent extremely small values as well as extremely large. For normal 32-bit floating point values, this corresponds to values in range: 1.175494351 * 10<sup>-38</sup> to 3.40282347 * 10<sup>38</sup>. Clearly using only 32 bits, its not possible to store every digit in such numbers. When it comes to representation, all normal floating-point numbers as a value in the range 1.0 to (almost) 2.0, scaled with a power of two. So, to encode this, the sign of the expression, the exponent, and, the value in the range 1.0 to (almost) 2.0 - this is known as the *mantissa* or the significand. Floating points are defined by the IEEE 754 Floating Point Standard Specifications. To assert this representation, ensure the following predefined constants have the correct values:

 - `__DBL_DIG__` = 15
 - `__DBL_MANT_DIG__` = 53
 - `__DBL_MAX_10_EXP__` = 308
 - `__DBL_MAX_EXP__` = 1024
 - `__DBL_MIN_10_EXP__` = -307
 - `__DBL_MIN_EXP__` = -1021

### IEEE 754 Standard for Floating-Point Arithmetic

Floating point arithmetic is a systematic approximation of real arithmetic. Floating point arithmetic can only represent a finite subset of the continuum of real numbers. Consequently, certain properties of real arithmetic, such as associativity of addition, do not always hold for floating point arithmetic. The mathematical structure underpinning the arithmetic in this standard is the extended real numbers, that is the set of real numbers together with positive and negative infinity. For a given format, the process of *rounding* maps an extended real number to a *floating point number* included in that format. A *floating point datum* which can be a signed zero, finite non-zero number, signed infinity, or a NaN (Not-a-Number), can be mapped to one or more representations of floating point data in a format. The representations of floating point data in a format consists of:

 -  Signed zero or non-zero floating point numbers of triples form: (sign, exponent, significand); in radix *b*, the floating point number represented by this triple is: (-1)<sup>sign</sup> x *b*<sup>exponent</sup> x significand; where:
     - *sign* is 0 or 1
     - *exponent* is any integer in the inclusive range: *emin* .. *emax*
     - *mantissa* (*significand*) is a number represented by a digit string of the form: *d<sub>0</sub>•d<sub>1</sub>d<sub>2</sub>...d<sub>p - 1</sub>*, where *d<sub>i</sub>* is an integer in the range: [0, *b*) - therefore, *m* is in the range: [0, *b*)
 - Two infinities: +∞, and -∞
 - Two NaNs: qNaN (quiet NaN), and sNaN (signalling NaN)

An encoding maps a representation of a floating point datum to a bit string. An encoding might map some representations of floating-point data to more than one bit string. Multiple NaN bit strings should be used to store retrospective diagnostic information.

The set of finite floating point numbers representable within a particular format is determined by the following integer parameters:

 - *b* = radix, 2 or 10
 - *p* = number of digits in the significand (precision)
 - *emax* = maximum exponent
 - *emin* = minimum exponent (*emin* shall be 1 - *emax* for all formats)

| **parameter** | **binary32** | **binary64** | **binary128** | **decimal64** | **decimal128** |
|---------------|--------------|--------------|---------------|---------------|----------------|
| *p* (digits)  | 24           | 53           | 113           | 16            | 34             |
| *emax*        | +127         | +1023        | +16383        | +384          | +6144          |

#### Binary interchange format encodings

Each floating point number has just one encoding in a binary interchange format. To make the encoding unique, the value of the mantissa, *m*, is maximized by decreasing *e* until either *e* = *emin* or *m* >= 1. After this process is done, if *e* = *emin* and 0 < *m* < 1, the floating point number is subnormal. Subnormal numbers (and zero) are encoded with reserved biased exponent value. Representations of floating point numbers in a binary interchange formats are encoded in *k* bits in the following three fields ordered as shown:

 - 1-bit sign *S*
 - w-bit biased exponent *E* = *e* + *bias*
 - (*t* = *p* - 1)-bit trailing significand field digit string *T* = *d<sub>1</sub>•d<sub>2</sub>...d<sub>p - 1</sub>*; the leading bit of the significand, *d*<sub>0</sub>* is implicitly encoded in the biased exponent *E*.

```
    1 bit       w bits                 t = p - 1 bits
------------------------------------------------------------
| S (sign) | E (exponent) | T (trailing significand field) |
------------------------------------------------------------
```

The range of encoding's biased exponent, E, shall include:
 
 - every integer between 1 and 2<sup>w</sup> - 2, inclusive, to encode numbers
 - the reserved value 0 to encode ±0 and subnormal numbers
 - the reserved value 2<sup>w</sup> - 1 to encode ±∞ and NaNs

The representation *r* of the floating point datum, and value *v* of the floating point datum represented, are inferred from the constituent fields as follows:
 
 - If E = 2<sup>w</sup> - 1 and T != 0, then *r* is qNaN or sNaN; and *v* is NaN regardless of S
 - If E = 2<sup>w</sup> - 1 and T = 0, then *r* and *v* = (-1)<sup>S</sup> x (+∞)
 - If 1 <= E <= 2<sup>w</sup> - 2, then *r* is (S, (E - bias), (1 + 2<sup>1 - p</sup> x T)); thus, normal numbers have an implicit leading significand bit of 1
 - If E = 0 and T != 0, then *r* is (S, emin, (0 + 2<sup>1 - p</sup> x T)); thus, subnormal numbers have an implicit leading signifand bit of 0
 - If E = 0 and T = 0, then *r* is (S, emin, 0) and *v* = (-1)<sup>S</sup> x (+0) - signed zero

### Difference between `float` and `double`

As the name implies, `double` has twice the precision of the single-precision floating point type `float`. In general, a `double` has 15 decimal digits of precision, while `float` has 7. In most architectures (gcc, MSVC, x86, x64, ARM) `float` is the IEEE 754 single-precision floating-point number (binary32) and `double` is the IEEE 754 double-precision floating-point number (binary64). As such, the following parameter differences can be drawn:

 - `float` has 24 bits for precision, whereas, `double` has 53 bits
 - The maximum exponent for `float` is 127, while for `double`, it is 1023
 - Also, the bias for `float` is 127, and 1023 for `double`
 - Exponent field width is 8 bits in `float`, and 11 bits in `double`
 - Trailing significand field width is 23 bits for `float`, and 52 bits for `double`
 - Storage width for `float` is 32 bits, whereas, for `double`, it is 64 bits

In addition, the `long double` is the extended-precision floating-points defined by IEEE 754 Floating Point Standard Specification, as binary128. On GCC 11.2.0 (Ubuntu 11.2.0-19ubuntu1), the implementation defined sizes for each category of precision floating points (in bits) is given below:

| **type**      | **width** |
|---------------|-----------|
| `float`       | 32        |
| `double`      | 64        |
| `long double` | 128       |

## Void types

A type cv `void` is an incomplete type that can not be completed; such a type has an empty set of values. It is used as the return type for functions that do not return a value. Any expression can be explicitly converted to type cv `void`. Any expression of type `void` shall be used only as an expression statement, as an operand of a comma expression, as a second or third operand of `?:`, as the operand of `typeid`, `noexcept`, or `decltype`, as the expression in a return statement for a function with a return type cv `void`, or as the operand of an explicit conversion to type cv `void`.

## Memory model

The fundamental storage unit in the C++ memory model is the *byte*. A byte is at least large enough to contain the ordinary literal encoding of any element of the basic literal set, and the eight bit code units of the Unicode UTF-8 encoding form and is composed of a contiguous sequence of bits, the number of which is implementation defined. The least significant bit is called the low-order bit, the most significant bit is called the high-order bit. The memory available to C++ program consists of one or more sequences of contiguous bytes. Every byte has a unique address.

A memory location is either an object of scalar type that is not a bit-field or a maximal sequence of adjacent bit-fields all having nonzero width. *Classes and structures can contains members that occupy less storage than an integral type. These members are specified as bit fields*. Various features of the language, such as references and virtual functions, might involve additional memory locations that are not accessible to programs but are managed by the implementation. Two or more threads of execution can access separate memory locations without interfering with each other. Thus a bit-field and an adjacent non-bit-field are in separate memory locations, and therefore, can be concurrently updated by two threads of execution without interference. The same applies to two bit-fields, if one is declared inside a nested struct declaration and the other is not, or if the two are separated by a zero-length bit-field declaration, or if they are separated by a non-bit-field declaration. It is not safe to concurrently update two bit-fields in the same struct if all fields between them are also bit-fields of nonzero width.

## Some important nots for choosing integral types

According to C++ Primer 5<sup>th</sup> Edition by Barbara E. Moo, Josée Lajoie, and Stanley B. Lippman:
 - Use an `unsigned` type when you know that the values cannot be negative
 - Use `int` for integer arithmetic. `short` is usually too small, and in many implementations, `long` is the same size as `int` or `long long`. If your data values are larger than the minimum guaranteed size for an `int`, use `long long`
 - Do not use plain `char` or `bool` in arithmetic expressions. Use them *only* to hold characters or truth values, respectively. Computations using `char` are especially problematic because `char` can be `unsigned` or `signed` depending on implementation. If you need a tiny integer, explicitly specifiy either `signed char` or `unsigned char`
 - Use `double` for floating-point computations; `float` usually does not have enough precision, and the cost of double-precision calculations versus single-precision is negligible. In fact, on some machines and implementations, double-precision operations are faster than single-precision. The precision offered by `long double` usually is unnecessary and often entails considerable run-time cost.
