#include <iostream>
using namespace std;

class ticket
{
private:
	int Number;
	string date;
	double sum;
public:
	ticket(int Number, string date, double sum) //конструктор с параметрами
	{
		this->Number = Number;
		this->date = date;
		this->sum = sum;
	}

	ticket() // конструктор без параметров
	{
		this->Number = 0;
		this->date = "-";
		this->sum = 0;
	}

	ticket(const ticket& ent) //конструктор копирования
	{
		this->Number = ent.Number;
		this->date = ent.date;
		this->sum = ent.sum;
	}

	void SetNumber(int FIO)
	{
		this->Number = Number;
	}
	void Setdate(string date)
	{
		this->date = date;
	}
	void Setsum(double sum)
	{
		this->sum = sum;
	}

	void Print()
	{
		cout << "Номер: " << Number << endl;
		cout << "Дата: " << date << endl;
		cout << "Сумма: " << sum << endl << endl;
	}

	~ticket()
	{
		cout << "Деструктор" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	ticket ticket1;
	ticket1.Print();

	ticket ticket2(1, "31.03.2022", 219);
	ticket2.Print();

	ticket ticket3 = ticket2;
	ticket3.Print();

	ticket3.SetNumber(3);
	ticket3.Setdate("01.04.2019");
	ticket3.Setsum(199);
	ticket3.Print();

	return 0;
}
