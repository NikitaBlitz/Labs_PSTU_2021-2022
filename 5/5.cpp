#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Ru");
    int maxDouble = 0, n = 0, max = 0;
    cout << "Введите количество строк: ";
    cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    cout <<"              " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int q = i+1 ; q < n; q++)
            {
                for (int w = 0; w < n; w++)
                {
                    if (a[i][j] == a[q][w])
                    {
                        maxDouble = a[i][j];
                        if (maxDouble > max)
                        {
                            max = maxDouble;
                        }
                    }
                }
            }
        }
    }
    cout << "              " << endl;
    if (max != 0)
    {
        cout << "Максимальное число из повторяющихся = " << max << endl;
    }
    else
    {
        cout << "Повторяющиеся числа в массиве - отсутствуют" << endl;
    }
}