#include<stdio.h>
#include<string.h>
int main()
{
	int a,d,e,f,g,h;
	long long b,c,i,j;
	char k[40];
	scanf("%d%c",&h,&k[0]);
	for(h;h>0;h--)
	{
		gets(k);
		g=strlen(k);
		for(a=0,b=0,d=0,e=0,i=1,j=0;a<g;a++)
		{
			if(k[a]=='*')
			{
				if(e==1)
				{
					i*=d;
					c*=d;
					d=0;
				}
				else
				{
					b+=d;
					i*=b;
					c=d;
					d=0;
					e=1;
				}
			}
			else if(k[a]=='+')
			{
				if(e==1)
				{
					b=d;
					c*=d;
					j+=c;
					c=0;
					d=0;
					e=2;
				}
				else
				{
					b+=d;
					j+=d;
					d=0;
				}
			}
			else
			{
				d*=10;
				d+=k[a]-48;
			}
		}
		if(e==1)
		{
			i*=d;
			c*=d;
			j+=c;
		}
		else
		{
			b+=d;
			i*=b;
			j+=d;
		}
		printf("The maximum and minimum are %lld and %lld.\n",i,j);
	}
	return 0;
}