#pragma once
#include <vector>
#include <memory>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

class StudentManagementSystem {
private:
    std::vector<std::unique_ptr<Person>> people;
    std::vector<std::unique_ptr<CourseBase>> courses;

    int findPersonIndexById(int id) const;

public:
    StudentManagementSystem();
    ~StudentManagementSystem();

    void addStudent(int id, const std::string& name, double gpa);
    void addTeacher(int id, const std::string& name, const std::string& subject);
    void addCourse(const std::string& code, const std::string& title, int credits);

    void showAll() const;
    void searchPersonById(int id) const;
    void removePersonById(int id);
};
#pragma once
