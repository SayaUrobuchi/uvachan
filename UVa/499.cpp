#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[123];
	char x;
	for(a=65;a<91;a++)
	{
		k[a]=0;
	}
	for(a=97;a<123;a++)
	{
		k[a]=0;
	}
	i=0;
	while(scanf("%c",&x)==1)
	{
		if(x==10)
		{
			for(a=65;a<91;a++)
			{
				if(k[a]==i)
				{
					printf("%c",a);
				}
				k[a]=0;
			}
			for(a=97;a<123;a++)
			{
				if(k[a]==i)
				{
					printf("%c",a);
				}
				k[a]=0;
			}
			printf(" %d\n",i);
			i=0;
			continue;
		}
		if(x>64&&x<91)
		{
			k[x]++;
			if(k[x]>i)
			{
				i=k[x];
			}
		}
		else if(x>96&&x<123)
		{
			k[x]++;
			if(k[x]>i)
			{
				i=k[x];
			}
		}
	}
	return 0;
}