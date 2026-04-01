---
sidebar_position: 1
title: OS & Shell Scripting
---

# Operating Systems & Automation 

This page summarizes the environment where the code interacts with the OS using CLI and automate repetitive tasks using Bash and CMD scripts.

---

## Q: In your own words, why do we need an Operating System?

Think of an OS as a **Resource Manager**. It handles four main jobs: managing and separating resources (CPU, RAM, Storage), providing hardware abstraction so I don't have to write different code for every speaker or disk, enforcing security policies, and maintaining a consistent programming model. Without an OS, my program would have to compete manually with others for memory, which would be a total disaster.

---

## Q: How do you identify and handle a process that is hogging system resources?

I use monitoring tools to check the 'Big Three' resources: CPU, Memory, and I/O. 
* On **Linux**, I use the `top` command to see real-time usage. If a process needs to be stopped, I use `kill [PID]`.
* On **Windows**, I can use the **Task Manager** or the `tasklist` and `taskkill` commands in the CMD shell. 
The goal isn't just to kill programs, but to understand if a process is 'stuck' or just needs more resources to finish its job.

---

## Q: What's the difference between an absolute and a relative pathname, and why does it matter for your scripts?

This is a classic pitfall! 
* An **Absolute Pathname** starts from the root (`/` on Linux, `C:\` on Windows). It’s unambiguous—it always points to the same place. 
* A **Relative Pathname** starts from my **Current Working Directory**. 
When I write scripts, I prefer absolute paths for critical files so the script doesn't break if I run it from a different folder. Also, I always remember that Linux is **case-sensitive** (File.txt != file.txt), while Windows usually isn't.

---

## Q: When do you decide to write a script instead of just typing commands?

I follow the **'25-step rule'** I learned at Seneca. If I have to perform a multi-step process—like compiling, testing, and moving files—repeatedly, it's more efficient and less error-prone to automate it. A shell script (Bash or `.cmd`) ensures the exact same steps are followed every time. It converts a manual, boring task into a single command, which is a huge productivity win for the whole team.

---

## Q: Can you explain how Linux file permissions work?

Linux uses a simple but powerful model based on three communities: **User (Owner), Group, and Other (UGO)**. 
Each has three permissions: **Read (4), Write (2), and eXecute (1)**. 
If I see permissions like `640`, I know:
* The **User** can read and write (4+2=6).
* The **Group** can only read (4).
* **Others** have no access (0).
For directories, 'Execute' is special—it's what allows me to 'enter' or `cd` into that folder.

---

## Q: How do you chain multiple commands together in a terminal?

I use **Piping (`|`)** and **Redirection (`>`, `>>`)**. 
Piping takes the `stdout` of one command and feeds it directly into the `stdin` of the next. For example, `ls -l | grep ".c"` lets me filter a long list to see only C files. 
Redirection is for saving output to a file. I use `>` to overwrite and `>>` to append. It's an essential skill for logging errors or generating reports automatically.

---

## 💡 OPS Interview Cheat Sheet

| Concept | Key Tool/Command | Why it matters? |
| :--- | :--- | :--- |
| **Monitoring** | `top` / `tasklist` | Keeping the system healthy and fast. |
| **Permissions** | `chmod` / `umask` | Protecting sensitive data and system files. |
| **Scripting** | `#!/usr/bin/bash` | Automating repetitive dev workflows. |
| **Filtering** | `grep` / `cut` / `tr` | Finding the needle in a haystack of data. |
| **Wildcards** | `*`, `?`, `[ ]` | Managing multiple files efficiently (Globbing). |