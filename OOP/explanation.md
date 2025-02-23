# Complete Guide to C++ Programming Expamples
## Introduction
Welcome to this comprehensive guide on C++ programming for absolute beginners! This guide is designed to help you learn C++ step by step, starting from the basics and progressing to more advanced concepts. Whether you want to automate tasks, develop applications, or enhance your problem-solving skills, learning C++ is a great starting point.

## Table of Contents
1. [Writing Your First C++ Program](#writing-your-first-c++-program)
2. [Understanding Variables and Data Types](#understanding-variables-and-data-types)
3. [User Input in C++](#user-input-in-c++)
4. [Operators in C++](#operators-in-c++)
   
---

## Writing Your First C++ Program
### Hello, World! Program
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!";
    return 0;
}
```
### Explanation
- `#include <iostream>` – Includes input-output library.
- `using namespace std;` – Simplifies code.
- `int main()` – The main function where the program starts.
- `cout << "Hello, World!";` – Prints text to the screen.
- `return 0;` – Indicates successful execution.

---

## Understanding Variables and Data Types
Variables are storage locations in memory that hold values.

### Example:
```cpp
int age = 25; // Integer variable
```
### Common Data Types in C++
| Data Type | Purpose | Example |
|-----------|---------|---------|
| int | Whole numbers | `int age = 30;` |
| float | Decimal numbers | `float pi = 3.14;` |
| double | Large decimal numbers | `double num = 3.1415926535;` |
| char | Single character | `char letter = 'A';` |
| bool | True or false values | `bool isHappy = true;` |
| string | Text (requires `#include<string>`) | `string name = "Alice";` |

### Example Program:
```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 20;
    double price = 19.99;
    char grade = 'A';
    string name = "Alice";

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Price: $" << price << endl;
    cout << "Grade: " << grade << endl;
    
    return 0;
}
```

---

## User Input in C++
Use `cin` to take user input.

### Example Program:
```cpp
#include <iostream>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello, " << name << "! You are " << age << " years old." << endl;
    return 0;
}
```

---

## Operators in C++
### Arithmetic Operators
| Operator | Meaning | Example |
|----------|---------|---------|
| `+` | Addition | `a + b` |
| `-` | Subtraction | `a - b` |
| `*` | Multiplication | `a * b` |
| `/` | Division | `a / b` |
| `%` | Modulus (Remainder) | `a % b` |

### Example Program:
```cpp
int a = 10, b = 3;
cout << "Sum: " << a + b << endl;
cout << "Difference: " << a - b << endl;
cout << "Product: " << a * b << endl;
cout << "Quotient: " << a / b << endl;
cout << "Remainder: " << a % b << endl;
```

---
🎉 Happy Coding! 🚀

