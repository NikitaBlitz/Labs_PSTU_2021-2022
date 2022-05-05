#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class creature
{
public:
	creature(void) {};
	~creature(void) {};
	virtual void Show() = 0;
};


class Person :public creature
{
protected:
	string name;
	int age;
public:
	Person();
	Person(string, int);
	Person(const Person&);
	~Person() {}
	string GetName() { return name; }
	int GetAge() { return age; }
	void SetName(string name) { this->name = name; }
	void SetAge(int age) { this->age = age; }
	virtual Person& operator= (const Person&);

	friend istream& operator>>(istream& in, Person& p);
	friend ostream& operator<<(ostream& out, const Person& p);
	void Show();
};

Person::Person()
{
	this->name = "-";
	this->age = 0;

}

Person::Person(string newName, int newAge)
{
	this->name = newName;
	this->age = newAge;
}

Person::Person(const Person& t)
{
	this->name = t.name;
	this->age = t.age;
}

Person& Person::operator=(const Person& t)
{
	if (&t == this) return *this;
	name = t.name;
	age = t.age;
	return *this;
}

istream& operator>>(istream& in, Person& p)
{
	cout << "Имя: "; in >> p.name;
	cout << "Возраст: "; in >> p.age;
	return in;
}

ostream& operator<<(ostream& out, const Person& p) { return (out << "Имя: " << p.name << "\nВозраст: " << p.age << "\n\n"); }

void Person::Show()
{
	cout << "Имя: " << name << "\nВозраст: " << age << "\n\n";
}

class Student :public Person
{
protected:
	int year;
public:
	Student(void);
	Student(string, int, int);
	Student(const Student&);
	~Student();
	void SetYear(int year) { this->year = year; }
	int GetYear() { return year; }
	virtual Student& operator=(const Student&);
	double cntyear() { return (year + 3); }
	friend istream& operator>>(istream& in, Student& t);
	friend ostream& operator<<(ostream& out, const Student& t);
	void Show();
};

Student::Student()
{
	this->name = "-";
	this->age = 0;
	this->year = 0;
}

Student::Student(string name, int age, int year)
{
	this->year = year;
	this->name = name;
	this->age = age;
}

Student::Student(const Student& t)
{
	this->year = t.year;
	this->name = t.name;
	this->age = t.age;
}

Student::~Student() {}

istream& operator>>(istream& in, Student& t)
{
	cout << "Год обучения: "; in >> t.year;
	return in;
}
ostream& operator<<(ostream& out, const Student& t)
{
	return (out << "Имя: " << t.name << "\nВозраст: " << t.age << "\nГод " << t.year << "\n\n");
}
Student& Student::operator=(const Student& t)
{
	if (&t == this) return *this;
	year = t.year;
	return *this;
}
void Student::Show()
{
	cout << "Имя: " << name << "\nВозраст: " << age << "\nГод: " << year << "\n\n";
}

void f1(Person& c)
{
	c.SetName("Саша");
	cout << c << '\n';
}

Person f2()
{
	Student l("Никита", 21, 5);
	return l;
}


class Vector
{
private:
	creature** beg;
	int size;
	int cur;
public:
	Vector(void);
	Vector(int);
	~Vector();
	void Add(creature*);
	friend ostream& operator<<(ostream& out, const Vector&);
};

Vector::Vector(void)
{
	beg = 0;
	size = 0;
	cur = 0;
}

Vector::Vector(int n)
{
	beg = new creature * [n];
	cur = 0;
	size = n;
}

void Vector::Add(creature* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty" << endl;
	creature** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show();
		p++;
	}
	return out;
}

Vector::~Vector(void)
{
	if (beg != 0) delete[] beg;
	beg = 0;
}


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Vector v(5);
	Person human1;
	cin >> human1;
	Student human2("Миша", 18, 4);
	creature* p = &human1;
	v.Add(p);
	p = &human2;
	v.Add(p);
	cout << v;

	return 0;
}