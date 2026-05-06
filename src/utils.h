#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

// Converts a positive integer to its string representation
inline string toString(int s)
{
    if (s == 0) return "0";
    string ss;
    while (s > 0)
    {
        ss = char(s % 10 + '0') + ss;
        s /= 10;
    }
    return ss;
}

#endif
