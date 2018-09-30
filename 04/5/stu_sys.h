// File: stu_sys.h
// In this file, the structure "stu" is defined, and all the function phototypes are declared.

#ifndef STU_SYS_H_INCLUDED
#define STU_SYS_H_INCLUDED

    #include <iostream>
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    using namespace std;



    struct stu
    {
        int id;
        char name[20];
        int chi_score;
        int ma_score;
        int eng_score;
        int score;
    };

    extern int stu_num;
    extern stu students[20];

    void help();
    void choice(int n);
    void add_stu();
    void change_stu();
    void show_one(int i);
    void show_all();
    void query_by_id();
    void query_by_name();
    void rank_by_id();
    void rank_by_score_desc();

#endif
