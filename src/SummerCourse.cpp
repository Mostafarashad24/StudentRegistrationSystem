#include "SummerCourse.h"
#include "utils.h"

SummerCourse::SummerCourse()
{
    name            = "";
    code            = "";
    minStudentLevel = 0;
    creditHours     = 0;
}

SummerCourse::SummerCourse(string name, int level, int creditHours)
    : Course(name, level, creditHours)
{
    this->code = name + "_S" + toString(level);
    courses.push_back(this);
}
