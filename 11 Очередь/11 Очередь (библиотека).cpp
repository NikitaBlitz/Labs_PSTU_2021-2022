#include <iostream>
#include <queue>

using namespace std;

void print(queue<char> q)
{
	int num = q.size();
	for (int i = 0; i < num; i++)
	{
		cout << q.front();
		q.pop();
	}
}

void change(queue<char>& q, int& size, int& n)
{
	int count = 1;
	for (int i=0; i<size;i++)
	{
		if (count==n)
		{
			cout << "Введите новый элемент очереди: ";
			char a;
			cin >> a;
			q.push(a);
			q.pop();
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
		count++;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n,k;
	char a;
	cout << "Введите размер очереди: ";
	cin >> n;
	cout << "Введите элемент очереди, который хотите поменять: ";
	cin >> k;
	queue<char> qu;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		qu.push(a);
	}
	cout << "Начальная очередь: ";
	print(qu);
	cout << endl;
	change(qu, n, k);
	cout << endl;
	cout << "Финальная очередь: ";
	print(qu);
	return 0;
}