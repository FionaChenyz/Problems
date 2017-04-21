#include<stdio.h>
#define max(a,b) ((a)>(b)?a:b)
#define abs(a) ((a)>0?a:-(a))
int foo(int x,int y)
{
    int t=max(abs(x),abs(y));
    int u=t+t;
    int v=u-1;
    v=v*v+u;
    
    if(y==-t)
      v+=3*u-t+x;     //y==-t,v=(2t-1)^2+7t+x
    else if(x==-t)
      v+=u+t-y;       //x==-t,v=(2t-1)^2+5t-y
    else if(y==t)
      v+=t-x;         //y==t,v=(2t-1)^2+3t-x
    else
      v+=y-t;         //y==t,v=(2t-1)^2+t+y
    return v;
}   

int main()
{
   int x,y;
   for(y=-4;y<4;y++)
   {
       for(x=-4;x<4;x++)
          printf("%5d",foo(x,y));
          printf("\n");
   }
   while(scanf("%d%d",&x,&y)==2)
     printf("%d\n",foo(x,y));
   
   return 0;
}
