#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	long long k[21];
	k[1]=1;
	for(a=2;a<21;a++)
	{
		k[a]=2*a-1;
		k[a]*=2;
		k[a]*=k[a-1];
		k[a]/=a+1;
	}
	while(scanf("%d",&a)==1)
	{
		b=1;
		c=20;
		while(1)
		{
			d=b+c;
			d/=2;
			if(k[d]==a)
			{
				printf("%d\n",d);
				break;
			}
			else if(k[d]>a)
			{
				c=d-1;
				if(b>c)
				{
					break;
				}
			}
			else
			{
				b=d+1;
				if(b>c)
				{
					break;
				}
			}
		}
	}
	return 0;
}