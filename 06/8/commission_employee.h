#ifndef COMMISSION_EMPLOYEE_H_INCLUDED
#define COMMISSION_EMPLOYEE_H_INCLUDED
    #include "employee.h"
    #include <iostream>
    using namespace std;

    class CommissionEmployee: public Employee
    {
    protected:
        int amount;
        double rate;
    public:
        CommissionEmployee(char *n, char *i, int a, double r);
        virtual int getSalary() const;
    };


#endif // COMMISSION_EMPLOYEE_H_INCLUDED
