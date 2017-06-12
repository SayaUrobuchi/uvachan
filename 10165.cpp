#include<stdio.h>
int main()
{
	int a,b,c,d;
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		for(b=0,c=0;b<a;b++)
		{
			scanf("%d",&d);
			c^=d;
		}
		if(c==0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;
}