#include<stdio.h>
int a,b,c,d,e,f,g,h;
int def()
{
}
int abc()
{
	e=c*2-1;
	f=a-d;
	if(f>=e)
	{
		d+=e;
		if(d==b)
		{
			g=1;
			printf("Let me try!\n");
		}
		else
		{
			c++;
			h=0;
			abc();
			c--;
			e=c*2-1;
			d-=e;
		}
	}
	if(d>e&&g!=1)
	{
		d-=e;
		if(d==b)
		{
			g=1;
			printf("Let me try!\n");
		}
		else
		{
			c++;
			h=0;
			abc();
			c--;
			e=c*2-1;
			d+=e;
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d %d",&a,&b)==2)
	{
		if(a==0&&b==0)
		{
			break;
		}
		else
		{
			if(a>=49)
			{
				printf("Let me try!\n");
			}
			else if(b==1)
			{
		        printf("Let me try!\n");
			}
			else
			{
				c=2;
				d=1;
				abc();
				if(g!=1)
				{
				    printf("Don't make fun of me!\n");
				}
				g=0;
			}
		}
	}
	return 0;
}
