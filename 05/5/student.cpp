#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;

bool compare(studentT s1, studentT s2)  // Return 1 if s1 should rank ahead s2. Otherwise, return 0;
{
    if (s1.total_score > s2.total_score) return 1;
    if (s1.total_score < s2.total_score) return 0;

    if (s1.chi_score > s2.chi_score) return 1;
    if (s1.chi_score < s2.chi_score) return 0;

    if (s1.ma_score > s2.ma_score) return 1;
    if (s1.ma_score < s2.ma_score) return 0;

    if (s1.eng_score > s2.eng_score) return 1;
    if (s1.eng_score < s2.eng_score) return 0;

    if (strcmp(s1.name, s2.name) < 0) return 1;
    else return 0;
}

void input_n(int n)
{
    studentT s0;
    for (int i = 0; i < n; i++)
    {
        cout << "Name:";
        cin >> s0.name;

        cout << "Chinese score:";
        cin >> s0.chi_score;

        cout << "Math score:";
        cin >> s0.ma_score;

        cout << "English score:";
        cin >> s0.eng_score;

        s0.total_score = s0.chi_score + s0.ma_score + s0.eng_score;
        if (stu_num == 0)
        {
            students[0] = s0;
            stu_num++;
            continue;
        }
        ranking(s0);
        stu_num++;
    }
}

void ranking(studentT s)
{
    if (compare(s, students[0]))
    {
        for (int i1 = stu_num - 1; i1 >= 0; i1--) students[i1 + 1] = students[i1];
        students[0] = s;
        return;
    }
    for (int j = 0; j <= stu_num; j++)
    {
        if (j == stu_num) students[j] = s;
        else
        {
            if (compare(students[j], s) && compare(s, students[j + 1]))
            {
                for (int k = stu_num - 1; k >= j + 1; k--) students[k + 1] = students[k];
                students[j + 1] = s;
                break;
            }
        }
    }
}

void display(int k)
{
    cout << "Name: " << students[k].name << endl;
    cout << "Chinese score: " << students[k].chi_score << endl;
    cout << "Math score: " << students[k].ma_score << endl;
    cout << "English score: " << students[k].eng_score << endl;
}
