#include<stdio.h>
#include<stdlib.h>
int a,b,c,d,e,f,g,h,i,j,k[1000000];
int abcc(const void *p,const void *q)
{
	return *(int*)p-*(int*)q;
}
int main()
{
	while(scanf("%d",&a)==1)
	{
		for(b=0;b<a;b++)
		{
			scanf("%d",&k[b]);
		}
		qsort(k,a,sizeof(int),abcc);
		if(a%2)
		{
			b=a/2;
			for(d=b-1;d>-1;d--)
			{
				if(k[d]!=k[b])
				{
					break;
				}
			}
			for(e=b+1;e<a;e++)
			{
				if(k[e]!=k[b])
				{
					break;
				}
			}
			printf("%d %d %d\n",k[b],e-d-1,1);
		}
		else
		{
			c=a/2;
			b=c-1;
			for(d=b-1;d>-1;d--)
			{
				if(k[d]!=k[b])
				{
					break;
				}
			}
			for(e=c+1;e<a;e++)
			{
				if(k[e]!=k[c])
				{
					break;
				}
			}
			printf("%d %d %d\n",k[b],e-d-1,k[c]-k[b]+1);
		}
	}
	return 0;
}