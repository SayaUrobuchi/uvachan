#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char x[60];
}abc;
int abcc(const void *p,const void *q)
{
	return strcmp((*(abc*)p).x,(*(abc*)q).x);
}
int main()
{
	int a,b,c,d,e,f,g,h;
	abc k[2000];
	char y[300],z[60];
	c=0;
	d=0;
	e=0;
	while(gets(y))
	{
		a=strlen(y);
		for(b=0;b<a;b++)
		{
			if(y[b]>64&&y[b]<91)
			{
				z[c++]=y[b]+32;
			}
			else if(y[b]>96&&y[b]<123)
			{
				z[c++]=y[b];
			}
			else if(y[b]=='-')
			{
				if(b==a-1)
				{
					d=1;
				}
				else
				{
					z[c++]=y[b];
				}
			}
			else
			{
				if(c>0)
				{
					z[c]='\0';
					strcpy(k[e++].x,z);
					c=0;
				}
			}
		}
		if(d==0&&c>0)
		{
			z[c]='\0';
			strcpy(k[e++].x,z);
			c=0;
		}
		d=0;
	}
	qsort(k,e,sizeof(abc),abcc);
	printf("%s\n",k[0].x);
	for(a=1;a<e;a++)
	{
		if(strcmp(k[a].x,k[a-1].x)!=0)
		{
			printf("%s\n",k[a].x);
		}
	}
	return 0;
}