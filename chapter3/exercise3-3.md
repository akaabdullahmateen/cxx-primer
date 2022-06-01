# Explain how whitespace characters are handled in the `string` input operator and in the `getline` function.

## `basic_istream& operator >> basic_string& str;`

Behaves as *formatted input function*. After constructing a `sentry` object, if the `sentry` object returns `true` when converted to a value of type `bool`, calls `str.erase()` (which removes characters from the entirety of string `str`), and then extracts characters from `is` and appends them to `str` as if by calling `str.append(1, c)` (which appends `n` (= 1) copies of `c` to the string `str`). If `is.width()` is greater than zero, the maximum number `n` of characters appended is `is.width()`; otherwise `n` is `str.max_size()`. Characters are extracted and appended until any of the following occurs:

- `n` characters are stored
- end-of-file occurs on the input sequence
- `isspace(c, is.getloc())` is `true` for the next input character `c`

After the last character (if any) is extracted, `is.width(0)` is called and the `sentry` object is destroyed. If the function extracts no characters, it calls `is.setstate(ios_base::failbit)`, which may throw `ios_base::failure`. The function then returns `is`.

## `basic_istream& getline(basic_istream&& is, basic_string& str, charT delim);`

Behaves as an *unformatted input function*, except that it does not affect the value returned by subsequent calls to `basic_istream<>::gcount()`. After constructing a `sentry` object, if the `sentry` object returns `true` when converted to a value of type `bool`, calls `str.erase()` and then extracts characters from `is` and appends them to `str` as if by calling `str.append(1, c)` until any of the following occurs:

- end-of-file occurs on the input sequence (in which case, the `getline` function calls `is.setstate(ios_base::eofbit)`)
- `traits::eq(c, delim)` for the next available input character `c` (in which case, `c` is extracted but not appended)
- `str.max_size()` characters are stored (in which case, the function calls `is.setstate(ios_base::failbit)`)

The conditions are tested in the order shown. In any case, after the last character is extracted, the `sentry` object is destroyed. If they function extracts no characters, it calls `is.setstate(ios_base::failbit)`, which may throw `ios_base::failure`. The function then returns `is`.

## Formatted and unformatted input functions

Each *formatted input function* begins execution by constructing an object of class `sentry` with the `noskipws` (second) argument `false`. (*Sentry object is created which (if `noskipws` is `false` and `is.flags() & ios_base::skipws` is nonzero) extracts and dicards each character as long as the next available character `c` is a whitespace character.*) If the `sentry` object returns `true`, when converted to a value of type `bool`, the function endeavors to obtain the requested input. If an exception is thrown during input then `ios_base::badbit` is turned on in `*this`'s error state. If `(exceptions()&badbit) != 0` then the exception is rethrown. In any case, the formatted input function destroys the `sentry` object. If no exception has been thrown, it returns `*this`.

Each *unformatted input function* begins execution by constructing an object of class `sentry` with the default `noskipws` (second) argument `true`. If the `sentry` object returns `true`, when converted to a value of type `bool`, the function endeavors to obtain the requested input. Otherwise, if the `sentry` constructor exits by throwing an exception or if the `sentry` object returns `false` when converted to a value of type `bool`, the function returns without attempting to obtain any input. In either case, the number of extracted characters is set to zero; unformatted input functions taking a character array of nonzero size as an argument shall also store a null character (using `charT()`) in the first location of the array. If an exception is thrown during input then `ios_base::badbit` is turned on in `*this`'s error state. (Exceptions thrown from `basic_ios<>::clear()` are not caught or rethrown). If `(exceptions()&badbit) != 0` then the exception is rethrown. It also counts the number of characters extracted. If no exception has been thrown it ends by storing the count in a member object and returning the value specified. In any event the `sentry` object is destroyed before leaving the unformatted input function.

## Differences between `string` input operator `>>` and `getline` function

- The input operator `>>` continues extracting and appending characters from the `istream` till it encounters a whitespace (i.e., if `isspace(c, is.getloc())` is `true` for the next input character `c`), whereas, `getline` continues till the next character causes `traits::eq(c, delim)` to be `true` where `delim` is the delimiter passed to the `getline` function (default is the newline character `\n`).
- Since the input operator `>>` is a formatted input function, it skips leading whitespaces, but because `getline` is an unformatted input function, it *does not* ignore leading whitespaces.
- The `getline` function consumes the delimiting character (`'\n'` by default) - although, it does not append it to the `string`. The input operator `>>` *sees* the delimiting whitespace character(s), but *does not* consume it - iterative use of `istream >> string` is possible because this unconsumed delimiting whitespace is skipped as leading whitespace in the next iteration.