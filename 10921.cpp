#include<stdio.h>
int abcc(int x)
{
	if(x>64)
	{
		if(x<83)
		{
			x-=59;
		}
		else if(x<90)
		{
			x-=60;
		}
		else
		{
			x-=61;
		}
		x/=3;
		return x+48;
	}
	else
	{
		return x;
	}
}
int main()
{
	char c;
	while(scanf("%c",&c)==1)
	{
		c=abcc(c);
		printf("%c",c);
	}
	return 0;
}