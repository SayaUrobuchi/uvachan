#include<stdio.h>
#include<string.h>
int main()
{
	int a;
	char x;
	while(scanf("%c",&x)==1)
	{
		if(x==10)
		{
			a=0;
			printf("\n");
		}
		else if(x=='B'||x=='F'||x=='P'||x=='V')
		{
			if(a!=1)
			{
				printf("1");
				a=1;
			}
		}
		else if(x=='C'||x=='G'||x=='J'||x=='K'||x=='Q'||x=='S'||x=='X'||x=='Z')
		{
			if(a!=2)
			{
				printf("2");
				a=2;
			}
		}
		else if(x=='D'||x=='T')
		{
			if(a!=3)
			{
				printf("3");
				a=3;
			}
		}
		else if(x=='L')
		{
			if(a!=4)
			{
				printf("4");
				a=4;
			}
		}
		else if(x=='M'||x=='N')
		{
			if(a!=5)
			{
				printf("5");
				a=5;
			}
		}
		else if(x=='R')
		{
			if(a!=6)
			{
				printf("6");
				a=6;
			}
		}
		else
		{
			a=0;
		}
	}
	return 0;
}