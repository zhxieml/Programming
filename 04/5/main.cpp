// File: main.cpp
// The main module of the student system.

#include "stu_sys.h"
stu students[20];
int stu_num = 0;

int main()
{
    int i;
    cout << "Welcome to the student management system!" << endl;
    while (true)
    {
        help();
        cin >> i;
        choice(i);
    }
    return 0;
}
