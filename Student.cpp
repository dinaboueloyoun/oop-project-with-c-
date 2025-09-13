#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(int id, const string& name, double gpa)
    : Person(id, name), gpa(gpa) {
}

void Student::setGPA(double g) { gpa = g; }
double Student::getGPA() const { return gpa; }

void Student::displayInfo() const {
    cout << "Student | ID: " << id << " | Name: " << name
        << " | GPA: " << gpa << endl;
}

Student::~Student() {}
