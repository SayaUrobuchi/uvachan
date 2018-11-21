#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, sq, flag, times;
	while(scanf("%d", &n) == 1)
	{
		flag = 0;
		if(!(n % 2))
		{
			for(times=0; !(n%2); n/=2, times++);
			if(times == 1)
			{
				printf("2");
			}
			else
			{
				printf("2^%d", times);
			}
			flag = 1;
		}
		sq = sqrt(n) + 1;
		for(i=3; i<sq; i+=2)
		{
			if(!(n % i))
			{
				if(flag)
				{
					printf(" * ");
				}
				flag = 1;
				for(times=0; !(n%i); n/=i, times++);
				if(times == 1)
				{
					printf("%d", i);
				}
				else
				{
					printf("%d^%d", i, times);
				}
				flag = 1;
			}
		}
		if(n > 1)
		{
			if(flag)
			{
				printf(" * ");
			}
			printf("%d", n);
		}
		printf("\n");
	}
	return 0;
}
