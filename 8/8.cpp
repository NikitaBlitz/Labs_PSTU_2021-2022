#include <fstream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <iostream>


using namespace std;

struct book
{
    string name;
    string author;
    int year;
    int pages;
};

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    ofstream p;
    p.open("text.txt");
    int n = 6;
    book book1 = { "Война и Мир","Толстой", 1869 , 1760 };
    book book2 = { "Капитанская дочка","Пушкин", 1841 , 165 };
    book book3 = { "В мире Роблокса","Качковский", 1847 , 120 };
    book book4 = { "Мертвые души","Гоголь", 1842 , 352 };
    book book5 = { "Обломов","Гончаров", 1847 , 165 };
    book book6 = { "Тарас Бульба","Гоголь", 1835 , 320 };
    book* books = new book[n];
    books[0] = book1;
    books[1] = book2;
    books[2] = book3;
    books[3] = book4;
    books[4] = book5;
    books[5] = book6;
    book boook;
    book* newbooks = new book[1];
    newbooks[0] = boook;

    if (!p.is_open())
    {
        cout << "Ошибка открытия файла!";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            p << "название: " << books[i].name << endl << "автор: " << books[i].author << endl << "год: " << books[i].year << endl << "количество страниц: " << books[i].pages << endl << "                 " << endl;
        }
    }
    p << "Преобразовнный файл" << endl;
    p << "                 " << endl;
    if (!p.is_open())
    {
        cout << "Ошибка открытия файла!";
    }
    else
    {
        string proverka, tmp;
        int fl = 1;
        cout << "Введите названием перед каким будет добавляться элемент" << endl;
        getline(cin, proverka);
        for (int i = 3; i < n; i++)
        {
            if (books[i].name == proverka)
            {
                for (int j = 0; j < 1; j++)
                {
                    cout << "Введите название: ";
                    getline(cin, newbooks[j].name);
                    cout << "Введите автора: ";
                    getline(cin, newbooks[j].author);
                    cout << "Введите год издания: ";
                    cin >> newbooks[j].year;
                    cout << "Введите количество страниц: ";
                    cin >> newbooks[j].pages;
                    p << "название: " << newbooks[j].name << endl << "автор: " << newbooks[j].author << endl << "год: " << newbooks[j].year << endl << "количество страниц: " << newbooks[j].pages << endl << "                 " << endl;

                }
            }
            p << "название: " << books[i].name << endl << "автор: " << books[i].author << endl << "год: " << books[i].year << endl << "количество страниц: " << books[i].pages << endl << "                 " << endl;
        }
    }
}

