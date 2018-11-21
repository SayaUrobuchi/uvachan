#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[45];
	k[1]=1;
	k[2]=2;
	for(b=3;b<45;b++)
	{
		k[b]=k[b-1]+k[b-2];
	}
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d",&a);
		for(b=44;b>0;b--)
		{
			if(k[b]<=a)
			{
				break;
			}
		}
		for(b;b>0;b--)
		{
			if(k[b]<=a)
			{
				a-=k[b];
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}