#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	while(scanf("%d %d",&a,&b)==2)
	{
		c=a/b;
		printf("[%d;",c);
		a%=b;
		if(a==0)
		{
			printf("]\n");
			continue;
		}
		c=b/a;
		printf("%d",c);
		b%=a;
		if(b==0)
		{
			printf("]\n");
			continue;
		}
		while(1)
		{
			c=a/b;
			printf(",%d",c);
			a%=b;
			if(a==0)
			{
				break;
			}
			c=b/a;
			printf(",%d",c);
			b%=a;
			if(b==0)
			{
				break;
			}
		}
		printf("]\n");
	}
	return 0;
}