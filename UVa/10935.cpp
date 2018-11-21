#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[60];
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		if(a==1)
		{
			printf("Discarded cards:\n");
			printf("Remaining card: 1\n");
			continue;
		}
		for(b=2;b<=a;b++)
		{
			k[b]=1;
		}
		printf("Discarded cards: 1");
		for(b=2,c=a,d=0;c>2;b++)
		{
			if(b>a)
			{
				b=2;
			}
			d+=k[b];
			if(d==2)
			{
				k[b]=0;
				printf(", %d",b);
				d=0;
				c--;
			}
		}
		for(b=2;b<=a;b+=2)
		{
			if(k[b]==1)
			{
				printf("\nRemaining card: %d\n",b);
				break;
			}
		}
	}
	return 0;
}