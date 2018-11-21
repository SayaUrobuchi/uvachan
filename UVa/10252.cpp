#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int abcc(const void *p,const void *q)
{
	return *(char*)p-*(char*)q;
}
int main()
{
	int a,b,c,d,e,f,g,h;
	char i[1001],j[1001],k[1001];
	while(gets(i))
	{
		a=strlen(i);
		qsort(i,a,sizeof(char),abcc);
		gets(j);
		b=strlen(j);
		qsort(j,b,sizeof(char),abcc);
		for(c=0,d=0,e=0;c<a&&d<b;)
		{
			if(i[c]==j[d])
			{
				k[e++]=i[c];
				c++;
				d++;
			}
			else if(i[c]<j[d])
			{
				c++;
			}
			else
			{
				d++;
			}
		}
		k[e]='\0';
		printf("%s\n",k);
	}
	return 0;
}