#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct abc
{
	int i,j;
}abc;
abc z[52],k[52];
int abcc(const void *p,const void *q)
{
	return (*(abc*)p).i-(*(abc*)q).i;
}
int bca(int s)
{
	if(s<26)
	{
		return s+65;
	}
	else
	{
		return s+71;
	}
}
int bcaa(char w)
{
	if(w>64&&w<91)
	{
		return bca(k[z[w-65].i].j);
	}
	else if(w>96&&w<123)
	{
		return bca(k[z[w-71].i].j);
	}
	else
	{
		return w;
	}
}
int main()
{
	int a,b,c,d,e,f,g,h;
	char x,y[8000],s;
	s=0;
	scanf("%d%c",&h,&x);
	for(h;h>0;h--)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		gets(y);
		gets(y);
		for(a=0;a<52;a++)
		{
			k[a].i=0;
			k[a].j=a;
		}
		a=strlen(y);
		for(b=0;b<a;b++)
		{
			if(y[b]>64&&y[b]<91)
			{
				k[y[b]-65].i++;
			}
			else if(y[b]>96&&y[b]<123)
			{
				k[y[b]-71].i++;
			}
		}
		qsort(k,52,sizeof(abc),abcc);
		gets(y);
		for(a=0;a<52;a++)
		{
			z[a].i=0;
			z[a].j=a;
		}
		a=strlen(y);
		for(b=0;b<a;b++)
		{
			if(y[b]>64&&y[b]<91)
			{
				z[y[b]-65].i++;
			}
			else if(y[b]>96&&y[b]<123)
			{
				z[y[b]-71].i++;
			}
		}
		qsort(z,52,sizeof(abc),abcc);
		for(b=0;b<52;b++)
		{
			z[z[b].j].i=b;
		}
		for(b=0;b<a;b++)
		{
			printf("%c",bcaa(y[b]));
		}
		printf("\n");
	}
	return 0;
}