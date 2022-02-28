#include <iostream>
#include <ctime>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
	int n, d, b;
	cout << "Введите размер массива: ";
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100;
	}
	cout << "Изначальный массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Итоговый массив: ";
	d = n;
	d = d / 2;
	while (d > 0)
	{
		for (int i = 0; i < n - d; i++)
		{
			int j = i;
			while (j >= 0 && A[j] > A[j + d])
			{
				b = A[j];
				A[j] = A[j + d];
				A[j + d] = b;
				j--;
			}
		}
		d = d / 2;
	}
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	delete[] A;
	return 0;
}