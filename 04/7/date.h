// File: date.h
// The head file of the date class

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Date
    {
    private:
        const int leapMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        const int normalMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year;
        int month;
        int day;
        bool checkValid();
    public:
        bool create(char *date);
        bool n_days_after(int n);
        void display();
    };

#endif // DATE_H_INCLUDED
