# Quiz Engine Application

This is a C++ console application that simulates a multiple-choice quiz system. It supports two types of users: *Premium Users* and *Guest Users*, and allows adding/removing questions and running quiz sessions.

##  Features

- Add and manage quiz questions (multiple choice)
- Two user types:
  - *Premium User*: earns 2 points per correct answer
  - *Guest User*: earns 1 point per correct answer
- Add users dynamically
- Run quiz sessions
- Track scores and display results

##  Concepts Used

- Object-Oriented Programming (Inheritance, Polymorphism)
- Dynamic Memory Allocation
- Structs and Classes
- Arrays and Pointers
- Menu-driven command-line interaction

##  How to Compile and Run

### Requirements
- A C++ compiler (like g++)

### Compile
```bash
g++ -o quiz_app QUIZ_ENGINE.cpp
