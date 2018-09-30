#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
    #include <iostream>
    using namespace std;

    struct studentT
    {
        char name[20];
        int chi_score;
        int ma_score;
        int eng_score;
        int total_score;
    };

    extern int stu_num;
    extern studentT students[30];

    bool compare(studentT s1, studentT s2);
    void input_n(int n);
    void ranking(studentT s);
    void display(int k);

#endif // STUDENT_H_INCLUDED
