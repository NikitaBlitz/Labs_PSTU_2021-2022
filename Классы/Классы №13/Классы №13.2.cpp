#include <iostream>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>

using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	Pair(double m, int n);
	Pair();
	Pair(const Pair& t);
	~Pair();

	int get_first() { return first; }
	double get_second() { return second; }
	void set_first(int n) { first = n; }
	void set_second(int m) { second = m; }

	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	Pair& operator--();
	Pair operator --(int);
	bool operator>(Pair& t);
	bool operator<(Pair& t);
	Pair& operator=(const Pair& t);
	bool operator==(const Pair& t);
	Pair operator+(const Pair& t);
	Pair operator/(int k);
};

Pair Pair::operator/(int k)
{
	first = first / k;
	second = second / k;
	return *this;
}

Pair Pair::operator+(const Pair& t)
{
	first += t.first;
	second += t.second;
	return *this;
}

bool Pair::operator==(const Pair& t)
{
	if (first == t.first && second == t.second) return true;
	return false;
}

Pair::Pair(double m, int n)
{
	first = n;
	second = m;
}

Pair::Pair()
{
	first = 0;
	second = 0;
}

Pair::Pair(const Pair& t)
{
	first = t.first;
	second = t.second;
}

Pair::~Pair() = default;

istream& operator>>(istream & in, Pair & p)
{
	cout << "first:"; in >> p.first;
	cout << "second:"; in >> p.second;
	return in;
}

ostream& operator<<(ostream & out, const Pair & p)
{
	return (out << p.first << ":" << p.second << endl);
}

Pair Pair::operator --(int)
{
	first--;
	return *this;
}

Pair& Pair::operator--()
{
	second--;
	return *this;
}

Pair& Pair::operator=(const Pair & t)
{
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	return *this;
}

bool Pair::operator<(Pair & t)
{
	if (first < t.first && second < t.second) return true;
	else  return false;
}

bool Pair::operator>(Pair & t)
{
	if (first > t.first && second > t.second) return true;
	else  return false;
}

typedef stack<Pair> St;
typedef deque<Pair> Tdeque;
Pair p;
Pair sravn;

St make_stack(int n)
{
	St s;
	Pair pr;
	for (int i = 0; i < n; i++)
	{
		cin >> pr;
		s.push(pr);
	}
	return s;
}

Tdeque copy_stack_to_deque(St s)
{
	Tdeque d;
	while (!s.empty())
	{
		d.push_front(s.top());
		s.pop();
	}
	return d;
}

St copy_deque_to_stack(Tdeque d)
{
	St s;
	for (int i = 0; i < d.size(); i++)
		s.push(d[i]);
	return s;
}

void print_stack(St s)
{
	Tdeque temp;
	temp = copy_stack_to_deque(s);
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	s = copy_deque_to_stack(temp);
	cout << '\n';
}

struct Equal_s
{
	bool operator() (Pair t)
	{
		return t == sravn;
	}
};

Pair srednee(Tdeque d)
{
	Pair s = d[0];
	int size = d.size();
	for (int i = 1; i < size; i++)
		s = s + d[i];
	return s / d.size();
}

void Foo(Pair & b)
{
	b = b + p;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int n = 0;
	cout << "������� ������ �����: ";
	cin >> n;
	St s = make_stack(n);
	cout << "\n��������� ����:\n";
	print_stack(s);

	Tdeque d = copy_stack_to_deque(s);
	Tdeque::iterator i;
	cout << "���� ������������ ������� � ��������� ��� � ����� �����:\n";
	i = max_element(d.begin(), d.end());
	Pair max = *i;
	d.push_back(max);
	s = copy_deque_to_stack(d);
	cout << "���� ����� ���������:\n";
	print_stack(s);

	cout << "�������� ���� ������ ���� Pair:\n";
	cin >> sravn;

	d = copy_stack_to_deque(s);
	cout << "���� ����� �������� ���������, ����������� � ������:\n";
	d.erase(remove_if(d.begin(), d.end(), Equal_s()), d.end());
	s = copy_deque_to_stack(d);
	print_stack(s);

	cout << "\n������� �������� ��������� �����: " << srednee(d) << '\n';
	p = srednee(d);

	d = copy_stack_to_deque(s);
	for_each(d.begin(), d.end(), Foo);
	s = copy_deque_to_stack(d);
	cout << "���� ����� ����������� � ������� ��� �������� �������� ��������:\n";
	print_stack(s);
	return 0;
}