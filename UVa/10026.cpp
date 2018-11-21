#include<stdio.h>
#include<stdlib.h>
typedef struct abc
{
	int i;
	double j;
}abc;
int abcc(const void *p,const void *q)
{
	if((*(abc*)p).j==(*(abc*)q).j)
	{
		return (*(abc*)p).i-(*(abc*)q).i;
	}
	else
	{
		if((*(abc*)p).j<(*(abc*)q).j)
		{
			return 1;
		}
		else if((*(abc*)p).j>(*(abc*)q).j)
		{
			return -1;
		}
	}
}
int main()
{
	int a,b,c,d,e,f,g,h;
	char check;
	abc k[1001];
	check = 0;
	k[0].j=0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(check) printf("\n");
		check = 1;
		scanf("%d",&g);
		for(a=0;a<g;a++)
		{
			scanf("%d%d",&b,&c);
			k[a].i=a+1;
			k[a].j=c;
			k[a].j/=b;
		}
		qsort(k,g,sizeof(abc),abcc);
		printf("%d",k[0].i);
		for(a=1;a<g;a++)
		{
			printf(" %d",k[a].i);
		}
		printf("\n");
	}
	return 0;
}
