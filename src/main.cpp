#include <iostream>
using namespace std;

#include "NormalCourse.h"
#include "SummerCourse.h"
#include "GeneralStudent.h"
#include "SpecialStudent.h"

int main()
{
    // ── Pre-load all available courses ──────────────────────────────────────
    // These constructors automatically register each course into the
    // static Course::courses vector so searchCourse() can find them.
    Course* COURSES[] = {
        new NormalCourse("Math",                 1, 2),
        new NormalCourse("Programming_1",        1, 3),
        new NormalCourse("Technical_Writing",    1, 3),
        new NormalCourse("Electronics",          2, 4),
        new NormalCourse("Data_Structures",      2, 3),
        new NormalCourse("OOP",                  2, 3),
        new NormalCourse("Algorithms",           3, 2),
        new NormalCourse("Operating_Systems",    3, 3),
        new NormalCourse("Databases",            3, 3),
        new NormalCourse("Machine_Learning",     4, 3),
        new NormalCourse("Compilers",            4, 4),
        new NormalCourse("Programming_Concepts", 4, 4),
        new SummerCourse("Math",                 1, 2),
        new SummerCourse("Compilers",            4, 4),
        new SummerCourse("Algorithms",           3, 2),
        new SummerCourse("OOP",                  2, 3)
    };

    // ── Read students ────────────────────────────────────────────────────────
    int v;
    cout << "Enter total number of students: "; cin >> v;

    Student** s = new Student*[v];

    for (int i = 0; i < v; i++)
    {
        int type;
        cout << "Enter student type (0 = General, 1 = Special): "; cin >> type;

        if (type == 0)
            s[i] = new GeneralStudent();
        else
            s[i] = new SpecialStudent();

        cin >> *s[i];
    }

    // ── Print all students ───────────────────────────────────────────────────
    for (int i = 0; i < v; i++)
        cout << *s[i];

    // ── Cleanup ──────────────────────────────────────────────────────────────
    for (int i = 0; i < 16; i++) delete COURSES[i];
    for (int i = 0; i < v;  i++) delete s[i];
    delete[] s;

    return 0;
}
