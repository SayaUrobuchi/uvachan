#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int i,j;
}abc;
int abcc(const void *p,const void *q)
{
	return (*(abc*)q).j-(*(abc*)p).j;
}
int main()
{
	int a,b,c,d,e,f,g,h,x[5607];
	abc k[5607];
	a=0;
	while(scanf("%d%d",&k[a].i,&k[a].j)==2)
	{
		a++;
	}
	qsort(k,a,sizeof(abc),abcc);
	x[0]=k[0].j-k[0].i;
	for(b=1,c=0;b<a;b++)
	{
		d=c;
		f=k[b].j-k[b].i;
		if(k[b].i<=x[c])
		{
			x[c+1]=x[c++]-k[b].i;
			if(f<x[c])
			{
				x[c]=f;
			}
		}
		for(d--;d>-1;d--)
		{
			if(k[b].i<=x[d])
			{
				e=x[d]-k[b].i;
				if(e>f)
				{
					e=f;
				}
				if(e>x[d+1])
				{
					x[d+1]=e;
				}
			}
		}
		if(f>x[0])
		{
			x[0]=f;
		}
	}
	printf("%d\n",c+1);
	return 0;
}