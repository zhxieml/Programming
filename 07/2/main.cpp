#include <iostream>
#include "set.h"
using namespace std;

int main()
{
    Set<char*> teacher(5);
    Set<char*> student(3);
    teacher.addElement("Bob");
    teacher.addElement("Tom");
    teacher.addElement("Tom");
    teacher.addElement("Mary");
    teacher.addElement("Grag");
    teacher.addElement("Jane");
    teacher.addElement("Tony");
    student.addElement("Tom");
    student.addElement("Bob");
    cout << "Teacher: ";
    teacher.display();
    cout << endl;
    cout << "Student: ";
    student.display();
    cout << endl;
    teacher.deleteElement("Tom");
    teacher.deleteElement("Tom");
    cout << "After deleting, Teacher: ";
    teacher.display();
    cout << endl;
    Set<char*> u = getUnion(teacher, student);
    Set<char*> i = getIntersection(teacher, student);
    cout << "Union of Teacher and Student: ";
    u.display();
    cout << endl;
    cout << "Intersection of Teacher and Student: ";
    i.display();
    cout << endl;
    i.setLength(10);    // Reset the length of the set for further convenience;
    return 0;
}
