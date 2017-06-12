#include<stdio.h>
#include<string.h>
int a;
int h;
char k[11];
int abcc()
{
	int x,y;
	x=1;
	y=0;
	while(gets(k))
	{
		if(strcmp(k,"IF")==0)
		{
			x*=abcc();
		}
		else if(strcmp(k,"ELSE")==0)
		{
			y=x;
			x=1;
		}
		else if(strcmp(k,"END_IF")==0)
		{
			return x+y;
		}
	}
}
int main()
{
	scanf("%d",&h);
	gets(k);
	for(h;h>0;h--)
	{
		a=1;
		while(gets(k))
		{
			if(strcmp(k,"IF")==0)
			{
				a*=abcc();
			}
			else if(strcmp(k,"ENDPROGRAM")==0)
			{
				printf("%d\n",a);
				break;
			}
		}
	}
	return 0;
}