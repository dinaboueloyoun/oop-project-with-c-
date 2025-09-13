#pragma once
#include <string>
using namespace std;


class CourseBase {
public:
    virtual ~CourseBase() {}
    virtual void showCourse() const = 0;
};

class Course : public CourseBase {
private:
    string code;
    string title;
    int credits;
public:
    Course(const string& code, const string& title, int credits);
    void showCourse() const override;
};
#pragma once
