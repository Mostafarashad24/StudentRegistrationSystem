#include "Course.h"

// Static member definitions
int             Course::count = 0;
vector<Course*> Course::courses;

Course::Course()
{
    name             = "";
    code             = "";
    minStudentLevel  = 0;
    creditHours      = 0;
}

Course::Course(string name, int level, int creditHours)
{
    this->name            = name;
    this->minStudentLevel = level;
    this->creditHours     = creditHours;
    count++;
}

string Course::getName()            { return name; }
string Course::getCode()            { return code; }
int    Course::getMinStudentLevel() { return minStudentLevel; }
int    Course::getCreditHours()     { return creditHours; }

Course* Course::searchCourse(string s)
{
    for (int i = 0; i < (int)courses.size(); i++)
    {
        if (courses[i]->getCode() == s)
            return courses[i];
    }
    return NULL;
}

ostream& operator<<(ostream& output, Course& c)
{
    output << "Course name        : " << c.name            << "\n"
           << "Course code        : " << c.code            << "\n"
           << "Min student level  : " << c.minStudentLevel << "\n"
           << "Credit hours       : " << c.creditHours;
    return output;
}
