#include "StudentManagementSystem.h"
#include <iostream>
using namespace std;

StudentManagementSystem::StudentManagementSystem() = default;
StudentManagementSystem::~StudentManagementSystem() = default;

int StudentManagementSystem::findPersonIndexById(int id) const {
    for (size_t i = 0; i < people.size(); ++i) {
        if (people[i]->getId() == id) return static_cast<int>(i);
    }
    return -1;
}

void StudentManagementSystem::addStudent(int id, const string& name, double gpa) {
    if (findPersonIndexById(id) != -1) {
        cout << "Error: ID already exists.\n";
        return;
    }
    people.push_back(make_unique<Student>(id, name, gpa));
    cout << "Student added successfully.\n";
}

void StudentManagementSystem::addTeacher(int id, const string& name, const string& subject) {
    if (findPersonIndexById(id) != -1) {
        cout << "Error: ID already exists.\n";
        return;
    }
    people.push_back(make_unique<Teacher>(id, name, subject));
    cout << "Teacher added successfully.\n";
}

void StudentManagementSystem::addCourse(const string& code, const string& title, int credits) {
    courses.push_back(make_unique<Course>(code, title, credits));
    cout << "Course added successfully.\n";
}

void StudentManagementSystem::showAll() const {
    cout << "\n--- People (Students & Teachers) ---\n";
    if (people.empty()) cout << "No people added yet.\n";
    for (const auto& p : people) p->displayInfo();

    cout << "\n--- Courses ---\n";
    if (courses.empty()) cout << "No courses added yet.\n";
    for (const auto& c : courses) c->showCourse();
}

void StudentManagementSystem::searchPersonById(int id) const {
    int idx = findPersonIndexById(id);
    if (idx == -1) {
        cout << "No person found with ID " << id << '\n';
    }
    else {
        people[idx]->displayInfo();
    }
}

void StudentManagementSystem::removePersonById(int id) {
    int idx = findPersonIndexById(id);
    if (idx == -1) {
        cout << "No person found with ID " << id << '\n';
        return;
    }
    people.erase(people.begin() + idx);
    cout << "Person with ID " << id << " removed.\n";
}
