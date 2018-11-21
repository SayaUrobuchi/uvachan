#include<stdio.h>
#include<string.h>
int main()
{
	int a,c,d,e,f,g,h,i,j;
	unsigned int b;
	char k[8];
	while(scanf("%d%c",&a,&k[0])==2)
	{
		if(a==0)
		{
			break;
		}
		b=0;
		c=1;
		i=2;
		j=3;
		for(a;a>0;a--)
		{
			gets(k);
			if(strcmp(k,"north")==0)
			{
				b++;
				b%=4;
			}
			else if(strcmp(k,"south")==0)
			{
				b--;
				b%=4;
			}
			else if(strcmp(k,"east")==0)
			{
				if(b==0)
				{
					d=c;
					c=j;
					j=7-d;
				}
				else if(b==1)
				{
					d=c;
					c=7-i;
					i=d;
					d=c;
					c=j;
					j=7-d;
				}
				else if(b==2)
				{
					c=7-c;
					i=7-i;
					d=c;
					c=j;
					j=7-d;
				}
				else
				{
					d=c;
					c=i;
					i=7-d;
					d=c;
					c=j;
					j=7-d;
				}
				b=0;
			}
			else
			{
				if(b==0)
				{
					d=c;
					c=7-j;
					j=d;
				}
				else if(b==1)
				{
					d=c;
					c=7-i;
					i=d;
					d=c;
					c=7-j;
					j=d;
				}
				else if(b==2)
				{
					c=7-c;
					i=7-i;
					d=c;
					c=7-j;
					j=d;
				}
				else
				{
					d=c;
					c=i;
					i=7-d;
					d=c;
					c=7-j;
					j=d;
				}
				b=0;
			}
		}
		if(b==1)
		{
			d=c;
			c=7-i;
			i=d;
		}
		else if(b==2)
		{
			c=7-c;
			i=7-i;
		}
		else if(b==3)
		{
			d=c;
			c=i;
			i=7-c;
		}
		printf("%d\n",c);
	}
	return 0;
}