## integral types:
- types that involve integers
    - e.g. bools, chars, ints etc
    - note, the newer types in cpp end in `_t` like `std::nullptr_t`
- sizes:

| Category       | Type           | Minimum Size     | Typical Size       |
|----------------|----------------|------------------|--------------------|
| Boolean        | bool           | 1 byte           | 1 byte             |
| Character      | char           | 1 byte (exactly) | 1 byte             |
|                | wchar_t        | 1 byte           | 2 or 4 bytes       |
|                | char8_t        | 1 byte           | 1 byte             |
|                | char16_t       | 2 bytes          | 2 bytes            |
|                | char32_t       | 4 bytes          | 4 bytes            |
| Integral       | short          | 2 bytes          | 2 bytes            |
|                | int            | 2 bytes          | 4 bytes            |
|                | long           | 4 bytes          | 4 or 8 bytes       |
|                | long long      | 8 bytes          | 8 bytes            |
| Floating point | float          | 4 bytes          | 4 bytes            |
|                | double         | 8 bytes          | 8 bytes            |
|                | long double    | 8 bytes          | 8, 12, or 16 bytes |
| Pointer        | std::nullptr_t | 4 bytes          | 4 or 8 bytes       |

- `sizeof` returns... the size of a type / variable
    - note, less memory =/= faster; e.g. some machines are better suited at processing 32-bit ints vs 16/8-bit ints

- for *integer division*, the decimal part is *always dropped*
- stinking integers aren't also fixed widths (2 bytes / 4 bytes)
    - cpp 11 introduced fix width integers!
        - `std::int8_t`, `std::int16_t`, `std::int32_t`, `std::int64_t`
        - `std::uint8_t`, `std::uint16_t`, `std::uint32_t`, `std::uint64_t`
    - NOTE: for some reason, `std::int8_t` gets treated as a *signed char* and `std::uint8_t` gets treated as an *unsigned char* 


