#pragma once
#include <glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

int n;//Кол-во вершин
int** tmp;//Вспомогательный массив для оценок пути
int* result;//Массив для пути
int*** inter;//Матрица смежности
const int maxSize = 15;//Максимальное кол-во вершин
int countVerts;//Переменная для кол-ва вершин

class Graph//Класс графа
{
	vector<int> vertList;//Переменная для работы с библиотекой <vector> и её функциями
	bool* visitedVerts = new bool[vertList.size()];//Булевая переменная для обозначения посещённых вершин
public:
	int adjMatrix[maxSize][maxSize] = { 0 };//Матрица смежности
	Graph();//Конструктор
	~Graph();//Деструктор
	void DrawGraph();//Функция отрисовки графа
	void InsertEdge(const int& vertex1, const int& vertex2, int weight);//Функция связи вершин ребром
	void InsertVertex(const int& vertex);//Функция добавления вершин
	int GetVertPos(const int& vertex);//Получение позиции вершины
	bool Empty();//Функция проверки на пустоту графа
	bool Full();//Функция првоерки на полноту графа
	void Print();//Функция отрисовки матрицы смежности в консоли
};

int R;

struct vertCoord//Структура дял координат
{
	int x, y;
};
vertCoord vertC[20];

void Graph::InsertVertex(const int& vertex)
{
	if (!this->Full())//Если не полон
	{
		this->vertList.push_back(vertex);//Вставка вершины с помощью встреонной функции библиотеки <vector>
	}
	else
	{
		cout << "Граф полон. " << endl;//Граф полон
		return;
	}
}


bool Graph::Empty()
{
	if (this->vertList.size() != 0)//Если пуст - true, если нет - false
		return false;
	else
		return true;
}

bool Graph::Full()
{
	return (vertList.size() == maxSize);//Присваивание мак-го кол-ва вершин
}


int Graph::GetVertPos(const int& vertex)
{
	for (int i = 0; i < this->vertList.size(); ++i) //Цикл от кол-ва вершин
	{
		if (this->vertList[i] == vertex)//Если номер совпадает
			return i;
	}
	return -1;
}

Graph::Graph()//Конструктор
{
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j)
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

Graph::~Graph() {}//Деструктор

Graph make()
{
	Graph graph;
	int countEdges, sourceVertex, targetVertex, edgeLength;
	cout << "Кол-во вершин: "; cin >> countVerts; cout << endl;//Кол-во вершин
	cout << "Кол-во путей: "; cin >> countEdges; cout << endl;//Кол-во рёбер
	for (int i = 1; i <= countVerts; ++i)//Цикл от кол-ва вершин 
	{
		int* vertPtr = &i;//Присваивание указателю адреса i
		graph.InsertVertex(*vertPtr);//Функция вставки вершины
	}

	for (int i = 0; i < countEdges; ++i) //Цикл от кол-ва рёбер
	{
		cout << "Начальная вершина: "; cin >> sourceVertex; cout << endl;//Начальная вершина
		int* sourceVertPtr = &sourceVertex;//Присваивание указателю адреса начальной вершины
		cout << "Конечная вершина: "; cin >> targetVertex; cout << endl;//Конечная вершина
		int* targetVertPtr = &targetVertex;//Присваивание указателю адреса конечной вершины

		cout << "Длина пути: "; cin >> edgeLength; cout << endl;
		graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeLength);//Функция вставки ребра
	}
	cout << endl;
	return graph;
}

void Graph::InsertEdge(const int& vertex1, const int& vertex2, int weight)
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1))//Если существуют обе вершины
	{
		int Pos1 = GetVertPos(vertex1);//Присваивание позиций вершин
		int Pos2 = GetVertPos(vertex2);
		if (this->adjMatrix[Pos1][Pos2] != 0//Если дорога есть
			&& this->adjMatrix[Pos2][Pos1] != 0)
		{
			cout << "Дорога уже существует" << endl;//Дорога уже существует
			return;
		}
		else
		{
			this->adjMatrix[Pos1][Pos2] = weight;//Ввод в матрицу веса ребра
			this->adjMatrix[Pos2][Pos1] = weight;
		}
	}
	else
	{
		cout << "Нельзя вставить вершину " << endl;//Нельзя вставить вершину
		return;
	}
}

void Graph::Print()
{
	if (!this->Empty()) //Проверка на пустоту переменной graph
	{
		cout << "Матрица смежности: " << endl;//Матрица смежности
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			cout << this->vertList[i] << " ";//Вывод номера дороги
			for (int j = 0; j < vertListSize; ++j) //Цикл вывода матрицы
			{
				cout << " " << this->adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
}

Graph graph;//Инициализация переменной класса Graph

void Djkstra(int*** inter, int n, int** tmp, int* path)//Алгоритм дейкстры
{
	for (int l = 0; l < n; l++)//Циклы от кол-ва вершин
	{
		for (int i = 0; i < n; i++)
		{
			int min = 1000000;//Здесь происходит оценка путей по длине и ширине
			for (int j = 0; j < n; j++)
				if (inter[i][j] && min > *inter[i][j])//Сравнивание минимума и длины пути
					min = *inter[i][j];
			for (int j = 0; j < n; j++)
				if (inter[i][j])
					*inter[i][j] -= min;//Декремент длины пути до 0
		}
		for (int j = 0; j < n; j++)//То же самое только для глубины
		{
			int min = 1000000;
			for (int i = 0; i < n; i++)
				if (inter[i][j] && min > *inter[i][j])
					min = *inter[i][j];
			for (int i = 0; i < n; i++)
				if (inter[i][j])
					*inter[i][j] -= min;
		}
		for (int i = 0; i < n; i++)//Цикл занулирования вспомогательного массива
			for (int j = 0; j < n; j++)
				tmp[i][j] = 0;

		for (int i = 0; i < n; i++)//Цикл для заполнения массива "ценами" путей
			for (int j = 0; j < n; j++)
			{
				if (inter[i][j] && !*inter[i][j])//Если не указатель на массив
				{
					int hmin = 1000000;
					int vmin = 1000000;
					for (int l = 0; l < n; l++)//Цикл от кол-ва вершин
						if (l != i && inter[l][j] && hmin > *inter[l][j])//Если длина пути меньше минимальной по высоте и i не равно l
							hmin = *inter[l][j];//Присваивание указателя на массив со значением пути

					for (int l = 0; l < n; l++)//Цикл от кол-ва вершин
						if (l != j && inter[i][l] && vmin > *inter[i][l])//Если длина пути меньше минимальной по ширине и i не равно l
							vmin = *inter[i][l];//Присваивание указателя на массив со значением пути

					tmp[i][j] = hmin + vmin;//Заполнение вспомогательного массива "ценами" путей
				}
			}
		int mcost = 0, mi = 0, mj = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (inter[i][j] && mcost < tmp[i][j])//Если минимальный путь меньше значения в массиве
				{
					mcost = tmp[i][j];//Присваивание цены пути
					mi = i;//Присваивание индексов для минимального пути
					mj = j;
				}
		path[mi] = mj;//Составление массива мин-го пути
		for (int i = 0; i < n; i++)
			inter[i][mj] = nullptr;//Присваивание нулевого указателя по ширине
		for (int i = 0; i < n; i++)
			inter[mi][i] = nullptr;//Присваивание нулевого указателя по высоте
		inter[mj][mi] = nullptr;//Присваивание нулевого указателя по ширине и высоте
	}
}

void Prepare(int***& inter, int& n, int**& tmp, int*& result)//Функция подготовки
{
	n = countVerts;//Присваивание кол-ва вершин
	tmp = new int* [n];//Дин-й вспомогательный массив
	result = new int[n];//Дин-й массив для пути
	inter = new int** [n];//Дин-я матрица смежности
	for (int i = 0; i <= n; i++)//Цикл для инициализации вспомогательного дин-го массива
	{
		tmp[i] = new int[n];
	}
	for (int i = 0; i < n; i++)//Цикл для инициализации дин-й матрицы
	{
		inter[i] = new int* [n];
		for (int j = 0; j < n; j++)
		{
			if (graph.adjMatrix[i][j] == 0)//Проверка массива на отсутствие дорог и присваиние нулевого указателя
			{
				inter[i][j] = nullptr;
				continue;
			}
			inter[i][j] = new int(graph.adjMatrix[i][j]);//Цикл для инициализации дин-й матрицы
		}
	}
}

void MinWay(int*** inter, int n, int** tmp, int* result)//Функция нахождения минимального пути
{
	Prepare(inter, n, tmp, result);//Функция подготовки
	int s = 0;//Переменная для хранения длины мин-го пути
	Djkstra(inter, n, tmp, result);//Функция для алгоритма дейкстры
	for (int i = 0, j = 0; i < n; i++)
	{
		j = result[i];//Присваивание j номера следующего номера вершины пути
		s += graph.adjMatrix[i][j];//Добавление длины пути
	}
	cout << "\nМинимальный путь: ";//Минимальный путь
	int temp = 0;
	for (int l = 0; l < n;)
	{
		for (int i = 0, j = 0; i < n; i++)
		{
			if (temp == 0 || i + 1 == temp)
			{
				if (temp == 0) cout << i + 1;//Вывод номера начальной вершины
				j = result[i];
				temp = j + 1;
				if (temp > 0)	cout << " -> " << temp;//Вывод пути
				l++;//Инкремент подсчёта кол-ва вершин
			}
		}
	}
	cout << " = " << s;//Вывод длины мин-го пути
	cout << endl;
}

void setCoord(int i, int n)//Функция для координат вершин и радиуса кругов
{
	int R_;
	int x0 = 1200 / 2;//Расположение центра
	int y0 = 800 / 2;
	R = 3 * (800 / 18) / n;//Вычисление радиуса
	R_ = 800 / 2 - R - 10;
	float theta = 2.0f * 3.1415926f * float(i) / float(n);//Вычисление угла для положения вершины в зависимости от кол-ва вершин
	float y1 = R_ * cos(theta) + y0;//Коор-ы вершин
	float x1 = R_ * sin(theta) + x0;
	vertC[i].x = x1;//Присваивание координат
	vertC[i].y = y1;
}

void CircEdgeText(int nom, int x1, int y1)//Функция отрисовки текста в вершинах и на рёбрах
{
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[j]);
}


void drawCircle(int x, int y, int R)//Функция отрисовки круга с заданными координатами и радиусом
{
	glColor3f(1.0f, 0.5f, 0.0f);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)//Цикл для отрисовки 360 точек
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)//Цикл для отрисовки 360 точек
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawVertex(int n)//Функция отрисовки вершин с текстом
{
	for (int i = 0; i < n; i++)//Цикл от кол-ва вершин
	{
		drawCircle(vertC[i].x, vertC[i].y, R);//Функция отрисовки круга с заданными координатами и радиусом
		CircEdgeText(i + 1, vertC[i].x, vertC[i].y);//Функция отрисовки текста в вершинах и на рёбрах
	}
}

void drawLine(int text, int x0, int y0, int x1, int y1)//Функция отрисовки линий, соединяющих две вершины
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);//Коор-ты начальной вершины
	glVertex2i(x1, y1);//Коор-ты конечной вершины
	glEnd();
	CircEdgeText(text, (x0 + x1) / 2 + 12, (y0 + y1) / 2 + 12);//Отрисовка текста для ребра
}

void Graph::DrawGraph()//Функция отрисовки графа
{
	int n = vertList.size();//Кол-во вершин
	for (int i = 0; i < n; i++)
	{
		setCoord(i, n);//Функция для задания координат вершинам
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = adjMatrix[i][j];
			if (a != 0)//Проверка на наличие дороги
			{
				drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);//Функция отрисовки линий, соединяющих две вершины
			}
		}
	}
	drawVertex(n);//Функция отрисовки вершины
}

void MenuText(string text, int x1, int y1)//Функция отрисовки текста в меню
{
	string s = text;
	glRasterPos2i(x1 + 5, y1 - 20);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[j]);
}

void mouseClick(int btn, int stat, int x, int y)//Функция для действий прик клике мыши
{
	if (stat == GLUT_DOWN) //Проверка на нажатие
	{
		if (x > 0 && x < 150 && y >  0 && y < 30)//Проверка на координаты положения мыши
		{
			graph.Print();//Функция отрисовки матрицы смежности в консоли
		}
		if (x > 0 && x < 150 && y >  30 && y < 70)//Проверка на координаты положения мыши
		{
			graph = make();//Вызов функции дял создания нового графа
		}
		if (x > 0 && x < 150 && y > 70 && y < 100)//Проверка на координаты положения мыши
		{
			MinWay(inter, n, tmp, result);//Функция вычисления минимальной длины пути из 1 в 1 с посещением всех вершин
		}
	}
	glutPostRedisplay();
}
void drawMenu()//Отрисовка меню с кнопками
{

	glColor3f(1.0f, 0.5f, 0.0f); //Отрисовка фона для кнопок
	glBegin(GL_QUADS);
	glVertex2f(0, 710);
	glVertex2f(150, 710);
	glVertex2f(150, 800);
	glVertex2f(0, 800);

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(0, 800);
	glVertex2i(150, 800);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(0, 770);
	glVertex2i(150, 770);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(0, 740);
	glVertex2i(150, 740);
	glEnd();

	glColor3d(0, 0, 0);
	MenuText("Print matrix", 0, 800);
	glColor3d(0, 0, 0);
	MenuText("New matrix", 0, 770);
	glColor3d(0, 0, 0);
	MenuText("Answer", 0, 740);
} 

void display()//Функция отрисовки главного окна программы с параметрами
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1200, 0, 800);
	glViewport(0, 0, 1200, 800);
	glClearColor(1.0, 0.3, 0.4, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	graph.DrawGraph();
	drawMenu();
	glutSwapBuffers();
}