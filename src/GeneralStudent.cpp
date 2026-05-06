#include "GeneralStudent.h"

bool GeneralStudent::RegisterCourse(Course* course)
{
    if (level >= course->getMinStudentLevel() && noOfCourses < 7)
    {
        courses[noOfCourses] = *course;
        noOfCourses++;
        return true;
    }
    return false;
}

float GeneralStudent::CalculateExpenses()
{
    return (float)(level * 1000);
}
