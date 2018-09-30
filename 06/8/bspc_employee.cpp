#include "bspc_employee.h"
#include <iostream>
using namespace std;

BspcEmployee::BspcEmployee(char *n, char *i, int a, double r, int b): CommissionEmployee(n, i, a, r)
{
    basic = b;
}

int BspcEmployee::getSalary() const
{
    return CommissionEmployee::getSalary() + basic;
}
