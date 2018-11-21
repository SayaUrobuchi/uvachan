#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char z[86];
}abc;
int abcc(const void *p,const void *q)
{
	char w[171],x[171];
	strcpy(w,(*(abc*)p).z);
	strcpy(x,(*(abc*)q).z);
	strcat(w,(*(abc*)q).z);
	strcat(x,(*(abc*)p).z);
	return strcmp(x,w);
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	abc k[50];
	char l[4251];
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		for(b=0;b<a;b++)
		{
			scanf("%s",k[b].z);
		}
		qsort(k,b,sizeof(abc),abcc);
		l[0]=0;
		for(b=0;b<a;b++)
		{
			strcat(l,k[b].z);
		}
		printf("%s\n",l);
	}
	return 0;
}