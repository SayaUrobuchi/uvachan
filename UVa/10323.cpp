#include<stdio.h>
int main()
{
	int a;
	int b[5];
	b[0]=40320;
	b[1]=362880;
	b[2]=3628800;
	b[3]=39916800;
	b[4]=479001600;
	while(scanf("%d",&a)==1)
	{
		if(a<0)
		{
			a*=-1;
			if(a%2==1)
			{
				printf("Overflow!\n");
				continue;
			}
			printf("Underflow!\n");
			continue;
		}
		if(a>7)
		{
			if(a>13)
			{
				printf("Overflow!\n");
				continue;
			}
			else if(a==13)
			{
				printf("6227020800\n");
				continue;
			}
			printf("%d\n",b[a-8]);
			continue;
		}
		printf("Underflow!\n");
	}
	return 0;
}