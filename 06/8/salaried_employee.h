#ifndef SALARIED_EMPLOYEE_H_INCLUDED
#define SALARIED_EMPLOYEE_H_INCLUDED
    #include "employee.h"
    #include <iostream>
    using namespace std;

    class SalariedEmployee: public Employee
    {
    private:
        int regular;
    public:
        SalariedEmployee(char *n, char *i, int r);
        virtual int getSalary() const;
    };


#endif // SALARIED_EMPLOYEE_H_INCLUDED
