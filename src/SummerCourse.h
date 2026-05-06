#ifndef SUMMERCOURSE_H
#define SUMMERCOURSE_H

#include "Course.h"

class SummerCourse : public Course
{
public:
    SummerCourse();
    SummerCourse(string name, int level, int creditHours);
};

#endif
