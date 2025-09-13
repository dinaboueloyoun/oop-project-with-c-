#pragma once
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
public:
    Person(int id, const string& name);
    virtual ~Person();

    int getId() const;
    string getName() const;
    void setName(const string& newName);

    virtual void displayInfo() const = 0; // abstract
};
#pragma once
