#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int i,j,x;
}abc;
int abcc(const void *p,const void *q)
{
	if((*(abc*)p).i==(*(abc*)q).i)
	{
		return (*(abc*)p).j-(*(abc*)q).j;
	}
	else
	{
		return (*(abc*)p).i-(*(abc*)q).i;
	}
}
int main()
{
	int a,b,c,d,e,f[1000],g[1000],h[1001];
	abc k[1000];
	a=0;
	while(scanf("%d%d",&k[a].i,&k[a].j)==2)
	{
		k[a].x=a+1;
		a++;
	}
	qsort(k,a,sizeof(abc),abcc);
	f[0]=k[0].j;
	g[0]=0;
	h[0]=-1;
	for(b=1,d=1;b<a;b++)
	{
		for(c=0;c<d;c++)
		{
			if(k[b].j>f[c])
			{
				f[c]=k[b].j;
				g[c]=b;
				if(c>0)
				{
					h[b]=g[c-1];
				}
				else
				{
					h[b]=-1;
				}
				break;
			}
		}
		if(c==d&&k[b].j<f[c-1])
		{
			f[c]=k[b].j;
			g[c]=b;
			h[b]=g[c-1];
			d++;
		}
	}
	printf("%d\n",d);
	for(a=0,b=g[d-1];h[b]!=-1;a++)
	{
		f[a]=k[b].x;
		b=h[b];
	}
	printf("%d\n",k[b].x);
	for(a-=1;a>-1;a--)
	{
		printf("%d\n",f[a]);
	}
	return 0;
}