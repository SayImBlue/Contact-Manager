# 📇 Contact Manager (C++ Project)

A simple command-line contact manager using modern C++ (RAII, STL, and file I/O).  
This is part of my **6-month C++ mastery roadmap – Week 1 Mini Project**.

## 🚀 Features
- Add / Delete / Update contacts
- Save & Load from file (`contacts.txt`)
- Sort alphabetically or by creation order
- Search by partial name (case-insensitive)
- Persistent data between runs

## 🧩 Tech
- Language: **C++17**
- STL: `vector`, `fstream`, `algorithm`, `accumulate`
- No external libraries

## 🗂️ Structure
ContactManager/
├── include/
│ └── Contact.h
├── src/
│ ├── Contact.cpp
│ └── main.cpp
├── data/
│ └── contacts.txt


## 💻 Build
Compile using g++:
```bash
g++ src/*.cpp -Iinclude -o ContactManager
./ContactManager
🧠 Author
Made by Al Farouk Benrami – Big Data & AI Future Engineer at Euromed Fès.

---

## 🧹 `.gitignore`

```gitignore
# Compiled binaries
*.exe
*.out
*.o

# OS junk
.DS_Store
Thumbs.db

# Data
/data/contacts.txt