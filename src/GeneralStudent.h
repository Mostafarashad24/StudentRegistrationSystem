#ifndef GENERALSTUDENT_H
#define GENERALSTUDENT_H

#include "Student.h"

// General Program Student:
//   - Can only register courses at or below their level
//   - Max 7 courses
//   - Expenses = level * 1000 EGP (flat fee per level)
class GeneralStudent : public Student
{
public:
    bool  RegisterCourse(Course* course) override;
    float CalculateExpenses()            override;
};

#endif
