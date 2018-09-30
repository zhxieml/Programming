#include <iostream>
#include "square.h"
using namespace std;

int main()
{
    Square s1(3);
    cout << "The side length is: " << s1.getSideLength() << endl;
    cout << "The perimeter is: " << s1.getPerimeter() << endl;
    cout << "The area is: " << s1.getArea() << endl;
    return 0;
}
