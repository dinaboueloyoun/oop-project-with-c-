#include "Person.h"

Person::Person(int id, const string& name) : id(id), name(name) {}
Person::~Person() {}

int Person::getId() const { return id; }
string Person::getName() const { return name; }
void Person::setName(const string& newName) { name = newName; }
