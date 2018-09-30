#include "hourly_employee.h"
#include <iostream>
using namespace std;

HourlyEmployee::HourlyEmployee(char *n, char *i, int p, int h): Employee(n, i)
{
    perhour = p;
    hour = h;
}

int HourlyEmployee::getSalary() const
{
    if (hour <= 40) return perhour * hour;
    else return perhour * 40 + 2 * perhour * (hour - 40);
}
