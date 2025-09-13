#include "Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher(int id, const string& name, const string& subject)
    : Person(id, name), subject(subject) {
}

void Teacher::setSubject(const string& s) { subject = s; }
string Teacher::getSubject() const { return subject; }

void Teacher::displayInfo() const {
    cout << "Teacher | ID: " << id << " | Name: " << name
        << " | Subject: " << subject << endl;
}

Teacher::~Teacher() {}
