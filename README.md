# Figures  

**Author:** Maxim Zaika  
**License:** MIT  

## Overview  

**Figures** is a C++ project for working with 2D geometric shapes such as triangles, circles, and rectangles. The project emphasizes immutability, string serialization/deserialization, easy extension with new figure types, and robust unit testing.  

## Project Structure  

/cmake — CMake configuration files
/lib — Libraries (if any)
/src — Source code
/test — Unit tests
CMakeLists.txt — Main CMake build file
.gitignore — Git ignore rules
LICENSE — MIT license
README.md — This file


## Main Components  

- Abstract base class for figures  
- Concrete implementations: Triangle, Circle, Rectangle (immutable)  
- Perimeter calculation for all figures  
- String conversion (serialization) and creation from strings (deserialization)  
- Easily extendable to add new figure types  
- Unit tests covering correctness, edge cases, and serialization/deserialization  

## Skills and Competencies  

### Programming Concepts
- Assertions  
- Exception handling  
- Exception safety guarantees  
- Invariants  
- Object-Oriented Programming principles  
- Polymorphism  
- SOLID principles  
- Streams  
- Test-Driven Development (TDD)  
- Unit testing  

### Design Patterns
- Abstract Factory  
- Factory  
- Prototype  

## Features Implemented  

- Support for basic figures: Triangle, Circle, Rectangle  
- Perimeter computation  
- Serialization to string  
- Deserialization from string  
- Unit tests  
- Build infrastructure with CMake  
