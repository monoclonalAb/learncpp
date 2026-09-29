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


### integers:

- for *integer division*, the decimal part is *always dropped*
- stinking integers aren't also fixed widths (2 bytes / 4 bytes)
    - cpp 11 introduced fix width integers! (have to import `#include <cstdint>`)
        - `std::int8_t`, `std::int16_t`, `std::int32_t`, `std::int64_t`
        - `std::uint8_t`, `std::uint16_t`, `std::uint32_t`, `std::uint64_t`
    - NOTE: for some reason, `std::int8_t` gets treated as a *signed char* and `std::uint8_t` gets treated as an *unsigned char* 
        - NOTE: it's because they are just aliases for *existing types*; not new ones, e.g. `std::int32_t` is just an alias for `int` or `long` (depending on which one represents 32 bits) 
    - cpp 11 also introduced **fast** and **least** integers (also included in `#include <cstdint>`)
        - e.g. `std::int_fast#_t` => fastest signed integer that is at least # bits (processed fastest by CPU)
        - e.g. `std::uint_least#_t` => least unsigned integer with width at least # bits
        (just annoying because it has different behaviour across different machines)

### floats:

- digits of precision:
    - `float` => 6-9 significant digits (typically 7)
    - `double` => 15-18 significant digits (typically 16)
    - `long double` => 33-36 significant digits
- `std::cout` has a precision of `6`
    - can be changed using `#include <iomanip>` (io manipulation??)
```cpp
#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::setprecision(17);
    std::cout << 3.333333333333333333333333333f << "\n"; // 3.3333332538604736
    std::cout << 3.333333333333333333333333333 << "\n";  // 3.3333333333333335
}
```
- favour `double` over `float` due to these *small rounding errors*

### booleans:

- stored w/ 0's and 1's
    - `false == 0` & `true == 1`
    - `std::cout` outputs `0` and `1` (if we want `true` and `false`, we can just do `std::cout << std::boolalpha;`, and toggle back off w/ `std::noboolalpha`)

## sizeof:

- `sizeof` returns... the size of a type / variable
    - note, less memory =/= faster; e.g. some machines are better suited at processing 32-bit ints vs 16/8-bit ints
    - return type is `std::size_t`; unsigned and at least 16 bits (author recommended import is `#include <cstddef>`)
        - imposes an *upper limit* on the size of an object
