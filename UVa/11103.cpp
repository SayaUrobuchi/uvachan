#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a,b,c,d,e,f,g,h,i,j;
char k[105],l[105];
int abcc()
{
	if(a==b)
	{
		return 0;
	}
	int w,x;
	l[c++]=k[a];
	if(k[a]>111&&k[a]<117)
	{
		return 1;
	}
	else if(k[a]=='N')
	{
		a++;
		if(abcc())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		a++;
		if(abcc())
		{
			a++;
			if(abcc())
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
}
int abc(const void *p,const void *q)
{
	int w,x;
	if(*(char*)p=='K'||*(char*)p=='A'||*(char*)p=='C'||*(char*)p=='E')
	{
		w=2;
	}
	else if(*(char*)p=='N')
	{
		w=1;
	}
	else
	{
		w=0;
	}
	if(*(char*)q=='K'||*(char*)q=='A'||*(char*)q=='C'||*(char*)q=='E')
	{
		x=2;
	}
	else if(*(char*)q=='N')
	{
		x=1;
	}
	else
	{
		x=0;
	}
	return x-w;
}
int main()
{
	while(gets(k))
	{
		if(!strcmp(k,"0"))
		{
			break;
		}
		b=strlen(k);
		qsort(k,b,sizeof(char),abc);
		for(d=0,i=0;d<b;d++)
		{
			a=d;
			c=0;
			e=abcc();
			if(c>i&&e)
			{
				l[c]=0;
				i=1;
				break;
			}
		}
		if(i)
		{
			printf("%s\n",l);
		}
		else
		{
			printf("no WFF possible\n");
		}
	}
	return 0;
}