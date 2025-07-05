# 🎓 Student Management System Projects – C++

Two C++ console applications for managing student records. Each project offers a simple text-based interface to add, edit, delete, search, and display student information. The second version organizes the logic into reusable functions and a custom header file using a namespace.

---

## 📁 Project 1: Simple Student Manager

A standalone C++ app where student records are stored in memory using `struct` and `vector`. It supports:

### ✅ Features:
- Add new student records
- Edit full or partial student info
- Delete student by ID
- Search by ID or name
- Display all students sorted by:
  - ID
  - Name
  - Grade

### 📦 Structure:
- `main.cpp` – All logic in one file
- Uses `struct stStudents` and enums for readability

---

## 📁 Project 2: Modular Student Manager (with Header)

A cleaner, modular version of the student manager. It separates declarations and functions into a header file using a namespace:

### ✅ Features:
- Same core functionality as Project 1
- Clean and organized code with:
  - `Header.h` – All logic and data structures
  - `main.cpp` – Only main function call

### 🧠 Benefits:
- Easy to scale and maintain
- Separated logic for better readability

---

## 🚀 How to Run

1. Open in your favorite C++ IDE or compile via terminal.
2. Compile:
   ```sh
   g++ main.cpp -o StudentManager
