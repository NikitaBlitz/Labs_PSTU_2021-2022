#include <iostream>
#include <ctime>
using namespace std;



int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int key, size=10, count = 1, tmp, newsize=0;
	cout << "Введите размер массива:";
	int mas[10] = {};
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand()%10;
	}
	cout << "Сгенерированный массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << mas[i]<<"   ";
	}
	cout << endl;
	cout << "Введите ключ поиска: ";
	cin >> key;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] != key)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	cout << count<<endl;
	tmp = mas[0];
	mas[0] = mas[count-1];
	mas[count-1] = tmp;
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << "   ";
	}
}
