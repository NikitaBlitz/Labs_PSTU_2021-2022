#include <iostream>
#include <stack>

using namespace std;

void print(stack<double> st)
{
	int num = st.size();
	for (int i = 0; i < num; i++)
	{
		cout << st.top() << " ";
		st.pop();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	double a;
	cout << "Введите размера стека: ";
	cin >> size;
	stack<double> stack1;
	for (int i = 0; i < size; i++)
	{
		cin >> a;
		stack1.push(a);
	}
	print(stack1);
	cout << endl;
	stack<double> stack2;
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		if (count % 2 == 0)
		{
			stack2.push(stack1.top());
		}
		stack1.pop();
		count++;
	}
	int size2 = stack2.size();
	for (int i = 0; i < size2; i++)
	{
		cout << stack2.top() << " ";
		stack2.pop();
	}
	print(stack2);
}