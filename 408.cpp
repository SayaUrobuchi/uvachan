#include<stdio.h>
int abcc(int x,int y)
{
	while(1)
	{
		x%=y;
		if(x<2)
		{
			return x;
		}
		y%=x;
		if(y<2)
		{
			return y;
		}
	}
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	while(scanf("%d %d",&a,&b)==2)
	{
		c=abcc(a,b);
		if(c==1)
		{
			printf("%10d%10d    Good Choice\n\n",a,b);
		}
		else
		{
			printf("%10d%10d    Bad Choice\n\n",a,b);
		}
	}
	return 0;
}