# 🎓 Student Registration System

A C++ object-oriented student course registration system with a modern web-based GUI.

## 📋 Features

- Register **General** and **Special** program students
- Auto-filter available courses based on student level
- Calculate weighted **GPA** per student
- Calculate **expenses** based on student type
- Support for **Normal** and **Summer** courses
- Modern **HTML/CSS/JS GUI** — runs in any browser, no installation needed

## 🏗️ Project Structure

```
StudentRegistrationSystem/
│
├── src/                        # C++ source files
│   ├── main.cpp                # Entry point
│   ├── Student.h / .cpp        # Abstract base class for students
│   ├── GeneralStudent.h / .cpp # General program student
│   ├── SpecialStudent.h / .cpp # Special program student
│   ├── Course.h / .cpp         # Base class for courses
│   ├── NormalCourse.h / .cpp   # Normal semester course
│   ├── SummerCourse.h / .cpp   # Summer course
│   ├── Rational.h / .cpp       # Rational number class for GPA
│   └── utils.h                 # Utility functions
│
└── gui/
    └── student_system_gui.html # Standalone web GUI
```

## 🧱 Class Hierarchy

```
Course
├── NormalCourse
└── SummerCourse

Student (abstract)
├── GeneralStudent
└── SpecialStudent

Rational
```

## ⚙️ How to Compile & Run (C++)

Make sure you have `g++` installed, then run:

```bash
g++ -std=c++11 Rational.cpp Course.cpp NormalCourse.cpp SummerCourse.cpp Student.cpp GeneralStudent.cpp SpecialStudent.cpp main.cpp -o student_system
```

Then run:

```bash
# Windows
.\student_system.exe

# Linux / Mac
./student_system
```

## 🌐 How to Use the GUI

1. Download `gui/student_system_gui.html`
2. Open it in any browser (Chrome, Edge, Firefox)
3. No server or installation needed — works completely offline

## 📐 OOP Concepts Used

| Concept | Where used |
|---|---|
| Inheritance | `GeneralStudent`, `SpecialStudent` extend `Student` |
| Polymorphism | `RegisterCourse()` and `CalculateExpenses()` overridden in subclasses |
| Abstraction | `Student` is an abstract class with pure virtual methods |
| Encapsulation | All data members are `protected`/`private` with getters |
| Operator Overloading | `>>` and `<<` for input/output, arithmetic for `Rational` |
| Static Members | `Course::count` and `Course::courses` shared across all instances |

## 👨‍💻 Student Types

| Type | Course restriction | Expenses |
|---|---|---|
| General | Can only register courses ≤ their level | Level × 1000 EGP |
| Special | Can register any course regardless of level | Sum of (credit hours × 500 EGP) |

## 📚 Available Courses

| Course | Level | Credits | Type |
|---|---|---|---|
| Math | 1 | 2 | Normal & Summer |
| Programming 1 | 1 | 3 | Normal |
| Technical Writing | 1 | 3 | Normal |
| Electronics | 2 | 4 | Normal |
| Data Structures | 2 | 3 | Normal |
| OOP | 2 | 3 | Normal & Summer |
| Algorithms | 3 | 2 | Normal & Summer |
| Operating Systems | 3 | 3 | Normal |
| Databases | 3 | 3 | Normal |
| Machine Learning | 4 | 3 | Normal |
| Compilers | 4 | 4 | Normal & Summer |
| Programming Concepts | 4 | 4 | Normal |

## 🛠️ Built With

- C++11
- HTML / CSS / JavaScript (GUI)
