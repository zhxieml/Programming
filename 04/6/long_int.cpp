// File: long_int.cpp
// This file realizes the long_int library.

#include <iostream>
#include <cstring>
#include "long_int.h"
using namespace std;

// Function: input
// This function transform the string integer into the array integer
int *input(char *ori_num)
{
    int *new_num;
    new_num = new int[100];
    int len = strlen(ori_num);
    for (int i  = len - 1; i >= 0; i--) new_num[len - i - 1] = ori_num[i] - '0';
    for (int i = len; i < 100; i++) new_num[i] = 0;
    return new_num;
}

// Function: add
// This function add two array integer
int *add(int *num1, int *num2)
{
    int *sum;
    int j = 0;
    int tmp;
    sum = new int[100];
    for (int i = 0; i < 100; i++)
    {
        tmp = num1[i] + num2[i] + j;
        j = tmp / 10;
        sum[i] = tmp % 10;
    }
    return sum;
}

// Function: output
// This function output the array integer
void output(int *num)
{
    for (int i = 99; i >= 0; i--)
    {
        if (num[i] != 0) cout << num[i];
    }
}
