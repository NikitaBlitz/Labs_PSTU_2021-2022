#include <iostream>

using namespace std;

int search(int* mas, int key, int n)
{
	int left = 0;
	int right = n;
	int mid = 0;
	bool found = false;
	while ((left <= right) && found != true)
	{
		mid = left + ((key - mas[left]) * (right - left)) / (mas[right] - mas[left]);
		if (mas[mid] < key) left = mid + 1;
		else if (mas[mid] > key) right = mid + 1;
		else found = true;
	}
	if (mas[left] == key) return left;
	else if (mas[right] == key) return right;
	else return -1;
}


void sort(int* mas, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[j] > mas[i])
			{
				temp = mas[j];
				mas[j] = mas[i];
				mas[i] = temp;
			}
		}
	}
}


void remove(int* arr, int& n,int k)
{
	int i = k;
	while (i < n - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	n--;
}

void printMas(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
    srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int key, n,k,count=0;
	cout << "Введите количество элементов в массиве: ";
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 10;
	}
	cout << "Начальный массив: ";
	printMas(mas, n);
	sort(mas, n);
	cout << "Отсортированный массив: ";
	printMas(mas, n);
	cout << "Введите ключ замены: ";
	cin >> key;
	k = search(mas, key, n);
	if (search(mas, key, n) == -1)
	{
		cout << "Элемента для замены не существует!";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (key == mas[i])
				count++;
		}
		while (count != 0)
		{
			remove(mas, n, k);
			count--;
		}
		printMas(mas, n);
	}
}
