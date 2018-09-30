#include "student.h"
#include "assert.h"
#include <iostream>
using namespace std;

Student::Student(int n, char *nm, char *d): Reader(n, nm, d)
{
    for (int i = 0; i < 5; i++) record[i] = 0;
}

void Student::borrowBook(int bookNo)
{
    if (borrow_num == 5)
    {
        cout << "No more books!" << endl;
        return;
    }
    record[borrow_num] = bookNo;
    cout << "Book no." << bookNo << " borrowed successfully!" << endl;
    borrow_num++;
}

void Student::returnBook(int bookNo)
{
    for (int i = 0; i < borrow_num; i++)
    {
        if (record[i] == bookNo)
        {
            cout << "Book no." << bookNo << " returned successfully!" << endl;
            for (int j = i + 1; j < borrow_num; j++) record[j - 1] = record[j];
            borrow_num--;
            record[borrow_num] = 0;
            return;
        }
    }
    cout << "No such a book!" << endl;
}
