#include "employee.h"
#include <iostream>
#include <cstring>
using namespace std;

Employee::Employee(char *n, char *i): name(n), id(i){}

char *Employee::getName()
{
    return name;
}

