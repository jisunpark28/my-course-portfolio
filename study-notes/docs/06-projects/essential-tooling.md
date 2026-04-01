---
sidebar_position: 1
title: Essential Tooling & Collaboration 
---

# Essential Tooling: Collaboration & Workflow

This page summarizes the managing the code, collaborating with a team, and using AI ethically

---

## Q: How would you explain the difference between Git and GitHub to a non-technical stakeholder?

I like to use the **Notebook and Garage analogy**. 
* **Git** is like my personal notebook. It tracks every change I make, allowing me to 'rewind time' if I make a mistake. It lives on my local computer. 
* **GitHub** is like a shared professional garage or a cloud-based library. It’s where I push my notebook so the whole team can read it, suggest improvements via **Pull Requests**, and build the final product together. Git is the engine; GitHub is the platform that hosts the car.

---

## Q: Tell me about a time you ran into a merge conflict. How did you resolve it?

Merge conflicts are a natural part of team collaboration. I remember a lab where two of us edited the same line in a configuration file. 
My approach is always:
1. **Communicate**: I talk to my teammate to understand why they made their change.
2. **Resolve**: I use VS Code's conflict editor to compare 'Current Change' vs. 'Incoming Change' and manually pick the best version (or a mix of both).
3. **Test**: I never just commit the fix; I always rebuild the project to ensure the merge didn't break the logic. 
In a professional setting, I try to avoid big conflicts by **pulling frequently** and keeping my branches focused on single features.

---

## Q: Before you start coding a new project, what tools do you set up and why?

I follow a **Development Environment Setup Plan**. 
First, I choose the right **IDE**—for native Windows apps, I prefer **Visual Studio** for its robust debugger, but for web projects, **VS Code** is my go-to due to its flexibility. 
Then, I set up **Git with SSH keys** for secure operations. I also believe in documenting the setup for the team (like a README or a setup checklist), so every member has the exact same compiler version and extensions. This prevents the 'it works on my machine' excuse later on.

---

## Q: Why is it important to check a library's license before using it in a commercial project?

Licensing is about **legal and ethical integrity**. 
* **Permissive licenses** (like **MIT** or **BSD**) are great for business because they allow me to use and modify code with very few restrictions. 
* **Copyleft licenses** (like **GPL**), however, might require my entire project to become open source, which could be a huge issue for a company's intellectual property. 
I always check the license to treat others' work the way I'd want mine to be treated and to protect my employer from legal risks.

---

## Q: We use AI tools in our workflow. What are your thoughts on AI ethics and how do you ensure your prompts are effective?

AI is a powerful assistant, but I use it with a **'Human-in-the-loop'** mindset. 
Ethically, I'm careful about **Privacy** (never pasting sensitive client data into a prompt) and **Bias** (recognizing that AI might suggest outdated or unfair patterns). 
Regarding efficiency, I use **Prompt Engineering**. Instead of asking 'Fix this code,' I provide **Context** (what the code is for), **Constraints** (what libraries to use), and **Desired Output** (how I want the response formatted). I always verify the AI's output because, at the end of the day, I am the one responsible for the code's quality.

---

## 💡 CEP Interview Key Terms Table

| Concept | Key Tool/Process | Professional Impact |
| :--- | :--- | :--- |
| **Revision Control** | `git commit`, `git bisect` | Ensures a clean, traceable history of the project. |
| **Branching** | Feature Branch Workflow | Allows multiple devs to work without stepping on toes. |
| **Verification** | Human-in-the-Loop / Audit Trails | Ensures AI-generated code is safe and ethical. |
| **Project Management** | Jira / GitHub Issues | Keeps the team organized and goals clear. |