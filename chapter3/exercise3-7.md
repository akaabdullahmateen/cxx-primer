# Exercise 3.7: What would happen if you define the loop control variable in the previous exercise as type `char`?

**Predict the results and then change your program to use a `char` to see if you were right**

The range-based `for` statement syntax below is equivalent to the latter explicit implementation using basic `for` statements. 

```cpp
for (optional_init_statement for_range_declaration : for_range_initializer) statement;
```

```cpp
optional_init_statement;
auto &&range = for_range_initializer;
auto begin = begin_expr;
auto end = end_expr;
for(; begin != end; ++begin){
	for_range_declaration = *begin;
	statement;
}
```

By implication, `for_range_initializer` can be an expression of array type `R`; then, `begin_expr` and `end_expr` are `range` and `range + N` respectively, where `N` is the array bound. `R` needs to be an array of known bound and have complete type, otherwise, the program is ill-formed.

The `string` library describes an object that has sequences of any non-array trivial standard-layout type. Such types are called *char-like types*, and objects of char-like types are called *char-like objects* or simply *characters*.

The header `<string>` defines five specializations of the class template `char_traits<charT>`: `char_traits<char>`, `char_traits<char8_t>`, `char_traits<char16_t>`, `char_traits<char32_t>`, and `char_traits<wchar_t>`.

The class template `basic_string_view` describes an object that can refer to a constant contiguous sequence of char-like objects, with the first element of the sequence at position zero. The type of the char-like objects held in a `basic_string_view` is designated by `charT`.

The header `<string>` defines the `basic_string` class template for manipulating varying-length sequences of char-like objects and five *typedef-names*: `string`, `u8string`, `u16string`, `u32string`, and `wstring` - that name the specializations: `basic_string<char>`, `basic_string<char8_t>`, `basic_string<char16_t>`, `basic_string<char32_t>`, and `basic_string<wchar_t>`, respectively.

The class template `basic_string` describes objects that can store a sequence consisting of varying number of arbitrary char-like objects with the first element of the sequence at position zero. Such a sequence is also called a *string* if the type of the char-like objects that it holds is clear from the context. In all cases, [`data()`, `data() + size()`] is a valid range, `data() + size()` points at an object with value `charT()` (null terminator), and `size()` <= `capacity()` is `true`.

Therefore, `std::string` has char-like objects with type `char`. The compiler deduces this type for `auto` and explicitly declaring the `for_range_declaration` declarator with `char` type will bring no change to the program execution.