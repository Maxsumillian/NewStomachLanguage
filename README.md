

# PROJECT: StomachLang

A CPU-driven virtual language system built in C++

---

## Overview

StomachLang is a custom virtual language built around a simple theme:
eating (input) and excreting (output).

The goal is to model how a programming language works internally by separating responsibilities into distinct components:

* A Language Layer (user interface)
* A Virtual CPU (execution engine)
* A Virtual Memory system (storage)
* A custom type system where variables act as memory references

---

## Project Goals

* Build a custom language that is easy to understand but still interesting
* Simulate low-level computation concepts
* Practice structured system design in C++
* Use test-driven development (TDD)
* Improve code quality through iteration

---

## Core Design Philosophy

Variables do not store values.
Variables only store memory addresses.

All computation and data access is handled by the CPU.

---

## System Architecture


Main
 └── Language Layer
      ├── CPU
      ├── Memory
      └── Variables


### Main

* Includes only `language.h`
* Acts as the entry point for the user

### Language Layer

* Connects CPU, Memory, and Variables
* Acts as the central system

### CPU

Handles:

* Arithmetic operations
* Comparisons
* String concatenation
* Expression evaluation
* Memory access

Also includes:

* Load/store operations
* An accumulator for temporary results

### Memory

* Stores only strings
* Uses a fixed structure
* Provides read/write operations
* Performs bounds checking

---

## Variable System

Variables are lightweight references to memory.

Example:


Calories x = 100;


Internally:

* `x` stores a memory address
* The actual value is stored in CPU-managed memory
* The CPU resolves the value when needed

Each variable contains:

* Name
* Data type
* Memory address

---

## Type System (Inheritance-Based)

Custom types mimic primitive data types:

* `Edible`
* `Calories`
* `Foods`

Each type defines:

* Valid input types
* Operator behavior
* Rules for interacting with the CPU

---

## Expression Evaluation

All expressions are executed through the CPU.


Variable result = a + b + c;


Execution flow:

* `operator+` returns a Variable
* The CPU stores intermediate results in temporary memory (slot 0)
* Original variables are not modified

---

## Temporary Memory System

* Uses reserved memory slot 0
* Stores intermediate results
* Overwritten for each expression
* No garbage collection is implemented

---

## Chaining System (Father Variable)

Before learning templates, chaining was implemented using:

* A generic Variable return type
* A FatherVariable system to hold intermediate results
* Constructors that convert results into the correct type

This allows:

* Expression chaining
* Controlled evaluation
* Safe conversion between types

---

## Operator Overloading

All variable classes use operator overloading to keep syntax clean.

Operators only trigger actions — the CPU performs the actual work.

---

## Design Notes

* Inheritance is used for polymorphism, but constructor overloading could simplify this
* Templates would improve chaining and type handling
* Addition is handled specially because of string concatenation
* The CPU-centric design simplifies variables but makes the CPU more complex

---

## Known Limitations

* No garbage collection
* Limited type system (int, string, bool)
* CPU handles most of the system complexity
* Some header/implementation separation issues during development
* Debugging required careful memory tracking

---

## Development History

### First Attempt

* Used maps and a symbol table
* Variables were retrieved dynamically

Problems:

* Memory tracking became complex
* Ordering required extra tracking
* Needed additional structures for lookup

### Second Attempt (Current)

* Variables store memory addresses directly

Improvements:

* Simpler design
* Easier to manage memory
* More predictable behavior

---

## Development Practices

* Test-driven development
* Incremental design
* Regular progress checks

Focus areas:

* Access control (private/protected/public)
* Const correctness
* Pointer and reference usage
* Performance improvements

---

## AI Usage

AI was used as a support tool, not to generate the system.

Used for:

* Structuring the project early on
* Debugging help
* Explaining C++ concepts (templates, inheritance, operator overloading)

Not used for:

* Writing the final implementation
* Designing the core system

Common issues during development:

* Header vs implementation mismatches
* Template errors
* Operator overloading type issues
* Memory update bugs
* Constructor initialization problems

NOTE: this Readme was polished with Ai
---

## Final Summary

StomachLang is a simplified virtual machine written in C++ where:

* Variables are memory references
* The CPU handles all computation
* Memory stores only strings
* Inheritance defines type behavior
* Operator overloading provides syntax
* Temporary memory enables expression chaining

---

## Future Improvements

* Add garbage collection
* Expand the type system
* Templates designed as a core element not just used as helper funcitons(Using for Chaining)
* Improve performance and memory handling
* Reduce CPU responsibility

---

## Notes

This is the second version of the project, with a much simpler and more maintainable design than the original.
