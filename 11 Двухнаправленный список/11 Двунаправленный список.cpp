#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* ptr_prev = nullptr;
	Node* ptr_next = nullptr;
};

struct List
{
	Node* headnode = nullptr;
	Node* tailnode = nullptr;
};

void StartList(List& list)
{
	Node* newnode = new Node;
	char data;
	cin >> data;
	newnode->data = data;
	if (list.headnode == NULL) {
		list.headnode = newnode;
		list.tailnode = newnode;
		return;
	}
	Node* currentnode = list.tailnode;
	newnode->ptr_prev = currentnode;
	newnode->ptr_next = currentnode->ptr_next;
	currentnode->ptr_next = newnode;
	list.tailnode = newnode;
}

void printList(List& list)
{
	Node* currentnode = list.headnode;
	while (currentnode != nullptr)
	{
		cout << currentnode->data << " ";
		currentnode = currentnode->ptr_next;
	}
}

void addList(List& list)
{
	Node* newnode = new Node;
	char data;
	int count = 0, index = 0;
	Node* currentnode = list.headnode;
	cout << "Введите номер:\n";
	cin >> index;
	while (count != index - 1)
	{
		currentnode = currentnode->ptr_next;
		count++;
	}
	cout << "Введите элемент char: \n";
	cin >> data;
	newnode->data = data;
	currentnode->data = newnode->data;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	List list;
	int n;
	cout << "Введите размер списка: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		StartList(list);
	}
	cout << "Изначальный список" << endl;
	printList(list);
	cout << endl;
	addList(list);
	cout << "Финальный список" << endl;
	printList(list);
	return 0;
}
