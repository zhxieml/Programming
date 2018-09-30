#ifndef HOURLY_EMPLOYEE_H_INCLUDED
#define HOURLY_EMPLOYEE_H_INCLUDED
    #include "employee.h"
    #include <iostream>
    using namespace std;

    class HourlyEmployee: public Employee
    {
    private:
        int hour;
        int perhour;
    public:
        HourlyEmployee(char *n, char *i, int p, int h);
        virtual int getSalary() const;
    };


#endif // HOURLY_EMPLOYEE_H_INCLUDED
