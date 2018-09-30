#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Employee
    {
    protected:
        char *name;
        char *id;
    public:
        Employee(char *n, char *i);
        char *getName();
        virtual int getSalary() const = 0;
    };


#endif // EMPLOYEE_H_INCLUDED
