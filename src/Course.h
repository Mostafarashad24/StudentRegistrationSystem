#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class student; // forward declaration

class Course
{
protected:
    string name;
    string code;
    int    minStudentLevel;
    int    creditHours;
    static int            count;
    static vector<Course*> courses;

public:
    Course();
    Course(string name, int level, int creditHours);

    string getName();
    string getCode();
    int    getMinStudentLevel();
    int    getCreditHours();

    Course* searchCourse(string s);

    friend ostream& operator<<(ostream& output, Course& c);
    friend istream& operator>>(istream& input,  student& s);
    friend ostream& operator<<(ostream& output, student& s);
};

#endif
