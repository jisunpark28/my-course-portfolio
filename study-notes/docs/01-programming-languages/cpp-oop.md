---
sidebar_position: 3
title: C++ programming
---

# C++ Basics

This page summarizes core C++ programming concepts.

---

## Q: Why do we bother with 'private' members if we're just going to write getters and setters anyway?

It’s all about **data integrity**. If I make my data members public, any module can reach in and change them to invalid values. In OOP244, we learned that a class should be a 'black box.' By keeping data private, I can add **validation logic** inside my setters. For example, if I have a 'salary' variable, I can prevent it from being set to a negative number. It keeps the object in a 'safe state' at all times.

---

## Q: If your class uses dynamic memory (pointers), what three things must you implement?

You’re talking about the **Rule of Three**. If a class manages a resource, I absolutely need:
1. **Destructor**: To prevent memory leaks by deallocating the memory.
2. **Copy Constructor**: To perform a **Deep Copy**. Without this, C++ does a 'shallow copy,' and two objects end up pointing to the same memory, which causes a crash when they both try to delete it.
3. **Copy Assignment Operator**: To handle cases like `a = b`. I have to check for **self-assignment** (like `a = a`), clean up existing memory, and then copy the new data.



---

## Q: What is the `this` pointer, and when have you actually used it?

The `this` pointer is essentially a hidden pointer that points to the **current object**. I used it a lot when overloading the **assignment operator**. Since the operator needs to return the current object to allow 'chaining' (like `a = b = c`), I return `*this`. It’s also a lifesaver when my function parameters have the same name as my member variables—I just use `this->name = name` to clarify which is which.

---

## Q: What happens when you declare a function as 'virtual'?

Declaring a function `virtual` tells the compiler to use **Dynamic Binding**. Instead of deciding which function to call at compile-time, it checks the actual type of the object at **runtime**. 
This is the heart of Polymorphism. In our 'Shape' workshop, we had a base class pointer pointing to a 'Circle' or a 'Rectangle.' Because the `draw()` function was virtual, the program knew exactly which shape to draw without me having to write a bunch of `if` statements.



---

## Q: What is a Pure Virtual Function, and why would you use one?

A Pure Virtual Function is a function that has no body in the base class—it’s just a placeholder, like `virtual void draw() = 0;`.
Any class that has at least one of these becomes an **Abstract Base Class**. You can’t instantiate it directly. We use this to create a strict 'contract' or **Interface**. It forces any derived class (like 'Square') to implement that specific function, ensuring our system remains consistent and predictable.

---

## Q: Is it a good idea to overload every operator possible?

Definitely not. Operator overloading should make code **more readable**, not more confusing. I usually overload `<<` and `>>` for easy I/O, or `==` for comparing objects. But if overloading an operator doesn't feel natural—like using `+` to combine two 'Employee' objects—it's better to just use a regular member function with a clear name.

---

## 💡 Key Takeaways for the Interview

| OOP Pillar | Real-world application | Why it matters in Industry? |
| :--- | :--- | :--- |
| **Encapsulation** | Private members + Validation | Prevents bugs and invalid data states. |
| **Inheritance** | Base 'Employee' -> Derived 'Manager' | Code reuse and hierarchy organization. |
| **Polymorphism** | Virtual Functions / V-Table | Flexibility; adding new features without breaking old code. |
| **Abstraction** | Pure Virtual Functions | Defining a standard 'Contract' for teams to follow. |