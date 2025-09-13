#pragma once
#include "Person.h"

class Student : public Person {
private:
    double gpa;
public:
    Student(int id, const string& name, double gpa);
    void setGPA(double g);
    double getGPA() const;

    void displayInfo() const override;
    ~Student();
};
#pragma once
