#include "Student.h"

Student::Student()
{
    name        = "";
    id          = "";
    arrsize     = 0;
    noOfCourses = 0;
    level       = 0;
    Grades      = new Rational[7];
    courses     = new Course[7];
}

Rational Student::calculateGPA()
{
    Rational gpa;
    int num = 0, den = 0;
    for (int i = 0; i < noOfCourses; i++)
    {
        num += Grades[i].getnumerator() * courses[i].getCreditHours();
        den += courses[i].getCreditHours();
    }
    gpa.setNumerator(num);
    gpa.setDenominator(den);
    return gpa;
}

Rational Student::courseGPA(int i)
{
    Rational gpa;
    gpa.setNumerator(Grades[i].getnumerator());
    gpa.setDenominator(100);
    return gpa;
}

void Student::printRegisteredCourses()
{
    for (int i = 0; i < noOfCourses; i++)
    {
        cout << "Course " << i + 1 << ":\n------\n";
        cout << "Name        : " << courses[i].getName()            << "\n";
        cout << "Code        : " << courses[i].getCode()            << "\n";
        cout << "Level       : " << courses[i].getMinStudentLevel() << "\n";
        cout << "Credit hours: " << courses[i].getCreditHours()     << "\n";
        cout << "Grade       : " << Grades[i].getnumerator()        << "\n";
        cout << "-----------\n";
    }
}

double Student::getCourseGPA(Rational grade)
{
    int g = grade.getnumerator();
    if      (g >= 97) return 4.0;
    else if (g >= 93) return 4.0;
    else if (g >= 90) return 3.7;
    else if (g >= 87) return 3.3;
    else if (g >= 83) return 3.0;
    else if (g >= 80) return 2.7;
    else if (g >= 77) return 2.3;
    else if (g >= 73) return 2.0;
    else if (g >= 70) return 1.7;
    else if (g >= 67) return 1.3;
    else if (g >= 63) return 1.0;
    else if (g >= 60) return 0.7;
    else              return 0.0;
}

double Student::getTotalGPA()
{
    double totalGPA = 0;
    int    sum      = 0;
    for (int i = 0; i < noOfCourses; i++)
    {
        totalGPA += getCourseGPA(courseGPA(i)) * courses[i].getCreditHours();
        sum      += courses[i].getCreditHours();
    }
    if (sum == 0) return 0;
    return totalGPA / sum;
}

int Student::getLevel()       { return level; }
int Student::getNoOfCourses() { return noOfCourses; }

// ── Stream operators ────────────────────────────────────────────────────────

istream& operator>>(istream& input, Student& s)
{
    cout << "Enter student name: ";   input >> s.name;
    cout << "Enter student id: ";     input >> s.id;
    cout << "Enter student level: ";  input >> s.level;
    cout << "Enter number of courses: "; input >> s.arrsize;

    for (int i = 0; i < s.arrsize; i++)
    {
        string code;
        cout << "Enter course code " << i + 1 << ": "; input >> code;

        // searchCourse is a static-style method on any Course instance
        Course* c = s.courses[0].searchCourse(code);
        if (c != NULL)
        {
            if (!s.RegisterCourse(c))
                cout << "Error: You cannot register in this course.\n";
            else
            {
                int grade;
                cout << "Enter grade (0-100) for this course: "; input >> grade;
                s.Grades[s.noOfCourses - 1].setNumerator(grade);
            }
        }
        else
        {
            cout << "Course not found.\n";
        }
    }
    return input;
}

ostream& operator<<(ostream& output, Student& s)
{
    output << "--------------------------------------------\n";
    output << "Name           : " << s.name  << "\n";
    output << "ID             : " << s.id    << "\n";
    output << "Student level  : " << s.level << "\n";
    s.printRegisteredCourses();
    output << showpoint << setprecision(3);
    output << "Overall GPA    = " << s.getTotalGPA()           << "\n";
    output << "Expenses       = " << (int)s.CalculateExpenses() << " EGP\n";
    output << "------------------\n";
    return output;
}
