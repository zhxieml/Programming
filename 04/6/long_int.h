// File: long_int.h
// The head file of the long-integer library.

#ifndef LONG_INT_H_INCLUDED
#define LONG_INT_H_INCLUDED

    // Function: input
    // Method: input(char *ori_num) (Given a number in string type)
    // Effect: transform the original number into an intarray
    int *input(char *ori_num);

    // Function: add
    // Method: add(int *num1, int *num2) (Given two number in intarray type)
    // Effect: add two long-int integer
    int *add(int *num1, int *num2);

    // Function: output
    // Method: output(int *num) (Given a number in intarray type)
    // Effect: show the integer
    void output(int *num);


#endif // LONG_INT_H_INCLUDED
