#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Student
    {
    private:
        int id;
        char name[20];
        int year;
        int month;
        int tel;
        static int total;
    public:
        Student(char *n = "", int y = 1990, int m = 1, int t = 0);
        static void addTotal();
        static void resetTotal(int n_total);
        void displayInfo() const;
    };


#endif // STUDENT_H_INCLUDED
