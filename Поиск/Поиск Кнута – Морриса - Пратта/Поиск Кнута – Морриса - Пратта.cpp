#include<string>
#include<iostream>
using namespace std;

int kmp(string str, string tmp)
{
    int i, j, strLen, tmpLen;
    strLen = str.size();
    tmpLen = tmp.size();
    int* d = new int[tmpLen];
    i = 0;
    j = -1;
    d[0] = -1;
    while (i < tmpLen - 1)
    {
        while ((j >= 0) && (tmp[j] != tmp[i]))
        {
            j = d[j];
        }
        i++;
        j++;
        if (tmp[i] == tmp[j])
        {
            d[i] = d[j];
        }
        else
        {
            d[i] = j;
        }
        i = 0;
        j = 0;
        for (i = 0, j = 0; (i <= strLen - 1) && (j <= tmpLen - 1); i++, j++)
        {
            while ((j >= 0) && (tmp[j] != str[i]))
            {
                j = d[j];
            }
        }
        delete[] d;
        if (j == tmpLen)
        {
            return i - j;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    string Stroka, strl;
    cout << "Введите строку: ";
    getline(cin, Stroka);
    cout << "Введите подстроку, которую нужно удалить: ";
    getline(cin, strl);
    if (kmp(Stroka, strl) != -1)
    {
        Stroka.erase(kmp(Stroka, strl) + strl.length() - 1, 1);
        cout << "Обновленная строка: " << Stroka;
    }
    else
    {
        cout << "Подстрока не найдена";
    }
}