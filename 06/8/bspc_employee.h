#ifndef BSPC_EMPLOYEE_H_INCLUDED
#define BSPC_EMPLOYEE_H_INCLUDED
    #include "commission_employee.h"
    #include <iostream>
    using namespace std;

    class BspcEmployee: public CommissionEmployee
    {
    private:
        int basic;
    public:
        BspcEmployee(char *n, char *i, int a, double r, int b);
        virtual int getSalary() const;
    };


#endif // BSPC_EMPLOYEE_H_INCLUDED
