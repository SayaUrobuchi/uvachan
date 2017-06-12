#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int abcc(const void *p,const void *q)
{
	return *(char*)p-*(char*)q;
}
int main()
{
	int a,b,c,d,e,g,h,i[8],j[]={2,3,5,7,11,13,17,19},k[21][8];
	unsigned long f;
	char x[21];
	k[1][0]=0;
	for(a=2;a<21;a++)
	{
		for(b=0;b<8&&j[b]<a;b++)
		{
			k[a][b]=k[a-1][b];
		}
		if(j[b]==a)
		{
			k[a][b]=0;
		}
		for(b=0,c=a;c>1;b++)
		{
			while(c%j[b]==0)
			{
				k[a][b]++;
				c/=j[b];
			}
		}
	}
	scanf("%d",&h);
	gets(x);
	g=0;
	for(h;h>0;h--)
	{
		gets(x);
		a=strlen(x);
		qsort(x,a,sizeof(char),abcc);
		for(b=0;a>=j[b]&&b<8;b++)
		{
			i[b]=k[a][b];
		}
		for(b=1,c=x[0],d=1;b<a;b++)
		{
			if(x[b]==c)
			{
				d++;
			}
			else
			{
				for(e=0;j[e]<=d&&e<8;e++)
				{
					i[e]-=k[d][e];
				}
				d=1;
				c=x[b];
			}
		}
		if(d>1)
		{
			for(e=0;j[e]<=d&&e<8;e++)
			{
				i[e]-=k[d][e];
			}
		}
		for(e=0,f=1;j[e]<=a&&e<8;e++)
		{
			f*=pow(j[e],i[e]);
		}
		printf("Data set %d: %lu\n",++g,f);
	}
	return 0;
}