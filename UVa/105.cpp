#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[10000];
	for(a=1;a<10000;a++)
	{
		k[a]=0;
	}
	f=0;
	while(scanf("%d %d %d",&a,&b,&c)==3)
	{
		if(c>f)
		{
			f=c;
		}
		for(d=a;d<c;d++)
		{
			if(k[d]<b)
			{
				k[d]=b;
			}
		}
	}
	for(a=1,c=0;a<f;a++)
	{
		if(k[a]!=c)
		{
			c=k[a];
			b=1;
			printf("%d %d ",a,k[a]);
		}
	}
	printf("%d %d\n",f,k[f]);
	return 0;
}