// File: show.cpp
// This file includes the definition of all the functions relating to output.


#include "stu_sys.h"
#include <iostream>

void help()
{
    cout << "Choice the following functions at your wish:" << endl;
    cout << "1- Add student information" << endl;
    cout << "2- Change student information" << endl;
    cout << "3- Show all student information" << endl;
    cout << "4- Query student information by id" << endl;
    cout << "5- Query student information by name" << endl;
    cout << "6- Rank by id" << endl;
    cout << "7- Rank by score in descending order" << endl;
    cout << "0- Exit" << endl;
}

void show_one(int i)
{

        cout << "ID:" << students[i].id << endl;
        cout << "Name:" << students[i].name << endl;
        cout << "Chinese score:" << students[i].chi_score << endl;
        cout << "Math score:" << students[i].ma_score << endl;
        cout << "English score:" << students[i].eng_score << endl;
        cout << endl;
}


void show_all()
{

    for (int i = 0; i < stu_num; i++)
    {
         cout << "Student " << i + 1 << ":\n";
        show_one(i);
    }
}

void query_by_id()
{
    int i;
    int id;
    cout << "Please input the ID:";
    cin >> id;
    for (i = 0; i < stu_num; i++)
    {
        if (students[i].id == id) break;
    }
    if (i == stu_num)
    {
        cout << "No such a student!" << endl;
        return;
    }

    cout << endl;
    show_one(i);
}

void query_by_name()
{
    int i;
    char name[20];
    cout << "Please input the Name:";
    cin >> name;
    for (i = 0; i < stu_num; i++)
    {
        if (!strcmp(name, students[i].name)) break;
    }
    if (i == stu_num)
    {
        cout << "No such a student!" << endl;
        return;
    }

    cout << endl;
    show_one(i);
}
