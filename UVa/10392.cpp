#include<stdio.h>
#include<math.h>
int main()
{
	int c;
	long long int a,b;
	while(scanf("%lld",&a)==1)
	{
		if(a<0)
		{
			break;
		}
		c=sqrt(a);
		if(a%2==0)
		{
			printf("    2\n");
			a/=2;
			if(a%2==0)
			{
				for(;;)
				{
					printf("    2\n");
					a/=2;
					if(a%2==1)
					{
						break;
					}
				}
			}
		}
		for(b=3;b<=c;b+=2)
		{
			if(a%b==0)
			{
				printf("    %lld\n",b);
				a/=b;
				if(a%b==0)
				{
					for(;;)
					{
						printf("    %lld\n",b);
						a/=b;
						if(a%b!=0)
						{
							break;
						}
					}
				}
			}
			if(a<b)
			{
				break;
			}
		}
		if(a>1)
		{
			printf("    %lld\n",a);
		}
		printf("\n");
	}
	return 0;
}