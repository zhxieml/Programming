#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("score.txt");   // Set the file name here;
    ofstream outfile("final.txt");
    char id[11];
    int chi_score, ma_score, eng_score;


    if (!infile)
    {
        cerr << "Open file error!" << endl;
        return 1;
    }

    while (infile >> id >> chi_score >> ma_score >> eng_score)
    {
        outfile << id << ' ' << chi_score << ' ' << ma_score << ' ' << eng_score << ' ' << chi_score + ma_score + eng_score << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
