#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Rational.h"
#include "Course.h"
using namespace std;

class Student
{
protected:
    string   name;
    string   id;
    int      arrsize;
    int      level;
    int      noOfCourses;
    Rational* Grades;       // array of grades (one per course slot)
    Course*   courses;      // array of registered course copies

public:
    Student();
    virtual ~Student() { delete[] Grades; delete[] courses; }

    Rational calculateGPA();
    Rational courseGPA(int i);

    void   printRegisteredCourses();
    double getTotalGPA();
    double getCourseGPA(Rational grade);
    int    getLevel();
    int    getNoOfCourses();

    // Pure virtual — must be overridden by subclasses
    virtual bool  RegisterCourse(Course* course) = 0;
    virtual float CalculateExpenses()            = 0;

    friend istream& operator>>(istream& input,  Student& s);
    friend ostream& operator<<(ostream& output, Student& s);
};

#endif
