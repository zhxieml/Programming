// File: operate.cpp
// This file includes the definition of all the functions relating to operation to student's information.

#include "stu_sys.h"
#include <iostream>

void add_stu()
{
    stu p;
    int id;

    cout << "Please input the information of the student in order:" << endl;
    cout << "ID:";
    cin >> id;

    bool flag = false;
    for (int i = 0; i <= stu_num; i++)
    {
        if (students[i].id == id) flag = true;
    }

    while (flag)
    {
        cout << "The id has been used. Please input another one:";
        cin >> id;
        flag = false;
        for (int i = 0; i <= stu_num; i++)
        {
            if (students[i].id == id)
            {
                flag = true;
                break;
            }
        }
    }

    p.id = id;

    cout << "Name:";
    cin >> p.name;

    cout << "Chinese score:";
    cin >> p.chi_score;

    cout << "Math score:";
    cin >> p.ma_score;

    cout << "English score:";
    cin >> p.eng_score;

    p.score = p.chi_score + p.ma_score + p.eng_score;
    students[stu_num] = p;
    students[stu_num + 1].id = -1;  //Maybe unnecessary
    stu_num++;
    cout << endl <<"Student " << stu_num << " has been successfully recorded:" << endl;
    show_one(stu_num - 1);
}

void change_stu()
{
    int i;
    int id;
    int choice;

    cout << "Please input the student ID:";
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

    cout << "Which kind of information you want to change?" << endl;
    cout << "1- Name" << endl;
    cout << "2- Chinese score" << endl;
    cout << "3- Math score" << endl;
    cout << "4- English score" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "The original name is " << students[i].name << endl;
            cout << "You want to change it into:";
            cin >> students[i].name;
            cout << students[i].name;
            break;
        case 2:
            cout << "The original Chinese score is " << students[i].chi_score << endl;
            cout << "You want to change it into:";
            cin >> students[i].chi_score;
            break;
        case 3:
            cout << "The original Math score is " << students[i].ma_score << endl;
            cout << "You want to change it into:";
            cin >> students[i].ma_score;
            break;
        case 4:
            cout << "The original English score is " << students[i].eng_score << endl;
            cout << "You want to change it into:";
            cin >> students[i].eng_score;
            break;
        default: cout << "Error: No such a choice!" << endl;
            return;
    }
    cout << endl <<"Student " << stu_num << "'s information has been successfully changed:" << endl;
}

void rank_by_id()
{
    stu new_rank[20];
	new_rank[0] = students[0];
	for (int i = 1; i < stu_num; i++) {
		if (students[i].id < new_rank[0].id) {
			for (int i1 = i - 1; i1 >= 0; i1--) new_rank[i1 + 1] = new_rank[i1];
			new_rank[0] = students[i];
			continue;
		}
		for (int j = 0; j <= i - 1; j++) {
			if (i == j + 1) new_rank[i] = students[i];
			else {
				if (students[i].id >= new_rank[j].id && students[i].id < new_rank[j + 1].id) {
					for (int k = i - 1; k >= j + 1; k--) new_rank[k + 1] = new_rank[k];
					new_rank[j + 1] = students[i];
					break;
				}
			}
		}
	}
	for (int i = 0; i < stu_num; i++) students[i] = new_rank[i];

	cout << endl <<"After re-ranking:" << endl;
	show_all();
}

void rank_by_score_desc()
{
    stu new_rank[20];
	new_rank[0] = students[0];
	for (int i = 1; i < stu_num; i++) {
		if (students[i].score > new_rank[0].score) {	// When the number is the largest one, put it in the first position;
			for (int i1 = i - 1; i1 >= 0; i1--) new_rank[i1 + 1] = new_rank[i1];
			new_rank[0] = students[i];
			continue;
		}
		for (int j = 0; j <= i - 1; j++) {
			if (i == j + 1) new_rank[i] = students[i];	// When the number is the smallest one, put it in the last position;
			else {
				if (students[i].score <= new_rank[j].score && students[i].score > new_rank[j + 1].score) {	// When the number can be put between two numbers, leave it there;
					for (int k = i - 1; k >= j + 1; k--) new_rank[k + 1] = new_rank[k];
					new_rank[j + 1] = students[i];
					break;
				}
			}
		}
	}
	for (int i = 0; i < stu_num; i++) students[i] = new_rank[i];

	cout << endl << "After re-ranking:" << endl;
	show_all();
}


void choice(int n)
{
    if (stu_num == 0 && n != 1 && n != 0)
    {
        cout << "There are no students." << endl;
        return;
    }
    switch(n)
    {
        case 1: add_stu(); break;
        case 2: change_stu(); break;
        case 3: show_all(); break;
        case 4: query_by_id(); break;
        case 5: query_by_name(); break;
        case 6: rank_by_id(); break;
        case 7: rank_by_score_desc(); break;
        case 0: exit(1);
        default: cout << "No such a choice!" << endl;
    }
}
