# 4 types of initialisation:

## for initialising variables:
```cpp
int width = 5;      // copy-initialisation (more readable, esp from `c` code)
int width ( 5 );    // direct-initialisation

/* Narrowing Conversions are NOT allowed below */
int width { 5 };    // direct-list-initialisation (most consistent behaviour -> *default*)
int width = { 5 };  // copy-list-initialisation
```

## for defining variables:
```cpp
int width;    // default-initialisation (left with indeterminate value)
int width {}; // value-initialisation (implicitly initialises the variable to the *closest* value to zero)
```

## if we are defining extra variables and we do not want compiler to complain (cpp 17):
```cpp
int main() {
    [[maybe_unused]] int x = 10; // don't complain if `x` is unused
    // additionally, compiler might optimise the the variables *out of the program*

    return 0;
}
```

# `std::cin` & `std::cout` is a buffer:

- `std::cin` has individual characters typed added to the buffer, enter key also stored as `\n (FIFO buffer)
- `>>` takes characters from the front of the buffer and *copy-initialises* it to the associated variable

```cpp
#include <iostream>

int main() {
    std::cout << "Enter two numbers: ";

    int x{};
    std::cin >> x;

    int y{};
    std::cin >> y;

    std::cout << "You entered " << x << " and " << y << "\n";

    // for this program, the inputs:
    // - `4\n` and `5\n`
    // - `4 5\n`
    // both react the same (output: "You entered 4 and 5")
    // due to buffered input

    // for `a b\n`, the output is "You entered 0 and 0" (gets assigned the value 0)
    // for `123ab123\n`, the output is "You entered 123 and 0" (the first read extracts "123" and leaves "abc" for a later extraction - that fails)

     
    return 0;
}
```


- `std::cout` output gets stored in memory inside a buffer, which gets periodically flushed

## `std::endl` vs `\n`

basically, `std::endl` flushes the buffer and `\n` doesn't => leading to better performance

## whitespace quirks:

```cpp
std::cout << "Hello "
    "world!"; // for some reason this works; outputs "Hello world!"
```

## sneak peak to operator order:

```cpp
int x { 2 };
std::cout << (x = 5) << '\n'; // for some reason, this outputs "5"
```


