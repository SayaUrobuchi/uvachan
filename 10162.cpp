#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c;
	char k[10]={0,1,5,2,8,3,9,2,8,7},l[10]={0,1,7,0,6,1,7,4,8,7},x[105];
	while(gets(x))
	{
		if(strcmp(x,"0")==0)
		{
			break;
		}
		a=strlen(x);
		b=x[--a]-48;
		c=0;
		if(a>0)
		{
			c=x[--a]-48;
		}
		if(c%2==0)
		{
			b=k[b];
		}
		else
		{
			b=l[b];
		}
		b+=c*7;
		b%=10;
		printf("%d\n",b);
	}
	return 0;
}