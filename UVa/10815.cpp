#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct abc
{
	char j[31];
}abc;
int abcc(const void *p,const void *q)
{
	return strcmp((*(abc*)p).j,(*(abc*)q).j);
}
int main()
{
	int a,b,c,d,e,f;
	abc i[50000];
	char x[31];
	a=0;
	b=0;
	while(scanf("%c",&x[b])==1)
	{
		if(x[b]>64&&x[b]<91)
		{
			x[b]+=32;
			b++;
		}
		else if(x[b]>96&&x[b]<123)
		{
			b++;
		}
		else
		{
			if(b==0)
			{
				continue;
			}
			x[b]='\0';
			strcpy(i[a].j,x);
			a++;
			b=0;
		}
	}
	qsort(i,a,sizeof(abc),abcc);
	printf("%s\n",i[0].j);
	for(b=1;b<a;b++)
	{
		if(strcmp(i[b].j,i[b-1].j)!=0)
		{
			printf("%s\n",i[b].j);
		}
	}
	return 0;
}