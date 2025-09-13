#pragma once
#include "Person.h"

class Teacher : public Person {
private:
    string subject;
public:
    Teacher(int id, const string& name, const string& subject);
    void setSubject(const string& s);
    string getSubject() const;

    void displayInfo() const override;
    ~Teacher();
};
#pragma once
