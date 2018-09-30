#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;

int Student::total = 0;

Student::Student(char *n, int y, int m, int t): id(total), year(y), month(m), tel(t)
{
    strcpy(name, n);
}

void Student::addTotal()
{
    ++total;
}

void Student::resetTotal(int n_total)
{
    total = n_total;
}

void Student::displayInfo() const
{
    cout << "Student No." << id << ": " << endl;
    cout << "Name: " << name << "\t";
    cout << "Date of birth: " << year << "/" << month << "\t";
    cout << "Tel:" << tel << endl;
}
