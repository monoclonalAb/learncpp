## unnamed parameters:

```cpp
void func(int count) {
    // if `count` doesn't do anything, we can turn it into an *unnamed parameter*
}

void func(int /* look unnamed */) {

}
```

## temporary objects:

```cpp
#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input; // return the value of input back to the caller
}

int main()
{
	std::cout << getValueFromUser() << '\n'; // where does the returned value get stored?

    // gets stored in a *temporary object*
    // return value of `getValueFromUser()` is destroyed after `std::cout << getValueFromUser() << '\n'`

	return 0;
}
```

## forward declaration:

cpp compilers compile *sequentially*; need a **forward declaration** to know what functions are

```cpp
#include <iostream>

// this is a declaration
int add(int x, int y); // forward declaration of add() (using a function declaration)

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
    return 0;
}

// this is a definition
int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}
```

eric tldr:
- compile error if syntax incorrect
- link error if no definition

## multiple code files:

you can just compile and link multiple files together:
e.g. with `main.cpp` and `input.cpp`, you can simply run `g++ main.cpp input.cpp -o main`

## namespaces:

namespaces are to prevent collisions w/ function names
- e.g. all of cpp standard libraries are in `std` namespace
- `using namespace std;` allows you to bypass having to assign namespaces

## preprocessor phase:

- happens before compilation
    - involves looking for *preprocessor directives* => instructions that start with '#'

### examples:

- `#include`
    - merges the contents of those files
        - angle brackets searches for *"included"* directories first
        - speech marks searches for files in our *current* directory
- `#define`
    - defines macros `#define IDENTIFIER substitution_text`
        - NOTE: macros are scoped from where they are defined to the end of the file 
    - used in conditional compilation:
```cpp
#define CONDITION
#ifdef CONDITION
    // code that gets compiled
#endif

#ifdef OTHER_CONDITION
    // code that does NOT get compiled
#endif

// other methods:

#ifndef CONDITION
    // is the opposite of `#ifdef`
#endif

#if 0
    // code does not get compiled
#endif
```

## header files:

- where you put ur function declarations => imported whenever u need them
    - to include them, you should add the import location in your compilation script, e.g. `g++ -o main -I./source/include main.cpp`

### header guards:

- to prevent duplicate definitions:
```cpp
#ifndef HEADER_GUARD
#define HEADER_GUARD
    // function definitions
#endif

// additional technique:
#pramga once // does the same thing

// NOTE: only doesn't work if header file gets copied multiple times => #pragma once wont work across files (even if identical)
```



