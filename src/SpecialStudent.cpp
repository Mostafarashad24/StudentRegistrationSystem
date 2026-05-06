#include "SpecialStudent.h"

bool SpecialStudent::RegisterCourse(Course* course)
{
    if (noOfCourses < 7)
    {
        courses[noOfCourses] = *course;
        noOfCourses++;
        return true;
    }
    return false;
}

float SpecialStudent::CalculateExpenses()
{
    float expenses = 0;
    for (int i = 0; i < noOfCourses; i++)
        expenses += courses[i].getCreditHours() * 500;
    return expenses;
}
