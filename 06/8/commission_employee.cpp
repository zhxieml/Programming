#include "commission_employee.h"
#include <iostream>
using namespace std;

CommissionEmployee::CommissionEmployee(char *n, char *i, int a, double r): Employee(n, i)
{
    amount = a;
    rate = r;
}

int CommissionEmployee::getSalary() const
{
    return (amount * rate + 0.5);   // Round the integer;
}
