#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
    #include <iostream>
    using namespace std;

    class Rectangle
    {
    public:
        Rectangle(double l = 0, double w = 0);
        Rectangle(const Rectangle &rec);
        double getPerimeter() const;
        double getArea() const;
    protected:
        double length;
        double width;
    };


#endif // RECTANGLE_H_INCLUDED
