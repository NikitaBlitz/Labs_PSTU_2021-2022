#include <iostream>
#include <string>
using namespace std;

class Person
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

class Student : public Person
{
protected:
	int year;
public:
	Student(void);
	Student(string, int, int);
	Student(const Student&);
	~Student();
	void SetYear(int year) { this-> year = year; }
	int GetYear() { return year; }
	virtual Student& operator=(const Student&);
	double cntyear() { return (year + 3); }
	friend istream& operator>>(istream& in, Student& t);
	friend ostream& operator<<(ostream& out, const Student& t);
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


int main()
{
	setlocale(LC_ALL, "rus");
	Person human1("Рома", 19);
	cout << human1;

	Student human2("Миша", 18, 4);
	cout << human2;
	cout << "Год с увеличением: " << human2.cntyear() << "\n\n";

	Student human3 = human2;
	cout << human3;
	Student human33333;
	f1(human33333);
	human1 = f2();
	cout << human1;

	return 0;
}