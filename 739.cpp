#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char x[35],y[26];
	for(a=0;a<35;a++)
	{
		x[a]=32;
	}
	printf("         NAME                     SOUNDEX CODE\n");
	while(gets(y))
	{
		a=strlen(y);
		x[9]='\0';
		printf("%s",x);
		x[9]=32;
		printf("%s",y);
		b=25-a;
		x[b]='\0';
		printf("%s",x);
		x[b]=32;
		printf("%c",y[0]);
		if(y[0]=='0'||y[0]=='P'||y[0]=='F'||y[0]=='V')
		{
			c=1;
		}
		else if(y[0]=='C'||y[0]=='S'||y[0]=='K'||y[0]=='G'||y[0]=='J'||y[0]=='Q'||y[0]=='X'||y[0]=='Z')
		{
			c=2;
		}
		else if(y[0]=='D'||y[0]=='T')
		{
			c=3;
		}
		else if(y[0]=='L')
		{
			c=4;
		}
		else if(y[0]=='M'||y[0]=='N')
		{
			c=5;
		}
		else if(y[0]=='R')
		{
			c=6;
		}
		else
		{
			c=0;
		}
		for(b=1,d=0;b<a;b++)
		{
			if(y[b]=='B'||y[b]=='P'||y[b]=='F'||y[b]=='V')
			{
				if(c!=1)
				{
					printf("1");
					d++;
					if(d==3)
					{
						break;
					}
					c=1;
				}
			}
			else if(y[b]=='C'||y[b]=='S'||y[b]=='K'||y[b]=='G'||y[b]=='J'||y[b]=='Q'||y[b]=='X'||y[b]=='Z')
			{
				if(c!=2)
				{
					printf("2");
					d++;
					if(d==3)
					{
						break;
					}
					c=2;
				}
			}
			else if(y[b]=='D'||y[b]=='T')
			{
				if(c!=3)
				{
					printf("3");
					d++;
					if(d==3)
					{
						break;
					}
					c=3;
				}
			}
			else if(y[b]=='L')
			{
				if(c!=4)
				{
					printf("4");
					d++;
					if(d==3)
					{
						break;
					}
					c=4;
				}
			}
			else if(y[b]=='M'||y[b]=='N')
			{
				if(c!=5)
				{
					printf("5");
					d++;
					if(d==3)
					{
						break;
					}
					c=5;
				}
			}
			else if(y[b]=='R')
			{
				if(c!=6)
				{
					printf("6");
					d++;
					if(d==3)
					{
						break;
					}
					c=6;
				}
			}
			else
			{
				c=0;
			}
		}
		for(d;d<3;d++)
		{
			printf("0");
		}
		printf("\n");
	}
	printf("                   END OF OUTPUT\n");
	return 0;
}