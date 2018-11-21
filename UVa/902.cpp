#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char x[11];
	int y;
}abc;
int abcc(const void *p,const void *q)
{
	return strcmp((*(abc*)p).x,(*(abc*)q).x);
}
int a,b,c,d,e,f,g,h,i,j;
abc k[700000];
char l[700000];
int main()
{
	while(scanf("%d%s",&a,l)==2)
	{
		b=strlen(l);
		for(c=0,d=b-a+1;c<d;c++)
		{
			for(e=0,f=c;e<a;e++,f++)
			{
				k[c].x[e]=l[f];
			}
			k[c].x[e]=0;
			k[c].y=1;
		}
		qsort(k,d,sizeof(abc),abcc);
		for(c=1,j=1,i=0;c<d;c++)
		{
			if(!strcmp(k[c].x,k[c-1].x))
			{
				j++;
			}
			else
			{
				if(j>i)
				{
					i=j;
					strcpy(l,k[c-1].x);
				}
				j=1;
			}
		}
		printf("%s\n",l);
	}
	return 0;
}