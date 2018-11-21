#include<stdio.h>
int abcc(int x,int y)
{
	int w,z;
	w=0;
	if(x>y)
	{
		z=x/y;
		if(z>1)
		{
			return 1;
		}
		x%=y;
		w++;
	}
	while(1)
	{
		z=y/x;
		y%=x;
		w++;
		if(y==0)
		{
			return w%2;
		}
		if(z>1)
		{
			return w%2;
		}
		z=x/y;
		x%=y;
		w++;
		if(x==0)
		{
			return w%2;
		}
		if(z>1)
		{
			return w%2;
		}
	}
}
int main()
{
	int a,b,c,d,e,f,g,h;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0&&b==0)
		{
			break;
		}
		c=abcc(a,b);
		if(c==1)
		{
			printf("Stan wins\n");
		}
		else
		{
			printf("Ollie wins\n");
		}
	}
	return 0;
}