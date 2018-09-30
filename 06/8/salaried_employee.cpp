#include "salaried_employee.h"
#include <iostream>
using namespace std;

SalariedEmployee::SalariedEmployee(char *n, char *i, int r): Employee(n, i)
{
    regular = r;
}

int SalariedEmployee::getSalary() const
{
    return regular;
}
