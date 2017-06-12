#include<stdio.h>
int a,b,c,f,g,h,l;
char j[10],k[12];
unsigned long long d,e,i;
int abcc(int x)
{
	if(x<2)
	{
		return 1;
	}
	return x*abcc(x-1);
}
int main()
{
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		for(b=0;b<10;b++)
		{
			j[b]=0;
		}
		for(b=0,c=0;b<a;b++)
		{
			scanf("%d",&k[b]);
			j[k[b]]++;
		}
		for(b=0,d=abcc(a-1),l=0;b<10;b++)
		{
			if(j[b])
			{
				j[b]--;
				for(c=0,e=d;c<10;c++)
				{
					e/=abcc(j[c]);
				}
				l+=e*b;
				j[b]++;
			}
		}
		for(b=0,i=0;b<a;b++)
		{
			i*=10;
			i+=l;
		}
		printf("%llu\n",i);
	}
	return 0;
}