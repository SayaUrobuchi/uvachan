#include<stdio.h>
int main()
{
	int a,b,c;
	char x;
	while(scanf("%d",&a)==1)
	{
		printf("q(x):");
		c=0;
		while(scanf("%d%c",&b,&x)==2)
		{
			if(x==10)
			{
				c*=a;
				c+=b;
				printf("\nr = %d\n\n",c);
				break;
			}
			c*=a;
			c+=b;
			printf(" %d",c);
		}
	}
	return 0;
}