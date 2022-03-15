#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    char alp[] = "zqswxcdrfvtgbhnjmkp,l.;/'[]";
    int s = 0;
    ifstream in("File1.txt");
    ofstream out("File2.txt");
    string line, firstWord, word, ls;
    while (getline(in, line))
    {
        stringstream ss(line);
        bool f = false;
        ss >> firstWord;
        while (ss >> word && !f)
        {
            if (word == firstWord)
            {
                f = true;
            }
        }
        if (f)
        {
            out << line << endl;
            ls = line;
        }
    }
    in.close();
    out.close();
    ifstream in2("File2.txt");
    cout << ls << "\n";
    for (int i = 0; i < ls.length(); i++)
    {
        for (int j = 0; j < strlen(alp); j++)
        {
            if (ls[i] == alp[j])
            {
                s += 1;
            }
        }
    }
    in2.close();
    cout << "кол-во согласных: " << s;
}