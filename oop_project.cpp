#include <iostream>
#include <limits>
#include <cctype>
#include "StudentManagementSystem.h"
using namespace std;

void clearInputLine() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool isValidName(const string& name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ')
            return false;
    }
    return !name.empty();
}

int main() {
    StudentManagementSystem sms;
    int choice = 0;

    while (true) {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Add Course\n";
        cout << "4. Show All\n";
        cout << "5. Search Person by ID\n";
        cout << "6. Remove Person by ID\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            clearInputLine();
            continue;
        }

        if (choice == 1) {
            int id;
            double gpa;
            string name;

            // ID input
            while (true) {
                cout << "Enter Student ID: ";
                if (cin >> id) break;
                cout << "Invalid input. Enter numbers only.\n";
                cin.clear();
                clearInputLine();
            }
            clearInputLine();

            // Name input
            while (true) {
                cout << "Enter Student Name: ";
                getline(cin, name);
                if (isValidName(name)) break;
                cout << "Invalid name. Please enter letters only.\n";
            }

            // GPA input
            while (true) {
                cout << "Enter GPA: ";
                if (cin >> gpa) break;
                cout << "Invalid input. Enter numbers only.\n";
                cin.clear();
                clearInputLine();
            }
            clearInputLine();

            sms.addStudent(id, name, gpa);
        }
        else if (choice == 2) {
            int id;
            string name, subject;

            // ID input
            while (true) {
                cout << "Enter Teacher ID: ";
                if (cin >> id) break;
                cout << "Invalid input. Enter numbers only.\n";
                cin.clear();
                clearInputLine();
            }
            clearInputLine();

            // Name input
            while (true) {
                cout << "Enter Teacher Name: ";
                getline(cin, name);
                if (isValidName(name)) break;
                cout << "Invalid name. Please enter letters only.\n";
            }

            // Subject input
            cout << "Enter Subject: ";
            getline(cin, subject);

            sms.addTeacher(id, name, subject);
        }
        else if (choice == 3) {
            string code, title;
            int credits;

            cout << "Enter Course Code: "; cin >> code; clearInputLine();
            cout << "Enter Course Title: "; getline(cin, title);

            while (true) {
                cout << "Enter Credits: ";
                if (cin >> credits) break;
                cout << "Invalid input. Enter numbers only.\n";
                cin.clear();
                clearInputLine();
            }
            clearInputLine();

            sms.addCourse(code, title, credits);
        }
        else if (choice == 4) {
            sms.showAll();
        }
        else if (choice == 5) {
            int id;
            while (true) {
                cout << "Enter ID to search: ";
                if (cin >> id) break;
                cout << "Invalid input. Enter numbers only.\n";
                cin.clear();
                clearInputLine();
            }
            clearInputLine();
            sms.searchPersonById(id);
        }
        else if (choice == 6) {
            int id;
            while (true) {
                cout << "Enter ID to remove: ";
                if (cin >> id) break;
                cout << "Invalid input. Enter numbers only.\n";
                cin.clear();
                clearInputLine();
            }
            clearInputLine();
            sms.removePersonById(id);
        }
        else if (choice == 7) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
