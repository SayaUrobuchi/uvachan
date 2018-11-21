#include<stdio.h>
#include<stdlib.h>
int a,b,c,d,e,f,g,h,i,j,k[500000],l[500000];
int abcc(const void *p,const void *q)
{
	return *(int*)p-*(int*)q;
}
int main()
{
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		for(b=0;b<a;b++)
		{
			scanf("%d%d",&k[b],&l[b]);
		}
		qsort(k,a,sizeof(int),abcc);
		qsort(l,a,sizeof(int),abcc);
		for(b=0;b<a;b++)
		{
			if(k[b]!=l[b])
			{
				break;
			}
		}
		if(b==a)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}