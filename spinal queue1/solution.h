#include<iostream>
using namespace std;
int a[10][10];
void fun(int n)
{
	int m = 1, j, i;
	for (i = 0; i < n / 2; i++)
	{
		for (j = 0; j < n - i; j++)                  //赋值1——5
		{
			if (a[i][j] == 0)
				a[i][j] = m++;
		}
		for (j = i + 1; j < n - i - 1; j++)         //赋值6——8
		{
			if (a[j][n - i - 1] == 0)
				a[j][n - i - 1] = m++;
		}
		for (j = n - i - 1; j > i; j--)             //赋值9——12
		{
			if (a[n - i - 1][j] == 0)
				a[n - i - 1][j] = m++;
		}
		for (j = n - i - 1; j > i; j--)            //赋值13——16
		{
			if (a[j][i] == 0)
				a[j][i] = m++;
		}
	}
	if ((n % 2) == 1)
		a[n / 2][n / 2] = m;

}
void main()
{
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	fun(n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
