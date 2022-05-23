#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Pair
{
public:
	int first;
	int second;
public:
	//������������
	Pair(void);
	Pair(int, int);
	Pair(const Pair&);

	//����������
	~Pair(void);

	//���������
	int get_first();
	int get_second();

	//������������ 
	void set_first(int);
	void set_second(int);

	//���������� ����������
	bool operator> (const Pair&);
	bool operator< (const Pair&);
	bool operator== (const Pair&);
	bool operator!= (const Pair&);

	Pair& operator+ (const Pair&);
	Pair& operator- (const Pair&);
	Pair& operator* (const Pair&);
	Pair& operator/ (int);
	Pair& operator=(const Pair&);

	//���������� ���������� ��� ������ � ��������
	friend ostream& operator<<(ostream&, const Pair&);
	friend istream& operator>>(istream&, Pair&);

};

//������������
Pair::Pair(void)
{
	first = 0;
	second = 0;
}
Pair::Pair(int a, int b)
{
	first = a;
	second = b;
}
Pair::Pair(const Pair& a)
{
	first = a.first;
	second = a.second;
}

//����������
Pair::~Pair(void) = default;

//���������
int Pair::get_first() { return first; }
int Pair::get_second() { return second; }

//������������
void Pair::set_first(int a) { first = a; }
void Pair::set_second(int b) { second = b; }



//���������� ����������
bool Pair::operator>(const Pair & a)
{
	if ((first > a.first) || (first == a.first && second > a.second)) return true;
	return false;
}
bool Pair::operator< (const Pair & a)
{
	if ((first < a.first) || (first == a.first && second < a.second)) return true;
	return false;
}
bool Pair::operator== (const Pair & a)
{
	if (first == a.first && second == a.second) return true;
	return false;
}
bool Pair::operator!= (const Pair & a)
{
	if (first != a.first || second != a.second) return true;
	return false;
}

Pair& Pair::operator+ (const Pair & a)
{
	first += a.first;
	second += a.second;
	return *this;
}
Pair& Pair::operator- (const Pair & a)
{
	first -= a.first;
	second -= a.second;
	return *this;
}
Pair& Pair::operator* (const Pair & a)
{
	first *= a.first;
	second *= a.second;
	return *this;
}
Pair& Pair::operator/ (int n)
{
	first /= n;
	second /= n;
	return *this;
}
Pair& Pair::operator=(const Pair & a)
{
	if (this == &a) return *this;
	first = a.first;
	second = a.second;
	return *this;
}

//���������� ���������� ��� ������ � ��������
ostream& operator<<(ostream & out, const Pair & a)
{
	out << "First: " << a.first << " Second: " << a.second;
	return out;
}
istream& operator>>(istream & in, Pair & a)
{
	cout << "Enter first >> "; in >> a.first;
	cout << "Enter second >> "; in >> a.second;
	return in;
}

typedef set<Pair> Tset;
typedef Tset::iterator it;

Pair s;


Tset make_set(int n)//�-�� ��� �������� ��-��
{
	Tset a;
	Pair p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		a.insert(p);
	}

	return a;
}

void print_set(Tset & a)//����� ��-��
{
	it i = a.begin();
	while (i != a.end())
	{
		cout << *i << "\n";
		i++;
	}
}

void add_max_elem(Tset & a)//�������� ���� �������
{
	const Pair b = *max_element(a.begin(), a.end());
	a.insert(b);
}

void del_elem(Tset & a, int n1, int n2)//������� �������� �� ���������� [n1; n2]
{
	if (n1 > a.size() || n2 > a.size() || n1 > n2) { cout << "������!!!\n"; return; }

	it i = a.begin();
	int k = 1;

	while (k != n1)//����� �������� � ����� ��������
	{
		i++;
		k++;
	}
	it beg = i;
	while (k != n2 + 1)//����� �������� � ������ �������
	{
		i++;
		k++;
	}
	it end = i;

	a.erase(beg, end);//remove ������������ �� ���������, �.�. �������� �������� ��� ���������, � ��� �������� ��� �������� � ��������� ������
}

Pair avereage(Tset & a)//����� ��������
{
	it i = a.begin();
	Pair sum;

	while (i != a.end())
	{
		sum = sum + *i;
		i++;
	}

	return sum / a.size();
}

void add_elem(Tset & a, Pair & p)//�������� � ������� �������� ����� �������
{
	Tset b;
	it i = a.begin();

	while (i != a.end())
	{
		Pair buf = *i;
		b.insert(buf + p);
		i++;
	}

	a = b;
}

bool operator< (const Pair & a, const Pair & b)//���������� ��������� <, ���������� ��� ��������� ����������� ���������
{
	return (a.first < b.first) || (a.second < b.second);
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "������� ���������� ��������� � ��������� >> "; cin >> n;

	Tset a = make_set(n);
	cout << "\n���� ���������:\n";
	print_set(a);

	add_max_elem(a);//�.� � ��� ��������� ��� ����������, �� ������ �� ���������
	cout << "\n��������� ������������ �������:\n";
	print_set(a);

	int n1, n2;
	cout << "\n������� ���������� �� �������� ����� ��������� �������� >> "; cin >> n1 >> n2;
	del_elem(a, n1, n2);
	print_set(a);

	s = avereage(a);
	add_elem(a, s);//�.�. �������� �������� ��� const, �� �������� � ���� ����������, �.� for_each ������������ ����������
	cout << "\n������� �������� ��������� � ���������: " << s << "\n���������� ������� ������� �� ���� ��������� ��������� : \n";
	print_set(a);

	return 0;
}