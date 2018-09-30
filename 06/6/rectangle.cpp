#include <iostream>
#include "rectangle.h"
using namespace std;

Rectangle::Rectangle(double l, double w): length(l), width(w){}

Rectangle::Rectangle(const Rectangle &rec): length(rec.length), width(rec.width){}

double Rectangle::getPerimeter() const
{
    return (2 * (length + width));
}

double Rectangle::getArea() const
{
    return (length * width);
}
