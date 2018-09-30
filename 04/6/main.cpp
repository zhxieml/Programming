// File: main.cpp
// The main module of the long int library.

#include <iostream>
#include "long_int.h"
using namespace std;

int main()
{
    int *num1, *num2, *sum;
    char *ori1 = "1234";
    char *ori2 = "333";
    num1 = input(ori1);
    num2 = input(ori2);
    sum = add(num1, num2);
    output(sum);
    delete [] num1;
    delete [] num2;
    delete [] sum;
    return 0;
}
