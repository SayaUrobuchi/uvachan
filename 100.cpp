#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a>b)
		{
			c=b;
			g=a+1;
		}
		else
		{
			c=a;
			g=b+1;
		}
		for(d=0;c<g;c++)
		{
			e=c;
			f=1;
			while(e>1)
			{
				if(e%2==0)
				{
					e/=2;
				}
				else
				{
					e*=3;
					e+=1;
				}
				f++;
			}
			if(f>d)
			{
				d=f;
			}
		}
		printf("%d %d %d\n",a,b,d);
	}
	return 0;
}
