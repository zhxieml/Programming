#include <iostream>
#include "teacher.h"
#include "student.h"
using namespace std;
Reader *library[20];
int reader_num = 0;

int main()
{
    int i;
    cout << "Welcome to the library system!" << endl;
    while (true)
    {
        help();
        cin >> i;
        choice(i);
    }
    return 0;
}
