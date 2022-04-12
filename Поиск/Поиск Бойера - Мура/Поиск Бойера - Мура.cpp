#include <iostream>
#include <string>

using namespace std;

int Search(string str, string sbstr)
{
	int st = str.size();
	int sbst = sbstr.size();
	int res = -1;
	if (st != 0 && sbst != 0)
	{
		int pos;
		int b[256];
		for (int i = 0; i < 256; i++)
		{
			b[i] = sbst;
		}
		for (int i = sbst - 2; i >= 0; i--)
		{
			if (b[int((unsigned char)sbstr[i])] == sbst)
			{
				b[int((unsigned char)sbstr[i])] = sbst - i - 1;
			}
		}
		pos = sbst - 1;
		while (pos < st)
		{
			if (sbstr[sbst - 1] != str[pos])
			{
				pos += b[int((unsigned char)str[pos])];
			}
			else
			{
				for (int i = sbst - 1; i >= 0; i--)
				{
					if (sbstr[i] != str[pos - sbst + i + 1])
					{
						pos += b[int((unsigned char)str[pos - sbst + i + 1])];
						break;
					}
					else if (i == 0)
					{
						return pos - sbst + 1;
					}
				}
			}
		}
	}
	return res;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string st, str;
	cout << "Введите строку: ";
	cin >> st;
	int n = st.size();
	string* newst = new string[n];
	cout << "Введите подстроку: ";
	cin >> str;
	int k = Search(st, str);
	if (k != -1)
	{
		for (int i = 0; i < k; i++)
		{
			*newst += st[i];
		}
		int size = str.size();
		int i = k;
		while (st[i + size] != '\0')
		{
			*newst += st[i + size];
			i++;
		}
		cout << "Итоговая строка: ";
		cout << *newst;
		delete[]newst;
		return 0;
	}
	else
	{
		cout << "Подстроки нет!";
		return 0;
	}
}