#include <iostream>
using namespace std;

template <class T>
class List
{
protected:
	int size;
	T* data;
public:
	List(int s, T k);
	List(const List<T>& p);
	~List();
	T& operator[](int index);
	List operator+(const T k);
	List& operator=(const List<T>& p);
	int& operator()();
	friend ostream& operator<< <>(ostream& out, const List<T>& p);
	friend istream& operator>> <>(istream& in, List<T>& p);
};

template <class T>
List<T>::List(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}

template <class T>
List<T>::List(const List<T>& p)
{
	size = p.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
}

template <class T>
List<T>::~List()
{
	delete[]data;
	data = 0;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& p)
{
	if (this == &p) return *this;
	size = p.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
	return *this;
}

template <class T>
T& List<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "ОШИБКА ДОСТУПА! (index>size)";
}

template <class T>
List<T> List<T>::operator+(const T k)
{
	List<T> temp(size, k);
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] + k;
	return temp;
}

template <class T>
int& List<T>::operator()()
{
	return size;
}

template <class T>
ostream& operator<<(ostream& out, const List<T>& p)
{
	for (int i = 0; i < p.size; i++)
		out << p.data[i] << " ";
	return out;
}

template <class T>
istream& operator>>(istream& in, List<T>& p)
{
	for (int i = 0; i < p.size; i++)
		in >> p.data[i];
	return in;
}

class Pair
{
public:
	int first;
	double second;
public:
	Pair(void);
	Pair(int, int);
	Pair(const Pair&);
	~Pair() {};
	Pair& operator=(const Pair&);
	friend ostream& operator<< (ostream& out, const Pair&);
	friend istream& operator>> (istream& in, Pair&);
};

Pair::Pair(void)
{
	first = second = 0;
}

Pair::Pair(int first, int second)
{
	this->first = first;
	this->second = second;

}

Pair::Pair(const Pair& p)
{
	this->first = p.first;
	this->second = p.second;
}

Pair& Pair::operator=(const Pair& p)
{
	this->first = p.first;
	this->second = p.second;
	return *this;
}



ostream& operator<< (ostream& out, const Pair& p)
{
	out << p.first << ":" << p.second;
	return out;
}

istream& operator>> (istream& in, Pair& p)
{
	cout << "\nfirst: "; in >> p.first;
	cout << "\nsecond: "; in >> p.second;
	return in;
}


int main()
{
	setlocale(LC_ALL, "rus");
	Pair t;
	cin >> t;
	cout << t << '\n';
	List<Pair> a(3, t);
	cout << a << '\n';
	cin >> a;
	cout << a;
	cout << '\n';
	List<Pair> c(3, t);
	List<Pair> b(3, t);
	cout << b << '\n';
	b = a;
	cout << b << '\n';
	cout << a[2] << '\n';
	cout << "size a: " << a() << '\n';
	return 0;
}