#include "square.h"
#include <iostream>
using namespace std;

Square::Square(double l): Rectangle(l, l){}

double Square::getSideLength() const
{
    return length;
}
