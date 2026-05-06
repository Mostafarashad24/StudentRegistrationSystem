#ifndef NORMALCOURSE_H
#define NORMALCOURSE_H

#include "Course.h"

class NormalCourse : public Course
{
public:
    NormalCourse();
    NormalCourse(string name, int level, int creditHours);
};

#endif
