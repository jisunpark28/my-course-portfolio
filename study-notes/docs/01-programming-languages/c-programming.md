---
sidebar_position: 2
title: C programming
---

# C Basics

This page summarizes core C programming concepts.

---

## Q: How does a C program actually turn into an executable?

In C, it’s not a one-step process. Your code goes through a few distinct stages:
1. **Pre-processor**: It handles things like `#include` and `#define`. It's basically a fancy 'search and replace' tool.
2. **Compiler**: This is where the magic happens. It translates your C code into **Object Files** (`.obj` or `.o`). It's machine code, but not yet a full program.
3. **Linker**: This is the final step. It takes your object files and any library code (like `stdio.h`) and stitches them together into one **Executable file**. 

*Interview Tip:* If you see an `ld` error, it’s a Linker issue, usually meaning it can't find a function you called!

---

## Q: Why do we bother with pointers instead of just using variables?

Pointers give you direct control over memory, which is C’s biggest strength. Instead of storing a value, a pointer stores a **memory address**. 
I use them for two main reasons:
* **Efficiency**: Passing a pointer to a huge structure is much faster than copying the whole thing.
* **Direct Modification**: It allows **Pass-by-Address**. Without pointers, a function only gets a copy of your data. With pointers, the function can reach into memory and change the original value.

---

## Q: How do you ensure your functions are well-designed?

I always follow the rule of **'High Cohesion and Loose Coupling'**.
* **High Cohesion**: I make sure each function has **one clear job**. If a function is calculating taxes *and* updating a database, it's doing too much.
* **Loose Coupling**: I try to make functions independent. I should be able to update my 'tax calculation' logic without breaking the 'printing' logic. It makes the whole system easier to maintain and test.

---

## Q: What is a common pitfall when working with strings in C?

The most common mistake is forgetting the **Null Terminator (`\0`)**. In C, a string is just a character array. The computer doesn't know where the string ends unless it hits that `\0`. 
If you forget to allocate space for it—say, a `char[5]` for the word 'Hello'—the program will keep reading into random memory. This leads to 'garbage' data or the dreaded **Segmentation Fault**.

---

## Q: How do you handle complex data models in C?

We use **Structs**. They are like the ancestors of Objects in C++. A struct lets me group different data types (like an `int` for an ID and a `char[]` for a name) into a single unit. 
A key detail I learned at Seneca is the syntax: 
* Use a **dot (`.`)** for a regular struct variable.
* Use an **arrow (`->`)** when you have a **pointer** to a struct. It’s shorthand for `(*ptr).member` and it makes the code much cleaner.

---

## Quick Summary Table

| Concept | Key Interview Word | Why it matters? |
| :--- | :--- | :--- |
| **Compilation** | Linker / Object File | Knowing where the build failed. |
| **Pointers** | Memory Address | Performance and direct data access. |
| **Modularity** | Loose Coupling | Making code reusable and easy to fix. |
| **Strings** | Null Terminator (`\0`) | Preventing memory leaks and crashes. |