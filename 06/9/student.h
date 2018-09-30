#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
    #include "reader.h"
    #include <iostream>
    using namespace std;

    class Student: public Reader
    {
    public:
        Student(int n = 0, char *nm = "xxx", char *d = "xxx");
        virtual void borrowBook(int bookNo);
        virtual void returnBook(int bookNo);
    };


#endif // STUDENT_H_INCLUDED
