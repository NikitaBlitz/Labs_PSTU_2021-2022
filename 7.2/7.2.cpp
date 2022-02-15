#include <iostream>
#include <stdarg.h>
using namespace std;

int nok(int n,  ...)
{
	int sum= 1;
	va_list param;
	va_start(param, n);
	for (int i = 0; i < n; i++)
	{
		sum *= va_arg(param, int);
	}
	va_end(param);
	va_start(param, n);
	int nod = va_arg(param, int);
	for (int i=0; i <(n-1); i++)
	{
		int b = va_arg(param, int);
		while (nod != 0 && b != 0)
		{
			if (nod > b) { nod = nod % b; }
			else { b = b % nod; }
		}
		nod = (nod + b);
	}
	return (sum/nod);
}



int main()
{
	cout << nok(3,  6 , 14, 24);
}
