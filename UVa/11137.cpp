#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,l[20];
	double k[10000];
	for(a=0;a<10000;a++)
	{
		k[a]=1;
	}
	for(a=2,b=0;a*a*a<10000;a++,b++)
	{
		l[b]=a*a*a;
	}
	for(a=0;a<20;a++)
	{
		for(b=l[a];b<10000;b++)
		{
			k[b]+=k[b-l[a]];
		}
	}
	while(scanf("%d",&a)==1)
	{
		printf("%.0f\n",k[a]);
	}
	return 0;
}