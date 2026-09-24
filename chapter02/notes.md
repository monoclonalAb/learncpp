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

