#include<stdio.h>
#include<stdlib.h>
int abcc(const void *p,const void *q)
{
	return *(int*)p-*(int*)q;
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[10000];
	while(scanf("%d",&a)==1)
	{
		for(b=0;b<a;b++)
		{
			scanf("%d",&k[b]);
		}
		qsort(k,a,sizeof(int),abcc);
		a--;
		scanf("%d",&i);
		b=i/2;
		c=0;
		d=a;
		while(1)
		{
			e=c+d;
			e/=2;
			if(k[e]==b)
			{
				break;
			}
			else if(k[e]>b)
			{
				d=e-1;
				if(c>d)
				{
					e++;
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
		if(k[e]-b>b-k[e-1])
		{
			e--;
		}
		for(g=e;g>-1;g--)
		{
			f=i-k[g];
			c=0;
			d=a;
			while(1)
			{
				e=c+d;
				e/=2;
				if(k[e]==f)
				{
					if(k[g]>f)
					{
						printf("Peter should buy books whose prices are %d and %d.\n\n",f,k[g]);
					}
					else
					{
						printf("Peter should buy books whose prices are %d and %d.\n\n",k[g],f);
					}
					break;
				}
				else if(k[e]>f)
				{
					d=e-1;
					if(c>d)
					{
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
			if(k[e]==f)
			{
				break;
			}
		}
	}
	return 0;
}
