#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED
    #include "reader.h"
    #include <iostream>
    using namespace std;

    class Teacher: public Reader
    {
    public:
        Teacher(int n = 0, char *nm = "xxx", char *d = "xxx");
        virtual void borrowBook(int bookNo);
        virtual void returnBook(int bookNo);
    };


#endif // TEACHER_H_INCLUDED
