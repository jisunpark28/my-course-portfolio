---
title: Working with Files and Directories
groups: [OPS102]
topic: command
compare: [linux, windows]
tags: [cli, path, mkdir, cd, ls, dir]
---

Linux는 경로가 대소문자를 구분하고 `/`를 씁니다. Windows는 대소문자를 구분하지 않고 `\`를 씁니다.

## Directory tree

예시 루트

- Linux: `/home/jpark295/ops102`
- Windows: `C:\Users\jisun\ops102`

`ops102` 안에 `lab2/`가 있고, `lab2` 안에 `first/`, `second/`, `third/`가 있습니다.

```bash
tree -F ops102
```

```bat
tree /f ops102
```

## Path navigation

| Operation | Linux (case-sensitive) | Windows (case-insensitive) |
|-----------|------------------------|----------------------------|
| Absolute path | `ls -l /home/jpark295/ops102/lab2/third` | `dir C:\Users\jisun\ops102\lab2\third` |
| Home path (`~`) | `ls -l ~/ops102/lab2/third` | — |
| Relative path | `ls -l lab2/third` 또는 `ls -l ./lab2/third` | `dir lab2\third` 또는 `dir .\lab2\third` |
| Show current directory | `pwd` | `cd` |
| Change directory | `cd (name)` | `cd (name)` |
| Go to root | `cd /` | `cd \` 또는 `cd C:\` |
| Go to home | `cd ~` | `cd C:\Users\jisun` |
| Parent directory | `cd ..` | `cd ..` |
| Previous directory | `cd -` | — |
| List files | `ls` | `dir` |
| List long format | `ls -l` | `dir`에 포함 |
| List directory info only | `ls -ld` | — |

## File and directory manipulation

| Operation | Linux | Windows |
|-----------|-------|---------|
| Create directory | `mkdir (name)` | `mkdir (name)` |
| Remove empty directory | `rmdir (name)` | `rmdir (name)` |
| Remove file | `rm (name)` | `del (name)` |
| Remove dir and contents | `rm -rf (name)` | `rmdir /s (name)` |
| Create empty file | `touch (name)` | `copy nul (name)` |
| Copy file | `cp (name) (dir)` | `copy (name) (dir)` |
| Move file | `mv (name) (dir)` | `move (name) (dir)` |

## View file content

| Operation | Linux | Windows |
|-----------|-------|---------|
| View content | `cat (name)` | `type (name)` |
| Paging | `more (name)` | `type (name) \| more` |
| Paging (advanced) | `less (name)` | — |
