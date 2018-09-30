#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Date
    {
        friend bool operator>(const Date &d1, const Date &d2);
        friend bool operator<(const Date &d1, const Date &d2);
        friend ostream &operator<<(ostream &os, const Date &obj);
    private:
        int year;
        int month;
        int day;
        static const int leapMonth[12];
        static const int normalMonth[12] ;
    public:
        Date(int m = 1, int d = 1, int y = 1990);
        Date &operator++();
        Date operator++(int);
        Date &operator+=(int n);
        void setDate(int m, int d, int y);
        bool isLeap() const;
    };


#endif // DATE_H_INCLUDED
