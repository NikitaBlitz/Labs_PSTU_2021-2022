#include <iostream>
#include <iomanip>

using namespace std;

class call 
{
private:
	int first = 0;
	double second = 0;
public:
	void read() 
	{
		cout << "Введите целое число: " << endl;
		cin >> first;
		cout << "Введите дробное число:" << endl;
		cin >> second;

	}
	void show() 
	{
		cout << "first: " << first << endl;
		cout << "second: " << second<< endl;
	}
	double cost()
	{
		double k = first * second;
		return k;
	}

};




int main()
{
	setlocale(LC_ALL, "RU");
	call a;
	int first;
	double second;
	a.read();
	cout<<a.cost();
	return 0;
}