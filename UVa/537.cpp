#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h;
	double i,j,p;
	char k,x,y[300];
	scanf("%d%c",&h,&x);
	for(g=0;h>0;h--)
	{
		f=0;
		while(scanf("%c",&x)==1)
		{
			if(x==10)
			{
				break;
			}
			if(x=='=')
			{
				scanf("%lf",&i);
				if(k=='U')
				{
					e=1;
				}
				else if(k=='I')
				{
					e=2;
				}
				else
				{
					e=3;
				}
				scanf("%c",&x);
				if(x=='m')
				{
					i*=0.001;
				}
				else if(x=='k')
				{
					i*=1000;
				}
				else if(x=='M')
				{
					i*=1000000;
				}
				if(f>0)
				{
					gets(y);
					break;
				}
				j=i;
				f=e;
			}
			k=x;
		}
		if(e>f)
		{
			d=e;
			e=f;
			f=d;
			p=i;
			i=j;
			j=p;
		}
		printf("Problem #%d\n",++g);
		if(f==3)
		{
			if(e==1)
			{
				printf("I=%.2fA\n\n",j/i);
			}
			else
			{
				printf("U=%.2fV\n\n",j/i);
			}
		}
		else
		{
			printf("P=%.2fW\n\n",i*j);
		}
	}
	return 0;
}