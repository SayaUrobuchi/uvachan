#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char y[21];
	char i[21];
	int j;
}abc;
int abcc(const void *p,const void *q)
{
	if((*(abc*)p).j==(*(abc*)q).j)
	{
		return strcmp((*(abc*)p).y,(*(abc*)q).y);
	}
	else
	{
		return (*(abc*)p).j-(*(abc*)q).j;
	}
}
int main()
{
	int a,b,c,d,e,f,g,h;
	abc k[100];
	char x[4];
	while(scanf("%d",&a)==1)
	{
		for(b=0;b<a;b++)
		{
			scanf("%s",&k[b].i);
			c=strlen(k[b].i);
			for(d=0;d<c;d++)
			{
				k[b].y[d]=k[b].i[d];
				if(k[b].y[d]>64&&k[b].y[d]<91)
				{
					k[b].y[d]+=32;
				}
			}
			scanf("%s",&x);
			scanf("%d%s",&c,&x);
			k[b].j=c*100000;
			scanf("%d%s",&c,&x);
			k[b].j+=c*1000;
			scanf("%d%s",&c,&x);
			k[b].j+=c;
		}
		qsort(k,a,sizeof(abc),abcc);
		for(b=0,c=1;b<a;c++)
		{
			printf("Row %d\n",c);
			for(b,d=2;b<a&&d>0;b++,d--)
			{
				printf("%s\n",k[b].i);
			}
		}
		printf("\n");
	}
	return 0;
}
