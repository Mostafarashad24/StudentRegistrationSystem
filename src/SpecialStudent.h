#ifndef SPECIALSTUDENT_H
#define SPECIALSTUDENT_H

#include "Student.h"

// Special Program Student:
//   - Can register any course regardless of level
//   - Max 7 courses
//   - Expenses = sum of (creditHours * 500) for each registered course
class SpecialStudent : public Student
{
public:
    bool  RegisterCourse(Course* course) override;
    float CalculateExpenses()            override;
};

#endif
