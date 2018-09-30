#include <iostream>
#include "student.h"
using namespace std;
int stu_num;
studentT students[30];  // The score list;

int main()
{
    input_n(3); // Input 3 students' information;
    cout << endl;
    display(2);  // Display second student's information in the score list;
    return 0;
}
