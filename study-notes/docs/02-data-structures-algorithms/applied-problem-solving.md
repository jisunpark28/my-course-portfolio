---
sidebar_position: 1
title: Applied Problem Solving
---

# Applied Problem Solving

This page summarizes language-agnostic logic and algorithm design.

---

## Q: When you're given a complex problem you've never seen before, what's your first step?

I don't start coding right away. I follow the **Computational Thinking** model. First, I **Decompose** the problem—breaking a huge task into smaller, manageable chunks. Then I look for **Patterns** (have I solved something similar before?). I use **Abstraction** to strip away the irrelevant details and focus on the core logic. Finally, I design an **Algorithm** and **Test** it against edge cases. This process saves hours of debugging later because the logic is solid before the first line of code is written.

---

## Q: How do you handle a project that feels too big to manage?

I use **Decomposition** to identify 'Black Box' functions. In APS145, we learned to treat complex logic as self-contained units. For example, if I'm building a vending machine system, I’ll create a separate 'Black Box' for 'ValidatePayment' and another for 'DispenseProduct.' I don't need to know *how* they work when I'm designing the main flow; I just need to know what they take in and what they return. This makes it easier for teams to work on different parts simultaneously without stepping on each other's toes.

---

## Q: Why do you use Flowcharts or Pseudocode instead of just writing the code?

Flowcharts and Pseudocode are **language-agnostic**. They allow me to communicate my logic to anyone—even a non-technical stakeholder—without getting bogged down in syntax errors like missing semicolons. 
* **Flowcharts** are great for seeing the 'high-level' orchestration and the 'Selection' (if-else) paths.
* **Pseudocode** is where I map out the 'detailed' steps. 
By separating logic from syntax, I can ensure the solution actually works before I decide whether to implement it in C++, JavaScript, or Python.

---

## Q: Can you explain how you decide between using a loop or a conditional statement?

It's about **Control Flow**.
* **Selection** (if/else) is for choosing a path. In my 'Muffin Tax' project, I used selection to decide if a customer should be taxed based on the quantity bought. 
* **Iteration** (loops) is for repeating a task. If the number of repetitions is known (like grading 10 students), I use a **Mandatory Iteration** (For loop). If I'm waiting for a certain condition (like valid user input), I use an **Optional Iteration** (While loop). 
A common pitfall I always watch out for is the **Infinite Loop**—I always make sure my 'loop control variable' is updated inside the body!

---

## Q: How do you decide what data structure to use for storing information?

It depends on the access pattern. If I have multiple related items of the same type, I use a **Collection** (like an array). In APS145, we practiced navigating collections using standard actions like `FIRST`, `NEXT`, and `LAST`. If the data is more complex—like a student with a name, ID, and GPA—I use a **Struct**. The key is to organize variables logically so the code is readable and the data is easy to retrieve. I always avoid 'magic numbers' and use descriptive identifiers for clarity.

---

## Q: How do you know your algorithm actually works?

I use **Trace Tables** (Walkthroughs) to track variable states at every step. I don't just test the 'Happy Path'; I look for **Edge Cases**. 'What if the user enters a negative number?' 'What if the collection is empty?' In Toronto's fast-paced environment, catching a **Semantic Error** (logic bug) during the design phase is much cheaper than catching it after the software is deployed.

---

## 💡 APS Interview Summary Table

| Concept | Interview Keywords | Why Interviewers Love It |
| :--- | :--- | :--- |
| **Computational Thinking** | Decomposition, Abstraction | Shows you can solve high-level problems. |
| **Language Agnostic** | Logic over Syntax | Proves you can adapt to any tech stack. |
| **Trace Tables** | Systematic Walkthrough | Demonstrates attention to detail and accuracy. |
| **Selection/Iteration** | Efficiency, Control Flow | Shows you know how to optimize program logic. |