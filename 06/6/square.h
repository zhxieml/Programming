#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
    #include "rectangle.h"
    #include <iostream>
    using namespace std;

    class Square:public Rectangle
    {
    public:
        Square(double l = 0.0);
        Square(const Square &s);
        double getSideLength() const;
    };


#endif // SQUARE_H_INCLUDED
