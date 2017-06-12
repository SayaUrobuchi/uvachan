#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j;
char k[260],x;
int abcc(char y)
{
	if(y=='N')
	{
		c++;
		d=abcc(k[c-1]);
		return d;
	}
	else if(y<91&&y>65)
	{
		c++;
		d=abcc(k[c-1]);
		if(d==1)
		{
			c++;
			d=abcc(k[c-1]);
			return d;
		}
		return 0;
	}
	else if(y>91)
	{
		return 1;
	}
	return 0;
}
int main()
{
	while(scanf("%s",&k)==1)
	{
		a=strlen(k);
		if(k[0]>91)
		{
			if(a>1)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
		}
		else
		{
			c=1;
			a--;
			b=abcc(k[0]);
			if(b==1&&c>a)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}