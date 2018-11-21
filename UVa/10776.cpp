#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a,b,c,d,e,f,g,h,i,j;
char k[31],x,y[31];
int abcc(const void *p,const void *q)
{
	return *(char*)p-*(char*)q;
}
int abc(int p)
{
	if(c==b)
	{
		printf("%s\n",y);
		return 0;
	}
	char q;
	q=0;
	for(p;p<a;p++)
	{
		if(k[p]!=q)
		{
			y[c]=k[p];
			c++;
			abc(p+1);
			c--;
			q=k[p];
		}
	}
}
int main()
{
	while(scanf("%s",&k)==1)
	{
		a=strlen(k);
		scanf("%d",&b);
		y[b]='\0';
		qsort(k,a,sizeof(char),abcc);
		c=0;
		abc(0);
	}
	return 0;
}