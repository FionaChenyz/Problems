#include<iostream>
#include<vector>
using namespace std;
bool check[10];

vector<int> v ;
void nineBitInteger(int k,long long a)
{   //判断是否可以被位数（k）整除，不可则结束
	if (k&&a%k != 0)return;
	//第9位也符合条件则将数A保存起来
	if (k == 9)
	{
		v.push_back(a);
		return;
	}
	//递归过程
	for (int i = 1; i <= 9; i++)
	{
		if (!check[i])
		{  //检测过则赋值为1
			check[i] = 1;
			nineBitInteger(k + 1, a * 10 + i);
			check[i] = 0;
		}
	}
}
void main()
{
   nineBitInteger(0, 0);
	for (int i = 0; i < v.size();i++)
	{
		cout << v[i];
	}
	cout << endl;
}
