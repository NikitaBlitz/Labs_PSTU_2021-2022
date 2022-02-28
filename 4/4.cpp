#include <iostream>
#include <ctime>
using namespace std;

void print(int* arr, int size, int k)
{
    for (int i = k; i != k - 1; i++)
    {
        if (i == size) i = 0;
        cout << arr[i] << " ";
    }
    cout << arr[k - 1];
}

void FillArray(int* const arr, const int size)
{
	for (int i = 0; i <size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void ShowArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout <<arr[i]<<" ";
	}
	cout << endl;
}

void push(int*& arr, int& size)
{
	int count = 0;
	int* newArray = new int[size + 2];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
		count += 1;
	}
	newArray[size] = arr[0];
	size++;
	newArray[size] = arr[count-1];
	size++;
	delete[] arr;
	arr = newArray;
}


int main()
{
	int size,k,k1;
	cin >> size;
	cin >> k;
	int* arr = new int[size];
	FillArray(arr, size);
	ShowArray(arr, size);
	print(arr, size, k-1);
	push(arr, size);
	cout <<endl;
	ShowArray(arr, size);
	for (int i = 0; i <= size; i++)
		for (int j = 0; j <= size; j++)
			if (arr[i] % 2 == 0)
			{
				arr[i] = arr[size - 1];
				size--;
			}
	ShowArray(arr, size);
	cin >> k1;
	print(arr, size, k1 - 1);
}