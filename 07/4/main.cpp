#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("file.txt");    // Set the file name here;
    int count_para = 0, count_word = 0, count_char = 0;
    char i;

    if (!infile)
    {
        cerr << "Open file error!" << endl;
        return 1;
    }

    while ((i = infile.get()) != EOF)
    {
        if (i == '\n') count_para++;
        if (i == ' ') count_word++;
        if ((i <= 'z' && i >= 'a') || (i <= 'Z' && i >= 'A') || i == ',' || i == '.') count_char++;
    }

    infile.close();

    cout << "There are " << ++count_para << " paragraphs." << endl;
    cout << "There are " << ++count_word << " words." << endl;
    cout << "There are " << count_char << " characters." << endl;
    return 0;
}
