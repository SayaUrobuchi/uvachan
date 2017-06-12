#include<stdio.h>
int main()
{
	int a,b,c,k[100];
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0||a<b)
		{
			printf("Boring!\n");
			continue;
		}
		if(b<2)
		{
			printf("Boring!\n");
			continue;
		}
		for(c=0;a>1;a/=b)
		{
			if(a%b==0)
			{
				k[c++]=a;
			}
			else
			{
				break;
			}
		}
		if(a>1)
		{
			printf("Boring!\n");
		}
		else
		{
			for(b=0;b<c;b++)
			{
				printf("%d ",k[b]);
			}
			printf("1\n");
		}
	}
	return 0;
}