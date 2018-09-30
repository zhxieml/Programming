#include "student.h"
#include "teacher.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void help()
{
    cout << "Choice the following functions at your wish:" << endl;
    cout << "1- Add reader" << endl;
    cout << "2- Borrow books" << endl;
    cout << "3- Return books" << endl;
    cout << "4- Show the books borrowed" << endl;
    cout << "0- Exit" << endl;
}

void add_reader()
{
    Reader *r;
    int choice;
    char *n;
    char *d;
    n = new char[10];
    d = new char[50];

    int id;

    cout << "Please provide the following information:" << endl;
    cout << "ID:";
    cin >> id;

    bool flag = false;
    for (int i = 0; i < reader_num; i++)
    {
        if (library[i]->getID() == id) flag = true;
    }

    while (flag)
    {
        cout << "The id has been used. Please input another one:";
        cin >> id;
        flag = false;
        for (int i = 0; i < reader_num; i++)
        {
            if (library[i]->getID() == id)
            {
                flag = true;
                break;
            }
        }
    }

    cout << "Name:";
    cin >> n;

    cout << "Department:";
    cin >> d;

    cout << "Please input the type of reader(0 for teacher; any other integer for student):";
    cin >> choice;
    if (choice == 0)
    {
        library[reader_num] = new Teacher(id, n, d);
    }

    else
    {
        library[reader_num] = new Student(id, n, d);
    }

    delete [] n;
    delete [] d;
    cout << endl <<"Reader no." << library[reader_num]->getID() << " has been successfully recorded:" << endl;
    reader_num++;
}

void borrowbook()
{
    int id;
    int num;
    cout << "Please input the reader ID:";
    cin >> id;

    int i;

    for (i = 0; i < reader_num; i++)
    {
        if (library[i]->getID() == id) break;
    }

    if (i == reader_num)
    {
        cout << "No such a reader!" << endl;
        return;
    }

    cout << "Please input the book ID:";
    cin >> num;
    library[i]->borrowBook(num);
}

void returnbook()
{
    int id;
    int num;
    cout << "Please input the reader ID:";
    cin >> id;

    int i;

    for (i = 0; i < reader_num; i++)
    {
        if (library[i]->getID() == id) break;
    }

    if (i == reader_num)
    {
        cout << "No such a reader!" << endl;
        return;
    }

    cout << "Please input the book ID:";
    cin >> num;
    library[i]->returnBook(num);
}

void showBorrowed()
{
    for (int i = 0; i < reader_num; i++)
    {
        cout << "Reader no." << library[i]->getID() << " has borrowed:" << endl;
        for (int j = 0; j < library[i]->getBorrowNum(); j++)
        {
            cout << "Book no." << library[i]->getRecord()[j] << endl;
        }
    }
}

void choice(int n)
{
    if (reader_num == 0 && n != 1 && n != 0)
    {
        cout << "There are no readers." << endl;
        return;
    }
    switch(n)
    {
        case 1: add_reader(); break;
        case 2: borrowbook(); break;
        case 3: returnbook(); break;
        case 4: showBorrowed(); break;
        case 0: exit(1);
        default: cout << "No such a choice!" << endl;
    }
}
