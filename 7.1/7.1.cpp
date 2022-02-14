#include <iostream>;
#include<cmath>;
#include <cstring>;
using namespace std;
int max_element(int n, int a[])
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

size_t max_element(string str)
{
	int max = 0;
	int k = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		k++;
		if (str[i + 1] == ' ' || str[i + 1] == '\0')
		{
			if (k > max)
			{
				max = k; 
			}
			k =-1;
		}
	}
	return max;
}


int main()
{
	int a[] = { 1313,452432,125,111,29 };
	cout << max_element("Hello fat user") << endl;
	cout << max_element(5, a);
}