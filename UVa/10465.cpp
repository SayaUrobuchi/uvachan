#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	while(scanf("%d%d%d",&b,&c,&a)==3)
	{
		if(b>c)
		{
			d=b;
			b=c;
			c=d;
		}
		d=a/b;
		e=b*d;
		if(e==a)
		{
			printf("%d\n",d);
			continue;
		}
		i=d;
		j=a-e;
		e+=c;
		f=d;
		d++;
		while(f>-1)
		{
			if(a>e)
			{
				if(a-e<j)
				{
					j=a-e;
					i=d;
				}
				e+=c;
				d++;
			}
			else if(a<e)
			{
				e-=b;
				d--;
				f--;
			}
			else
			{
				printf("%d\n",d);
				break;
			}
		}
		if(f==-1)
		{
			printf("%d %d\n",i,j);
		}
	}
	return 0;
}