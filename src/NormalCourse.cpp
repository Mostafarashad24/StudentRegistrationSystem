#include "NormalCourse.h"
#include "utils.h"

NormalCourse::NormalCourse()
{
    name            = "";
    code            = "";
    minStudentLevel = 0;
    creditHours     = 0;
}

NormalCourse::NormalCourse(string name, int level, int creditHours)
    : Course(name, level, creditHours)
{
    this->code = name + "_N" + toString(level);
    courses.push_back(this);
}
