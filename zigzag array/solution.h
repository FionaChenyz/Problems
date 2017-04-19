#include "stdafx.h"  
#include<iostream>
#include<string>
using namespace std;

void display(int a[][8],int N)
{
     for(int i=0;i<N;i++)
     {
             for(int j = 0;j<N;j++)
             {
                     cout<<a[i][j]<<"\t";
             }
             cout<<endl;
     }
}
int main()
{   
    int a[8][8] = {0};
    int N = 8;
    int count = 0;//记录当前应当填充的元素
    int cross = 0;
    //填充左上三角矩阵，包括对角线，按斜线输出，cross表示的是第几条斜线
	//对于任意一个元素a[i][j]，有i+j = cross
    for(cross = 0;cross<N;cross++)
    {
            if(cross %2 == 0)//如果填充第偶数条斜线，那么输出的方向是做左下角到右上角，终止的条件是行号i==0,或者列好j==N-1
            {
                     for(int row = cross;row>=0;row--)
                     {
                             a[row][cross - row] = count++;
                     }
            }
            else{
                     for(int col = cross;col>=0;col--)//如果填充第奇数数条斜线，那么输出的方向是做右上角到左下角
                     {
                             a[cross - col][col] = count++;
                     }
                 
            }
    }
    //填充右下角矩阵，不包括对角线
    int limit = 1;//记录终止的行列号
    for(cross = N-2;cross>=0;cross--)
    {
            if(cross %2 == 0)
            {
                     for(int row = N-1;row>=limit;row--)
                     {
                             a[row][limit+N-1-row] = count++;
                     }
                     limit++;
            }
            else{
                     for(int col = N-1;col>=limit;col--)
                     {
                             a[limit+N-1-col][col] = count++;
                     }
                     limit++;
                 
            }
    }
    display(a,N);
    getchar();
    return 0;
}
