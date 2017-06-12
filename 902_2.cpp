#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a,b,c,d,e,f,g,h,i,j;
long long k[700000],m[11];
char l[700000];
int abcc(const void *p,const void *q)
{
	if(*(long long*)p<*(long long*)q)
	{
		return -1;
	}
	else if(*(long long*)p>*(long long*)q)
	{
		return 1;
	}
	return 0;
}
int main()
{
	m[1]=1;
	for(a=2;a<11;a++)
	{
		m[a]=m[a-1]*26;
	}
	while(scanf("%d%s",&a,l)==2)
	{
		k[0]=0;
		c=strlen(l);
		for(b=0;b<a;b++)
		{
			k[0]*=26;
			l[b]-=97;
			k[0]+=l[b];
		}
		for(d=1;b<c;b++,d++)
		{
			k[d]=k[d-1]-l[d-1]*m[a];
			k[d]*=26;
			l[b]-=97;
			k[d]+=l[b];
		}
		qsort(k,d,sizeof(long long),abcc);
		for(b=1,i=0,j=1;b<d;b++)
		{
			if(k[b]==k[b-1])
			{
				j++;
			}
			else
			{
				if(j>i)
				{
					i=j;
					g=b-1;
				}
				j=1;
			}
		}
		l[a]=0;
		for(b=a-1;b>-1;b--)
		{
			l[b]=k[g]%26+97;
			k[g]/=26;
		}
		printf("%s\n",l);
	}
	return 0;
}