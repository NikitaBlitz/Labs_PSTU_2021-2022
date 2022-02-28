#include <iostream>
using namespace std;

int Hoop(int n, int start, int temp, int point)
{
	if (n > 0)
	{
		Hoop(n - 1, start, point, temp);
		cout << start << " => " << temp << endl;
		Hoop(n - 1, point, temp, start);
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество обручей: ";
	cin >> n;
	Hoop(n, 1, 3, 2);
	return 0;
}
