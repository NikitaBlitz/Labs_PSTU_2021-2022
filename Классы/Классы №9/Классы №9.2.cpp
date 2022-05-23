#include <iostream>
#include <string>
using namespace std;
const int max_size = 7;
class error
{
private:
	string msg;
public:
	error(string msg)
	{
		this->msg = msg;
	}
	void what()
	{
		cout << "Произошла ошибка: " << msg << endl;
	}
};

class List
{
protected:
	int size;
	int* data;
public:
	List(void);
	List(int s);
	List(int s, int* mas);
	List(const List&);
	~List();
	List& operator=(const List&); //операция присваивания 
	int& operator[](int index); //добавление по индексу 
	int& operator()();
	List operator+(const int k);

	friend istream& operator>>(istream& in, List& p);
	friend ostream& operator<<(ostream& out, const List& p);
	friend List add_elem(List& p);
};


List::List()
{
	size = 0;
	data = 0;
}

List::List(int s)
{
	if (s >= max_size) throw 1;
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = 0;
}

List::List(int s, int* mas)
{
	if (s >= max_size) throw 1;
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = mas[i];
}

List::List(const List& t)
{
	size = t.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = t.data[i];
	}
}

List::~List()
{
	delete[] data;
	data = 0;
}

List& List::operator=(const List& t)
{
	if (this == &t) return *this;
	size = t.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = t.data[i];
	}
	return *this;
}

int& List::operator[](int index)
{
	if (index < 0) throw 2;
	if (index >= size) throw 3;
	return data[index];
}

int& List::operator()()
{
	return size;
}

List List::operator+(const int k)
{
	List temp(size);
	for (int i = 0; i < size; i++)
		temp.data[i] = data[i] + k;
	return temp;
}



ostream& operator<<(ostream& out, const List& p)
{
	if (p.size == 0) out << "Список пуст!\n";
	for (int i = 0; i < p.size; i++)
		out << p.data[i] << " ";
	return out;
}

istream& operator>>(istream& in, List& p)
{
	for (int i = 0; i < p.size; i++)
		in >> p.data[i];
	return in;
}

List add_elem(List& p)
{
	if (p.size >= max_size) throw 1;
	int newsize = p.size + 1;
	int k = 0;
	List temp(newsize);
	for (int i = 0; i < p.size; i++)
	{
		temp[i] = p[i];
	}
	cout << "Введите новый элемент: \n";
	cin >> k;
	temp[newsize - 1] = k;
	return temp;
}

int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		List first(5);
		cout << first << '\n';
		first = first + 5;
		cout << first[0] << '\n';
		cout << add_elem(first);
		cout << endl;
		List second(0);
		cout << second << '\n';

	}
	catch (error er)
	{
		er.what();

	}
	return 0;
}