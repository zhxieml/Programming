#include <iostream>
#include "bspc_employee.h"
#include "commission_employee.h"
#include "hourly_employee.h"
#include "salaried_employee.h"
using namespace std;

int main()
{
    SalariedEmployee salariedEmployee("John", "111111111", 800 );
    HourlyEmployee hourlyEmployee("Tom", "222222222", 16, 50 );
    CommissionEmployee commissionEmployee("Sue", "333333333", 10000, .06 );
    BspcEmployee  basePlusCommissionEmployee("Bob", "444444444", 5000, .04, 300 );

    Employee *em[4] = {&salariedEmployee, &hourlyEmployee, &commissionEmployee, &basePlusCommissionEmployee};
    for (int i = 0; i < 4; i++)
    {
        cout << "Name: " << em[i]->getName() << endl;
        cout << "Salary: " << em[i]->getSalary() << endl;
    }
    return 0;
}
