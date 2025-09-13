#include "Course.h"
#include <iostream>
using namespace std;

Course::Course(const string& code, const string& title, int credits)
    : code(code), title(title), credits(credits) {
}

void Course::showCourse() const {
    cout << "Course | Code: " << code << " | Title: " << title
        << " | Credits: " << credits << endl;
}
