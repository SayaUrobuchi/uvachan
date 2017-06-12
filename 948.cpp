#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[44],l;
int main()
{
	k[0]=1;
	k[1]=1;
	for(a=2;a<44;a++)
	{
		k[a]=k[a-1]+k[a-2];
	}
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d",&a);
		c=0;
		d=43;
		while(1)
		{
			e=c+d;
			e/=2;
			if(k[e]==a)
			{
				break;
			}
			else if(k[e]>a)
			{
				d=e-1;
				if(c>d)
				{
					e--;
					break;
				}
			}
			else
			{
				c=e+1;
				if(c>d)
				{
					break;
				}
			}
		}
		printf("%d = ",a);
		for(e;e>0;e--)
		{
			if(k[e]<a+1)
			{
				a-=k[e];
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf(" (fib)\n");
	}
	return 0;
}